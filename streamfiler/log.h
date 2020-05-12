/*
 * This class represents a console writer logger and it implements the singleton pattern. 
 * 
 * File:   parameters.h
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#ifndef LOG_H
#define	LOG_H

#include <type_traits>
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>

namespace streamfiler
{
    class Log
    {
    private:
        std::ostream& outStream;
        bool lineBegin;
        bool verbose;

        using endl_type = std::ostream&(std::ostream&);

        static Log* instance;


        /**
         * konstruktor.
         * @param outStream: meg lehet adni, hogy hova írjon. Alapértelmezetten standard output
         */
        Log(std::ostream& outStream = std::cout)
                : outStream(outStream), lineBegin(true), verbose(false) 
        {
        }

    public:
        /**
         * visszaadja az egyetlen példányt. Ha nem volt, létrehozza.
         * @return 
         */
        static Log& getInstance()
        {
            if (instance == nullptr)
            {
                instance = new Log();
            }
            return *instance;
        }


        /**
         * A futás végeztével kitörli a memóriából.
         */
        static void releaseInstance()
        {
            if(instance != nullptr)
            {
                delete instance;
                instance = nullptr;
            }
        }

        /**
         * setter. Csak akkor ír az outputra, ha ez be lett állítva
         * @param verbose
         */
        void setVerbose(bool verbose)
        {
            this->verbose = verbose;
        }

        /**
         * insertion operator definíció. Különböző működése van, ha sorvége jelet ír ki,
         * mert ezzel jelzi, hogy a következő kiítás a sor elejére kerül és oda 
         * időbélyeget kell írni.
         * @param endl
         * @return 
         */
        Log& operator<<(endl_type endl)
        {
            if (verbose)
            {
                lineBegin = true;
                outStream << endl;
            }
            return *this;
        };

        /**
         * insertion operator definíció. Az összes többi esetre.
         * @param data
         * @return 
         */
        template<typename T>
        Log& operator<< (const T& data)
        {
            if (verbose)
            {
                if(lineBegin)
                {
                    auto now = std::chrono::system_clock::now();
                    auto now_time_t = std::chrono::system_clock::to_time_t(now);
                    auto tm  = std::localtime(&now_time_t);
                    outStream << "[" << tm->tm_hour << ":" << tm->tm_min << ":" << tm->tm_sec << "]: " << data;
                }
                else
                {
                    outStream << data;
                }
                lineBegin = false;
            }

            return *this;
        }
    };
}

#endif	/* LOG_H */

