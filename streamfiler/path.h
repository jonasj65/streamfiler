/* 
 * This class represents a tool to handle file system paths.
 * 
 * File:   Path.h
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM 
 */

#ifndef PATH_H
#define PATH_H

#include "stringtool.h"
#include <vector>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>

#ifdef UNITTEST
    namespace streamfiler_test
    {
        class PathTest;
    }
#endif

namespace streamfiler
{
    class Path
    {
#ifdef UNITTEST
    friend class streamfiler_test::PathTest;
#endif
    public:
        Path();
        Path(std::string& aPath);
        Path(const char* aPath);
        virtual ~Path();

        std::string getPath();
        std::string getSeparator();
        void setPath(std::string aPath);
        bool isGoodPath();
        bool isGoodPath(std::string* aPath);    
        std::vector<std::string> getPathList(std::string* aPath);
        std::string getPathFromList(std::vector<std::string>* pathItems);
        bool isValidDirectory();
        bool isFile();
        void append(std::string aSubPath);
        void append(std::string* aSubPath);
        void append(std::vector<std::string>* pathList);
        int isValidPath();
        std::string getDirectory();
    private:
        std::string path;
        const std::string separator = "/";

        void init(const char* aPath);
        bool isContainsForbiddenChars(std::string& aPath);

    };
}

#endif /* PATH_H */

