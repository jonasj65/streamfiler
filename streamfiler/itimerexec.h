/* 
 * This class represents an interface for the TimedExecutor timer class. 
 * The timer can run its method timerExecute().
 * 
 * File:   itimerexec.h
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#ifndef ITIMEREXEC_H
#define ITIMEREXEC_H

namespace streamfiler
{
    class ITimerExec 
    {
    public:
        virtual int timerExecute()=0;
    private:
        
    };
}
#endif /* ITIMEREXEC_H */

