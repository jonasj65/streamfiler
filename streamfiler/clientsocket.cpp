/* 
 * File:   clientsocket.cpp
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#include "clientsocket.h"
#include "filenamegenerator.h"
#include "iparameters.h"

using namespace streamfiler;

/*
 * Konstruktor
 */
ClientSocket::ClientSocket() 
{
    clientSocketDescriptor = 0;
}

/**
 * Destruktor
 */
ClientSocket::~ClientSocket() 
{
    closeSocket();
}

/**
 * getter. File descriptor.
 * @return 
 */
int ClientSocket::getSocketDescriptor()
{
    return clientSocketDescriptor;
}

/**
 * Beindítja a kliens socketet. Indul a stopper, nevet kap a file.
 * @param socketDescriptor
 * @param pars
 */
void ClientSocket::setSocket(int socketDescriptor, IParameters* pars)
{
    clientSocketDescriptor = socketDescriptor;
    // milisec-et vár
    timer.setTimeout(pars->getTimeout() * 1000);
    timer.startTimer(this);
    Path p = pars->getDirectory();
    FileNameGenerator genFileName(p);
    genFileName.setTimeByNow();
    std::string fileName = genFileName.getFullPath();
    
    Log::getInstance() << "New file: " << fileName << std::endl;
    
    fileWriter.setFileName(fileName);
}

/**
 * getter. A távoli gép adatai.
 * @return 
 */
struct sockaddr_in* ClientSocket::getAddress()
{
    return &address;
}

/**
 * setter. A távoli gép adatai.
 * @param address
 */
void ClientSocket::setAddress(struct sockaddr_in* address)
{
    this->address.sin_addr = address->sin_addr;
    this->address.sin_family = address->sin_family;
    this->address.sin_port = address->sin_port;
    
    Log::getInstance() 
        << "New connection, socket descriptor is: " << getSocketDescriptor()
        << ", ip is : " << inet_ntoa(getAddress()->sin_addr)
        << ", port:" << ntohs(getAddress()->sin_port)
        << std::endl;
}

/**
 * Kiolvassa a küldött adatokat
 * @param limit: másodpercenként engedett adatmennyiség. -1, ha nincs korlátozás
 */
void ClientSocket::readSocket(int limit)
{
    int socketReaderBufferSize;
    
    // másodpercenként ennyi Byte-ot fogad
    if (limit == -1)
    {
        socketReaderBufferSize = 65536;
    }
    else
    {
        socketReaderBufferSize = limit;
    }
     
    
    unsigned char socketReaderBuffer[socketReaderBufferSize];
    std::memset(socketReaderBuffer, 0, socketReaderBufferSize);

    int readLength = 0;
    
    // Ameddig a socketReaderBuffer tele lesz, van olvasni való.
    do
    {
        std::memset(socketReaderBuffer, 0, socketReaderBufferSize);
        readLength = read(clientSocketDescriptor, socketReaderBuffer, socketReaderBufferSize);
        if (readLength == 0) 
        {   
            // Nem olvasott be semmit, megszakadt a kapcsolat.
            int addressLength = sizeof(address);
            getpeername(clientSocketDescriptor, (struct sockaddr*)&address, (socklen_t*)&addressLength);
            
            Log::getInstance() << "Host disconnected, ip: " << inet_ntoa(address.sin_addr) << ", port: " << ntohs(address.sin_port) << std::endl;

            // Bezárjuk a socketet, ha már nincs mit olvasni
            closeSocket();
        } 
        else 
        {
            timer.reset();
            fileWriter.write(socketReaderBuffer, readLength);
            Log::getInstance() << "File write: " << fileWriter.getFileName() << ", bytes: " << readLength << std::endl;
            
            // echo; visszaírja a kliensre a kapott karaktereket
            //send(clientSocketDescriptor, socketReaderBuffer, readLength, 0);
        }
        
        // Ha -1, nincs lassítás
        if(limit != -1 && readLength == socketReaderBufferSize)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }while(readLength == socketReaderBufferSize);
}

/**
 * Bezárja a kapcsolatot
 */
void ClientSocket::closeSocket()
{
    if (clientSocketDescriptor >= 0)
    {
        int err = 1;
        socklen_t len = sizeof err;
        if (-1 == getsockopt(clientSocketDescriptor, SOL_SOCKET, SO_ERROR, (char *)&err, &len))
        {
           Log::getInstance() << "ClientSocket error: " << err << std::endl;
        }
        
        if (err)
        {
           errno = err; 
        }
        
        if (shutdown(clientSocketDescriptor, SHUT_RDWR) < 0)
        {
            if (errno != ENOTCONN && errno != EINVAL)
            {
                Log::getInstance() << "ClientSocket shutdown: " << std::strerror(errno) << std::endl;
            }
        }
        int closeError = close(clientSocketDescriptor);
        if (closeError < 0) 
        {
           Log::getInstance() << "ClientSocket close error: " << closeError << std::endl;
        }
        clientSocketDescriptor = 0;
        std::string f("");
        fileWriter.setFileName(f);

    }
    Log::getInstance() << "ClientSocket::closeSocket() : " << clientSocketDescriptor << std::endl;
}

/**
 * override az ITimerExec interface-ből, ezt a metódust hívja a timer, ha lefutott. 
 * @return 
 */
int ClientSocket::timerExecute()
{
    closeSocket();
    return 0;
}

