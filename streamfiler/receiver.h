/* 
 * This class represents the worker. 
 * It is responsible for creating connection between the local server and remote clients.
 * 
 * File:   receiver.h
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#ifndef RECEIVER_H
#define RECEIVER_H

#define socketReaderBufferSize 1024;

#include "itimerexec.h"
#include "iparameters.h"

namespace streamfiler
{
    class Receiver
    {
    public:
        Receiver();
        Receiver(const Receiver& orig);
        virtual ~Receiver();

        int run(IParameters* params);

    private:

    };
}

#endif /* RECEIVER_H */

