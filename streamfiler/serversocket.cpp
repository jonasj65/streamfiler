/* 
 * File:   ServerCocket.cpp
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#include "serversocket.h"
#include "log.h"


using namespace streamfiler;

/**
 * Konstruktor. Felépíti a socetet.
 * Runtime error-t dob, ha valami nem sikerült.
 * @param portNumber a port, amin figyelni fog
 */
ServerSocket::ServerSocket(int portNumber) 
{
    this->portNumber = portNumber;
    
    if( (serverSocketDescriptor = socket(AF_INET , SOCK_STREAM , 0)) == 0)   
    {
        Log::getInstance() << "Server socket initialisation error." <<  std::endl;
        throw std::runtime_error("Socket init error.");
    }
    
    //beállítjuk több kapcsolat kezelésére
    int opt = 1;
    if( setsockopt(serverSocketDescriptor, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0 )
    {
        Log::getInstance() << "Server socket option error." <<  std::endl;
        throw std::runtime_error("Socket set option error.");   
    }   
     
    //cím összeállítása
    struct sockaddr_in address;
    address.sin_family = AF_INET;  // IPv4
    address.sin_addr.s_addr = INADDR_ANY; // automatikus IP-mel 
    address.sin_port = htons(portNumber); // short, network byte order 
    
         
    // összekapcsoljuk a listener sockettel 
    if (bind(serverSocketDescriptor, (struct sockaddr *)&address, sizeof(address))<0)   
    {   
        Log::getInstance() << "Server socket binding error." <<  std::endl;
        throw std::runtime_error("Socket binding error.");
    }
}

/**
 * getter. A socket file descriptora
 * @return 
 */
int ServerSocket::getSocketDescriptor()
{
    return serverSocketDescriptor;
}

/**
 * Elindítja a porton való figyelést.
 * Runtime error-t dob, ha nem sikerült.
 */
void ServerSocket::listenSocket()
{
    if(listen(serverSocketDescriptor, SOMAXCONN) < 0)
    {
        Log::getInstance() << "Server socket listener start error." <<  std::endl;
        throw std::runtime_error("Socket listen error.");
    }
}

/**
 * destruktor
 */
ServerSocket::~ServerSocket() 
{
    if (serverSocketDescriptor != 0)
    {
        Log::getInstance() << "Server socket has been closed. Socket descriptor: " <<  serverSocketDescriptor << std::endl;
        close(serverSocketDescriptor);
        serverSocketDescriptor = 0;
    }
}
