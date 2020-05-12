/*
 * This class represents the command line arguments and it implements the singleton pattern.
 * Unspecified optional arguments are filled with default values.
 * 
 * File:   parameters.h
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <string>
#include <unistd.h>
#include "iparameters.h"
#include "log.h"

#define DEFAULT_CONNECTIONS 1
#define DEFAULT_LIMIT -1
#define DEFAULT_TIMEOUT -1


#ifdef UNITTEST
    namespace streamfiler_test
    {
        class ParametersTest;
    }
#endif

namespace streamfiler
{
    class Parameters : public IParameters 
    {
#ifdef UNITTEST
    friend class streamfiler_test::ParametersTest;
#endif
    public:
        static Parameters* getInstance();
        static void releaseInstance();

        bool parseParams(int argc, char* argv[]);
        void setDefaultDirectory();

        virtual int getConnections();
        virtual Path& getDirectory();
        virtual std::string getDirectoryStr();
        virtual int getLimit();
        virtual int getTimeout();
        virtual bool getHelp();
        virtual int getPortNumber();
        virtual bool getVerbose();
        
    private:
        int connections;
        Path directory;
        int limit;
        int timeout;
        int help;
        int portNumber;
        int verbose;
        
        static Parameters* instance;

        void setConnections(int connections);
        void setDirectory(std::string directory);
        void setLimit(int limit);
        void setTimeout(int timeout);
        void setHelp(bool help);
        void setPortNumber(int portNumber);
        void setVerbose(bool verbose);

        Parameters();
        virtual ~Parameters();

    };
}

#endif /* PARAMETERS_H */

