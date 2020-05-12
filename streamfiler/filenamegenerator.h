/* 
 * This class represents a file name generator from timestamp.
 * 
 * File:   filenamegenerator.h
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#ifndef FILENAMEGENERATOR_H
#define FILENAMEGENERATOR_H

#include <cmath>
#include <string>
#include "path.h"

#ifdef UNITTEST
    namespace streamfiler_test
    {
        class FileNameGeneratorTest;
    }
#endif

namespace streamfiler
{
    class FileNameGenerator
    {
#ifdef UNITTEST
    friend class streamfiler_test::FileNameGeneratorTest;
#endif
    public:
        FileNameGenerator(Path& directory);
        FileNameGenerator(const FileNameGenerator& orig);
        virtual ~FileNameGenerator();
        void setTimeByNow();
        bool isValid();
        void invalidate();

        std::string getFileName();
        std::string getFullPath();
    private:
        struct timespec timestamp;  // tárol nanosec-et is
        bool valid;
        Path directory;
        std::string fileName;
    };
}
#endif /* FILENAMEGENERATOR_H */

