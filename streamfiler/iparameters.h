/* 
 * This class represents an interface for passing parameters from command line arguments. 
 * 
 * File:   IParameters.h
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM 
 */

#ifndef IPARAMETERS_H
#define IPARAMETERS_H

#include <string>
#include "path.h"
namespace streamfiler
{
    class IParameters {
    public:
        virtual Path& getDirectory()=0;
        virtual int getConnections()=0;
        virtual int getLimit()=0;
        virtual int getTimeout()=0;
        virtual bool getHelp()=0;
        virtual int getPortNumber()=0;
        virtual bool getVerbose()=0;

    };
}
#endif /* IPARAMETERS_H */

