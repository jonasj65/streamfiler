/* 
 * This class represents a local participant of the connection - Listener.
 * 
 * File:   serversocket.h
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <stdexcept>

namespace streamfiler
{
    class ServerSocket 
    {
    public:
        ServerSocket(int portNumber);
        ServerSocket(const ServerSocket& orig);

        int getSocketDescriptor();
        void listenSocket();

        virtual ~ServerSocket();
    private:
        int serverSocketDescriptor;
        int portNumber;
    };
}

#endif /* SERVERSOCKET_H */

