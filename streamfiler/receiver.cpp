/* 
 * File:   receiver.cpp
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#include "receiver.h"
#include "filenamegenerator.h"

#include <stdio.h>
#include <string.h>
#include <sys/socket.h> 
#include <netinet/in.h>
#include <arpa/inet.h>

#include "timedexecutor.h"
#include "serversocket.h"
#include "clientsocket.h"
#include "log.h"

using namespace streamfiler;

/**
 * konstruktor
 */
Receiver::Receiver() 
{
}

/**
 * destruktor
 */
Receiver::~Receiver() 
{
}

/**
 * A program fő futási ciklusa
 * @param params
 * @return 
 */
int Receiver::run(IParameters* params)
{
    int maxClients = params->getConnections();
    int portNumber = params->getPortNumber();
    int limit = params->getLimit();
    ClientSocket clientSocket[maxClients]; // egyszerre kezelt kapcsolatok 

    ServerSocket* serverSocket = new ServerSocket(portNumber); 
    
    serverSocket->listenSocket();

    // Bejövő kapcsolatok kezelése
    struct sockaddr_in address;
    int addressLength = sizeof(address);

    // Az élő kapcsolatok listája 
    fd_set readDescriptors;
    while(true)
    {
        //kitakarítjuk a socket set-et
        FD_ZERO(&readDescriptors);   
     
        //hozzáadjuk a serverSocket-et
        FD_SET(serverSocket->getSocketDescriptor(), &readDescriptors);   
        int maxSD = serverSocket->getSocketDescriptor();

        for (int i = 0 ; i < maxClients ; i++)   
        {
            //hozzáadjuk az élő clientSocket-eket a socket set-hez
            if(clientSocket[i].getSocketDescriptor() > 0)
            {
                FD_SET(clientSocket[i].getSocketDescriptor(), &readDescriptors);
            }

            //a legmagasaabb descriptor kell a select-hez
            if(clientSocket[i].getSocketDescriptor() > maxSD)   
                maxSD = clientSocket[i].getSocketDescriptor();   
        }
     
        //Aktivitásra várunk a socket-en
        int activity = select( maxSD + 1 , &readDescriptors , NULL , NULL , NULL);   
       
        if ((activity < 0) && (errno != EINTR))   
        {   
            Log::getInstance() << "Socket select error: " << std::strerror(errno) << std::endl;
        }

        // Bejött egy kapcsolat  
        if (FD_ISSET(serverSocket->getSocketDescriptor(), &readDescriptors))
        {   
            int newSocket;
            // address újrahasznosítás. Milyen címről hívták és mi lett a port szám.
            // Az eredeti port maradt a listener.
            if ((newSocket = accept(serverSocket->getSocketDescriptor(), (struct sockaddr *)&address, (socklen_t*)&addressLength))<0)
            {
                Log::getInstance() << "Error! Client connection failed!" << std::endl;
                return -1;
            }

            // felvesszük a listába az új kapcsolatot
            for (int i = 0; i < maxClients; i++)   
            {
                // A következő üres helyre tesszük a listában  
                if( clientSocket[i].getSocketDescriptor() == 0 )
                {
                    clientSocket[i].setSocket(newSocket, params);
                    clientSocket[i].setAddress(&address);

                    Log::getInstance() << "Adding to list of sockets: " <<  i << std::endl;
                    break;
                }
            }
        }

        // végigolvassuk az össes aktív kapcsolatot 
        for (int i = 0; i < maxClients; i++)   
        {
            if (FD_ISSET(clientSocket[i].getSocketDescriptor(), &readDescriptors))   
            {
                clientSocket[i].readSocket(limit);
            }
        }
    }
    delete serverSocket;

    return 0;
}
