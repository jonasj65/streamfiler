/* 
 * File:   Path.cpp
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM 
 */

#include "path.h"

using namespace streamfiler;

/**
 * konstruktorok
 */
Path::Path() 
{
    init(std::string("").c_str());
}


Path::Path(std::string& aPath)
{
    init(aPath.c_str());
}


Path::Path(const char* aPath)
{
    init(aPath);
}

/**
 * destruktor
 */
Path::~Path() 
{
}

/**
 * Kezdő értéket állít be
 * @param aPath
 */
void Path::init(const char* aPath)
{
    this->path = aPath;
}

/** getterek / setterek */
std::string Path::getPath()
{
    return this->path;
}

void Path::setPath(std::string aPath)
{
    this->path = aPath;
}


std::string Path::getSeparator()
{
    return separator;
}

/**
 * megvizsgálja, hogy az eltárolt string használható-e filesystem path-nak
 * @return true ha igen
 */
bool Path::isGoodPath()
{
    return isGoodPath(nullptr);
}

/**
 * megvizsgálja, hogy a megadott string használható-e filesystem path-nak
 * @param aPath
 * @return true ha igen
 */
bool Path::isGoodPath(std::string* aPath)
{
    std::string a;
    std::vector<std::string> pathList = getPathList(aPath);
    for (std::vector<std::string>::iterator it = pathList.begin(); it != pathList.end(); ++it)
    {
        a = (*it);
        if (isContainsForbiddenChars(a))
        {
            return false;
        }
    }
    return true;
}

/**
 * a path separator mentén szétszedi egy vektorba
 * 
 * @param aPath
 * @return 
 */
std::vector<std::string> Path::getPathList(std::string* aPath)
{
    std::string p;
    if (aPath == nullptr || aPath->empty())
    {
        p = this->path;
    }
    else
    {
        p = *aPath;
    }
    return StringTool::split((char*)p.c_str(), (char*)separator.c_str());
}

/**
 * a megadott tömbből képez path stringet
 * @param pathItems
 * @return 
 */
std::string Path::getPathFromList(std::vector<std::string>* pathItems)
{
    std::string tmp;

    std::string last = pathItems->back();

    for (std::vector<std::string>::iterator it = pathItems->begin(); it != pathItems->end(); ++it)
    {
        std::string str = (*it);

        tmp.append(str);
        if (str != last)
        {
            tmp += separator;
        }
    }
    return tmp;
}

/**
 * megvizsgálja, hogy tartalmaz-e tiltott karaktereket.
 * @param aPath
 * @return 
 */
bool Path::isContainsForbiddenChars(std::string& aPath)
{
    std::string forbiddenChars("<>:\"/\\|?*");

    for (unsigned int i=0; i<forbiddenChars.size();i++)
    {
        char c = forbiddenChars.at(i);
        if (aPath.find(c) != std::string::npos) 
        {
            return true;
        }
    }
    return false;
}

/**
 * megviszgálja, hogy létező filsystem objektum-e. 2: file; 1: directory; 0: nem létezik vagy nem elérhető.  
 * @return 
 */
int Path::isValidPath()
{
    struct stat info;

    if(stat(path.c_str(), &info ) != 0)
        return 0; // hiba, nem tudta elérni
    else if( info.st_mode & S_IFDIR ) 
        return 1; // directory
    else
        return 2; // egyéb
}

/**
 * A lemezen létező directory
 * @return 
 */
bool Path::isValidDirectory()
{
    return (isValidPath() == 1);
}


/**
 * A lemezen létező file
 * @return 
 */
bool Path::isFile()
{
    return (isValidPath() == 2);
}

/**
 * A path separator-ral elválasztva a végéhez illeszti
 * @param aSubPath
 */
void Path::append(std::string aSubPath)
{
    append(&aSubPath);
}


/**
 * A path separator-ral elválasztva a végéhez illeszti
 * @param aSubPath
 */
void Path::append(std::string* aSubPath)
{
    std::string tmpPath(path);
    int a = tmpPath.length();
    char b = tmpPath.at(tmpPath.length()-1);
    char c = separator.at(0);
    char d = tmpPath.at(0);
    
    if (tmpPath.at(tmpPath.length()-1) != separator.at(0) && aSubPath->at(0) != separator.at(0))
    {
        tmpPath += separator;
    }

    // Hozzáfűzzük az új részt
    tmpPath.append(*aSubPath);

    // ha ezek vannak benne, akkor megszüntetjük
    std::string upPath("..");
    std::string thPath(".");


    std::vector<std::string> pathList = getPathList(&tmpPath);
    if (tmpPath.at(0) == separator.at(0))
    {
        pathList.insert(pathList.begin(), separator);
    }
    
    for (std::vector<std::string>::iterator it = pathList.begin(); it != pathList.end(); ++it)
    {
        std::string a = (*it);

        if (((*it) == upPath) && (it != pathList.begin())) // ..-tal kezd, akkor mégis kell
        {
            ((*it)) = "";
            (*(it-1)) = "";
        }
        if ((*it) == thPath)
        {
            (*it) = "";
        }
    }
    tmpPath = getPathFromList(&pathList);
	
    std::string replace(separator);
    std::string search(replace);
    search.append(search);
    size_t pos = std::string::npos;
    
    do {
    	pos = tmpPath.find(search.c_str());
    	
    	if (pos != std::string::npos)
        {
            tmpPath.erase(pos, search.length());
            tmpPath.insert(pos, replace.c_str());
        }
        else
            break;

    } while (true); //(pos > std::string::npos);

    path = tmpPath;
}


/**
 * Ha létező directory, a teljes stringet adja vissza.
 * Ha létező file, a filename előtti részt.
 * Ha egyik sem, üres stringet ad vissz.
 * @return 
 */
std::string Path::getDirectory()
{
    std::string retVal = "";
    if (isValidDirectory())
    {
        retVal = path;
    }
    else if (isFile())
    {
        int pos = path.find_last_of(separator);
        if (pos > -1)
        {
            retVal = path.substr(0, pos);
        }
    }
    return retVal;
}