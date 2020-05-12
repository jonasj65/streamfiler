/*
 * File:   main.cpp
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#include <iostream>
#include "parameters.h"
#include "receiver.h"
#include "log.h"
#include <unistd.h>
#include <ncurses.h> 
#include <cstdio> 
#include <thread>
#include <cstring>

using namespace streamfiler;

/**
 * Helpet ír a képernyőre. Vagy a -h --help paraméterekkel lehet kérni,
 * vagy ha nem sikerült elintulni pl. hibás paraméterek miatt.
 */
void printHelp()
{
    std::cout 
       << "streamfiler [-options] portnumber" << std::endl << std::endl
       << "portnumber                   Kötelező megadni, ezen a porton várja a fájlokat." << std::endl << std::endl
       << "-c --connections <number>    A maximálisan fogadható párhuzamos connection-ök száma. (Default: 10)" << std::endl
       << "-f --folder <path>           A mappa, ahova az érkztetett állományokat letárolja a program." << std::endl
       << "                             Ha nem létezik induláskor, akkor a program létrehozza azt." << std::endl
       << "-h --help                    Ez a help." << std::endl
       << "-l --limit <number>          Ekkora limit adatmennyiséget enged szálanként és " << std::endl
       << "                             másodpercenként kilobyte-ban a portjára folyatni a program. (Default: 1000)" << std::endl
       << "-t --timeout  <number>       Azt az időt határozza meg másodpercben, ami után a program" << std::endl
       << "                             bontja az idle connection-öket. Timeout -1 esetén nem bontja. (Default: 10)" << std::endl
       << "-v --verbose                 Képernyő log." << std::endl

            << std::endl
       << "Kilépés: [ESC]" << std::endl;
}


/**
 * belépési pont
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char* argv[]) 
{
    bool goodParameters = Parameters::getInstance()->parseParams(argc, argv);
    
    if(!goodParameters)
    {
        printHelp();
        exit(EXIT_FAILURE);
    }
    else
    {
        Log::getInstance().setVerbose(Parameters::getInstance()->getVerbose());
        
        Log::getInstance() << "connections: " << Parameters::getInstance()->getConnections() << std::endl;
        Log::getInstance() << "directory: " << Parameters::getInstance()->getDirectory().getPath() << std::endl;
        Log::getInstance() << "limit: " << Parameters::getInstance()->getLimit() << std::endl;
        Log::getInstance() << "timeout: " << Parameters::getInstance()->getTimeout() << std::endl;
        Log::getInstance() << "verbose: " << Parameters::getInstance()->getVerbose() << std::endl;
        Log::getInstance() << "port: " << Parameters::getInstance()->getPortNumber() << std::endl;
        
        // Billentyűt figyelő thread, hogy az [ESC] lenyomására kilépjen. 
        // a getchar() miatt kellett egy kicsit trükközni, mert a terminal 
        // csak ENTER után adja vissza a begépelt karaktert.
        std::thread([]() {
            std::cout << "Press [ESC] to quit." << std::endl;
            system("stty -echo"); // Terminal settings: Nem írja ki a leütött karaktert.
            system("stty cbreak"); // Terminal settings: Törli a spec karaktereket.
            char ch;
            while ((ch = getchar()) != 27) 
            {
                std::cout << "press [ESC] to quit." << std::endl;
            }
            system ("stty echo"); // Terminal settings: visszaállítjuk az eredetit
            system("stty -cbreak"); // 
            
            
            std::cout << "Bye!" << std::endl;

            std::exit(0);

        }).detach(); 

      
        Receiver fr;
        Parameters* pars = Parameters::getInstance();
        int err = fr.run(pars);
        
        std::cout << "FileReceiver.run: " << err << std::endl;
    }

    // Megszünteti az objektumokat.
    Parameters::releaseInstance();
    Log::releaseInstance();
    
    return EXIT_SUCCESS;
}

