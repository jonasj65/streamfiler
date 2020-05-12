/* 
 * File:   filenamegenerator.cpp
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#include "filenamegenerator.h"

using namespace streamfiler;

/**
 * konstruktor.
 * @param directory: Ez lesz a generált név elérési útja. Ha nem létezik, létrehozza
 */
FileNameGenerator::FileNameGenerator(Path& directory) 
{
    this->directory.setPath(directory.getPath());
    if (!directory.isValidDirectory())
    {
        mode_t mode = 0755;
        int ret = mkdir(directory.getPath().c_str(), mode);
    }
    
    this->valid = false;
}


FileNameGenerator::FileNameGenerator(const FileNameGenerator& orig) 
{
}

/**
 * destruktor
 */
FileNameGenerator::~FileNameGenerator() 
{
}

/**
 * Lementi az időt az adott pillanatban ha invalid az objektum, és valid-ra állítja.
 * A valid jelzi, hogy tartalmaz időbélyeget.
 */
void FileNameGenerator::setTimeByNow()
{
    if(!isValid())
    {
        timespec_get(&timestamp, TIME_UTC); // pontos idő UTC-ben
        valid = true;
    }
}

/**
 * Be lett-e állítva az idő
 * @return true ha igen
 */
bool FileNameGenerator::isValid()
{
    return valid;
}

/**
 * Invalidálja az objektumot. Ha valid, nem lehet új időt beállítani.
 */
void FileNameGenerator::invalidate()
{
    valid = false;
}

/**
 * Stringet generál a mentett időből, ha az objektum valid.
 * @return A generált string. ha valid, újat generál.
 */
std::string FileNameGenerator::getFileName()
{
    if(isValid())
    {
        struct tm * ptm;
        ptm = localtime(&timestamp.tv_sec); // konvertálás év, hó, nap, óra, perc, mp-re

        int millisec = std::lrint(timestamp.tv_nsec/1000000.0); // a ts nanosec-et tárol

        char buff[100];
        int length = std::sprintf(buff, "%d%02d%02d%02d%02d%02d%03d", 1900+ptm->tm_year, ptm->tm_mon+1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, millisec);

        fileName = std::string(buff, length);
    }
    return fileName;
}

/**
 * A teljes elérési útvonalat adja vissza a generált névből és a konstruktorban kapott path-ból.
 * @return 
 */
std::string FileNameGenerator::getFullPath()
{
    std::string fn = getFileName();
    std::string pn = directory.getPath();
    Path p(pn);
    p.append(fn);

    return p.getPath();
}
