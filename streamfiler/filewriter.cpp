/* 
 * File:   filewriter.cpp
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#include "filewriter.h"
#include <fstream>

using namespace streamfiler;

/**
 * konstruktorok
 */
FileWriter::FileWriter() 
{
}


FileWriter::FileWriter(std::string& fileName) 
{
    setFileName(fileName);
}

/**
 * destruktor
 */
FileWriter::~FileWriter() 
{
}

/**
 * retter 
 * @return fileName
 */
std::string FileWriter::getFileName()
{
    return this->fileName;
}

/**
 * setter
 * @param fileName
 */
void FileWriter::setFileName(std::string& fileName)
{
    this->fileName = fileName;
}

/**
 * File nyitás/zárással megnézi, hogy létezik-e a file.
 * @param path: Viszgált file
 * @return true, sikerült megnyitni
 */
bool FileWriter::isExists(const char* path)
{
    FILE* f = fopen(path,"rb");
    if (f > 0)
    {
        fclose(f);
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Kiírja a file-ba a kapott adatokat
 * @param buffer: Kiírandó adatok
 * @param size: az adatok mennyisége
 */
void FileWriter::write(const unsigned char* buffer, int size)
{
    // Ha a file még nem létezik, ez az első adag adat
    if (!isExists(fileName.c_str()))
    {
        Log::getInstance() << "New File Name: " << fileName << std::endl;
    
        // PNG file megállípítása
        if (buffer[0] == 137 && buffer[1] == 80 && buffer[2] == 78 && buffer[3] == 71) // .PNG karakterekkel kezdődik
        {
            Log::getInstance() << "A PNG file received: " << fileName << std::endl;
        }
        // BMP file megállípítása
        else if (buffer[0] == 66 && buffer[1] == 77) // BM karakterekkel kezdődik
        {
            Log::getInstance() << "A BMP file received: " << fileName << std::endl;
        }
    }
    
    FILE *fptr = fopen(fileName.c_str(),"ab");
    if(fptr == NULL)
    {
        Log::getInstance() << "File open error: " << fileName <<  " Error: " << std::strerror(errno) << std::endl;
    }
    else
    {
        if (fwrite(buffer, 1, size, fptr) != size)
        {
            Log::getInstance() << "File write error: " << fileName <<  " Error: " << std::strerror(errno) << std::endl;
        }

    }
    fclose(fptr);
}
