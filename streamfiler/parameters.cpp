/* 
 * File:   parameters.cpp
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#include "parameters.h"

#include <getopt.h>
#include "stringtool.h"

using namespace streamfiler;

/** A kezdő értéknek NULL-nak kell lenni.*/

Parameters* Parameters::instance = nullptr; 

/**
 * Private konstruktor. Kezdő értékeket állít be.
 */
Parameters::Parameters() 
{
    connections = -10;
    directory.setPath("");
    limit = -10;
    timeout = -10;
    help = -10;
    portNumber = -10;
    verbose = -10;
}

/**
 * destruktor
 */
Parameters::~Parameters() 
{
}


/**
 * Static függvény első hívásakor hozza létre az objektumot.
 */
Parameters* Parameters::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Parameters();
    }
    return instance;
}

/**
 * A program kilépés előtt meg kell hívni, különben az instance nem szabadul fel.
 */
void Parameters::releaseInstance()
{
    if(instance != nullptr)
    {
        delete instance;
        instance = nullptr;
    }
}

/**
 * A parancssori argumentumokat dolgozza fel.
 * A program meghatározott opciókat tud kezelni. 
 * Ezek megadása nem kötelező, de ha ismeretlen opciót 
 * vagy paramétert adunk meg, a program leáll.
 * 
 * @param argc: az argumentumok száma
 * @param argv: az argumentumok tömbje
 */
bool Parameters::parseParams(int argc, char* argv[])
{
    // Az értelmezhető opciók listája. A shortOpts a kötőjel / egy betű,
    // a longOpts a két kötőjel / kulcsszó jelölés. 
    // Ha : áll a betű után, akkor argumentumot vár.
    
    bool retPar = true;
    
    const char* const shortOpts = "c:f:hl:t:v";
    const option longOpts[] = {
        {"connections", required_argument, nullptr, 'c'},
        {"folder", required_argument, nullptr, 'f'},
        {"help", no_argument, nullptr, 'h'},
        {"limit", required_argument, nullptr, 'l'},
        {"timeout", required_argument, nullptr, 't'},
        {"verbose", no_argument, nullptr, 'v'},
        {nullptr, no_argument, nullptr, 0}
    };
    
    int opt = 0;
    
    while (retPar && (opt = getopt_long(argc, argv, shortOpts, longOpts, nullptr)) != -1)
    {
        switch (opt)
        {
        case 'c':
            {
                int c;
                if(StringTool::strToInt(optarg, c))
                {
                    setConnections(c);
                }
                else
                {
                    retPar = false;
                }
            }
            break;

        case 'f':
            {
                std::string f(optarg);
                setDirectory(f);
            }
            break;

        case 'l':
            {
                int l;
                if(StringTool::strToInt(optarg, l))
                {
                    setLimit(l);
                }
                else
                {
                    retPar = false;
                }
            }
            break;

        case 't':
            {
                int t;
                if(StringTool::strToInt(optarg, t))
                {
                    setTimeout(t);
                }
                else
                {
                    retPar = false;
                }
            }
            break;

        case 'h': // ha helpet kérünk ne csináljon semmit
            {
                setHelp(true);
                retPar = false;
            }
        case 'v':
            {
                setVerbose(true);
            }
            break;
        case '?': // az értelmezhetetlen opciók
            {
                retPar = false;
            }
            break;
        
        default:
            {
                retPar = false;
            }
            break;
        }
    }
    
    // Ha csak 1 argumentum maradt a vizsálatból, akkor az a port szám.
    if (retPar && ((optind + 1) == argc))
    {
        int p;
        if(StringTool::strToInt(argv[optind], p))
        {
            setPortNumber(p);
        }
        else
        {
            retPar = false;
        }
    }
    else
    {
        for(; optind < argc; optind++)
        { 
            Log::getInstance() << "unrecognized parameter: " << argv[optind] << std::endl;
        }
        retPar = false;
    }
    
    // Ha nem voltak a paraméterek között:
    if (connections == -10)
    {
        connections = DEFAULT_CONNECTIONS;
    }
    
    // Írja a futtatható mellé, ha ki tudja olvasni, ha nem, akkor az aktuális folder
    if (directory.getPath().empty())
    {
        setDefaultDirectory();
    }
    
    if (limit == -10)
    {
        limit = DEFAULT_LIMIT;
    }

    if (timeout == -10)
    {
        timeout = DEFAULT_TIMEOUT;
    }
    
    if (help == -10)
    {
        setHelp(false);
    }

    if (verbose == -10)
    {
        setVerbose(false);
    }

    return retPar;
}

/**
 * Ha a parancssori paramterekben nem lett megadva directory az adatok lementéséhez,
 * akkor beírja a futó program helyt, vagy ha azt nem tudja kiolvasni, az aktuális könyvtárat.
 */
void Parameters::setDefaultDirectory()
{
    // A futó bináris helye. 
    char result[4096];
    
    // proc: futó processek, self: link arra, amiben vagyok, exe: link a futó binárisra
    ssize_t count = readlink( "/proc/self/exe", result, 4096);
    std::string p(result, (count > 0) ? count : 0);
    directory.setPath(p);
    directory.setPath(directory.getDirectory());

    // Ha nem sikerült kiolvasni és még mindig üres.
    if (directory.getPath().empty())
    {
       // aktuális directory, ahonnan indítva lett a program.
        char buff[FILENAME_MAX];
        getcwd(buff, FILENAME_MAX);
        directory.setPath(std::string(buff));
    }
}

/** getterek / setterek. A paraméterek csak egyszer állíthatók be. */

int Parameters::getConnections()
{
    return connections;
}


void Parameters::setConnections(int connections)
{
    if (this->connections == -10)
    {
        this->connections = connections;
    }
}


Path& Parameters::getDirectory()
{
    return directory;
}


std::string Parameters::getDirectoryStr()
{
    return directory.getPath();
}


void Parameters::setDirectory(std::string directory)
{
    if (this->directory.getPath().empty())
    {
        this->directory.setPath(directory);
    }
}


int Parameters::getLimit()
{
    return limit;
}


void Parameters::setLimit(int limit)
{
    if (this->limit == -10)
    {
        this->limit = limit;
    }
}


int Parameters::getTimeout()
{
    return timeout;
}


void Parameters::setTimeout(int timeout)
{
    if (this->timeout == -10)
    {
        this->timeout = timeout;
    }
}


bool Parameters::getHelp()
{
    return (help == 1);
}


void Parameters::setHelp(bool help)
{
    if (this->help == -10)
    {
        this->help = (help) ? 1 : 0;
    }
}


int Parameters::getPortNumber()
{
    return portNumber;
}


void Parameters::setPortNumber(int portNumber)
{
    if (this->portNumber == -10)
    {
        this->portNumber = portNumber;
    }
}


bool Parameters::getVerbose()
{
    return (verbose == 1);
}


void Parameters::setVerbose(bool verbose)
{
    if (this->verbose == -10)
    {
        this->verbose = (verbose) ? 1 : 0;
    }
}
