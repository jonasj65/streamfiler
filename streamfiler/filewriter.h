/* 
 * This class is responsible for writing the received data to disk;
 * 
 * File:   filewriter.h
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <string>
#include <cstring>
#include "log.h"
namespace streamfiler
{
    class FileWriter
    {
    public:
        FileWriter();
        FileWriter(std::string& fileName);
        virtual ~FileWriter();
        std::string getFileName();
        void setFileName(std::string& fileName);
        bool isExists(const char* path);
        void write(const unsigned char* buffer, int size);

    private:
        std::string fileName;

    };
}
#endif /* FILEWRITER_H */

