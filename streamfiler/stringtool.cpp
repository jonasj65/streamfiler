/* 
 * File:   stringtool.cpp
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#include "stringtool.h"

using namespace streamfiler;

/**
 * Integert alakít át stringgé
 * @param i
 * @return 
 */
std::string StringTool::intToStr(int i)
{
    char buff[100];
    snprintf(buff, sizeof(buff), "%d", i);
    return std::string(buff);
}

/**
 * Stringet alakít át integerré. Csak akkor csinálja meg, ha a string csak számjegy karaktereket tartalmaz.
 * @param str
 * @param i
 * @return false, ha nem sikeres - a string nem csak számjegy karaktereket tartalmaz
 */
bool StringTool::strToInt(std::string str, int& i)
{
    bool retVal = false;
    if (StringTool::isNumber(str))
    {
        i = std::stoi(str);
        retVal = true;
    }
    return retVal;
}

/**
 * Megvizsgálja, hogy csak számjegyeket tartalmaz-e
 * @param s
 * @return 
 */
bool StringTool::isNumber(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
    {
        ++it;
    }
    return !s.empty() && it == s.end();
}

/**
 * A separator mentén szétvágja egy vektorba
 * @param str
 * @param separator
 * @return 
 */
std::vector<std::string> StringTool::split(const char* str, const char* separator)
{
    std::vector<std::string> result;
    char* token = strtok((char*)str, separator);

    while (token != NULL) 
    {
        result.push_back(std::string(token));
        token = strtok(NULL, separator);
    }
    return result;
}

/**
 * A separator mentén szétvágja egy vektorba
 * @param str
 * @param separator
 * @return 
 */
std::vector<std::string> StringTool::split(std::string& str, std::string& separator) 
{
    return split((char*)str.c_str(), (char*)separator.c_str());
}