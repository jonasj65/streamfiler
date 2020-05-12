/* 
 * File:   timedexecutor.cpp
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#include "timedexecutor.h"
#include "receiver.h"
#include "log.h"

using namespace streamfiler;

/**
 * Konstruktor
 */
TimedExecutor::TimedExecutor()
{
    this->timeout = 0;
    this->running = false;
    this->exec = nullptr;
}


/**
 * destruktor
 */
TimedExecutor::~TimedExecutor() 
{
}

/**
 * beállítja a várakozási időt millisec-ben
 * @param timeoutMillisec
 */
void TimedExecutor::setTimeout(int timeoutMillisec) 
{
    this->timeout = timeoutMillisec;
    reset();
}

/**
 * újraindítja az időzítőt
 */
void TimedExecutor::reset() 
{
    timeoutCounter = timeout/100;
    startTimer(nullptr);
    Log::getInstance() << "TimedExecutor: reset" << std::endl;
}

/**
 * megszakítja az időzítő futását
 */
void TimedExecutor::cancel() 
{
    timeoutCounter = -1;
    Log::getInstance() << "TimedExecutor: cancel" << std::endl;
}

/**
 * Indítja az időzítőt. Amikor az időzítő lejár, 
 * az "exec" objektum timerExecute() metódusát lefuttatja.
 * Ha az exec NULL, nem indítja el vagy ha az időzítő már fut, indítja el mégegyszer.
 * @param exec
 */
void TimedExecutor::startTimer(ITimerExec* exec)
{
    if (timeout > -1)
    {
        Log::getInstance() << "The timer has started." << std::endl;
        if (exec != nullptr && this->exec == nullptr)
        {
            this->exec = exec;
        }
         // új thread, a []-ban a neki átadott paraméterekkel
        int* ptu = &timeoutCounter;
        if (!running && this->exec!= nullptr)
        {
            bool* prunning = &running;
            std::thread([ptu, prunning, this]() {
                *prunning = true;
                while(*ptu > 0)
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                    (*ptu)--;
                    //Log::getInstance() << "timeoutCounter: " <<  *ptu << std::endl;
                }
                if ((*ptu) == 0)
                {
                    Log::getInstance() << "TimedExecutor: expired" << std::endl;
                    this->exec->timerExecute();
                }
                if ((*ptu) == -1)
                {
                    Log::getInstance() << "TimedExecutor: cancelled" << std::endl;
                }
                *prunning = false;
            }).detach(); 
        }
    }
}