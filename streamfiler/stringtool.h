/* 
 * This class represents a tool to expand string functionalities.
 * 
 * File:   stringtool.h
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#ifndef STRINGTOOL_H
#define STRINGTOOL_H

#include <string>
#include <string.h>
#include <stdexcept>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <fstream>
#include <vector>

namespace streamfiler
{
    class StringTool 
    {
    public:
        static std::string intToStr(int i);
        static bool strToInt(std::string str, int& i);
        static bool isNumber(const std::string& s);
        static std::vector<std::string> split(const char* str, const char* separator);
        static std::vector<std::string> split(std::string& str, std::string& separator);
    private:

    };
}
#endif /* STRINGTOOL_H */

