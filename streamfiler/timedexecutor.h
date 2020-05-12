/* 
 * This class represents a timer what can run an object's timerExecute() 
 * method implementing the ITimerExec interface.
 * 
 * File:   timedexecutor.h
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#ifndef TIMEDEXECUTOR_H
#define TIMEDEXECUTOR_H

#include <iostream>
#include <thread>
#include "itimerexec.h"

namespace streamfiler
{
    class TimedExecutor 
    {
    public:
        TimedExecutor();
        virtual ~TimedExecutor();

        void startTimer(ITimerExec* exec);
        void setTimeout(int timeoutMillisec);
        void reset();
        void cancel();

    private:
        int timeout;
        int timeoutCounter;
        bool running;
        ITimerExec* exec;
    };
}
#endif /* TIMEDEXECUTOR_H */

