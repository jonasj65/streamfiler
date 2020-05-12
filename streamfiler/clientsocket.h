/* 
 * This class represents a remote participant of the connection.
 * 
 * File:   clientsocket.h
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <thread>

#include "timedexecutor.h"
#include "iparameters.h"
#include "filewriter.h"
#include "log.h"

namespace streamfiler
{
    class ClientSocket : public ITimerExec
    {
    public:
        ClientSocket();
        virtual ~ClientSocket();

        int getSocketDescriptor();
        void setSocket(int socketDescriptor, IParameters* pars);

        struct sockaddr_in* getAddress();
        void setAddress(struct sockaddr_in* address);

        void readSocket(int limit);
        void closeSocket();

        int timerExecute();
        

    private:
        TimedExecutor timer;
        FileWriter fileWriter;
        int clientSocketDescriptor;
        struct sockaddr_in address;

    };
}

#endif /* CLIENTSOCKET_H */

