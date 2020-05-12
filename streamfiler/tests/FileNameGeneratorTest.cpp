/* 
 * File:   FileNameGeneratorTest.cpp
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#include "FileNameGeneratorTest.h"

#include <unistd.h>
#include "../path.h"

using namespace streamfiler_test;
using namespace streamfiler;

CPPUNIT_TEST_SUITE_REGISTRATION(FileNameGeneratorTest);


FileNameGeneratorTest::FileNameGeneratorTest() 
{
}

FileNameGeneratorTest::~FileNameGeneratorTest() {
}

void FileNameGeneratorTest::setUp() 
{
}

void FileNameGeneratorTest::tearDown() 
{
}


void FileNameGeneratorTest::testCreatePath()
{
    std::string str1 = "/opt/temp/testdir";
    rmdir(str1.c_str());
    
    Path p(str1);
    
    bool v0 = p.isValidDirectory();

    FileNameGenerator g(p);

    bool v1 = p.isValidDirectory();
    
    rmdir(str1.c_str());
    CPPUNIT_ASSERT(!v0 && v1);
}


void FileNameGeneratorTest::testGenerateFileName()
{
    std::string str1 = "/opt/temp";
    std::string strExp = "/opt/temp/20200429140000123";
    
    Path p(str1);
    FileNameGenerator g(p);
    
    g.timestamp.tv_sec = 1588161600; // Epoch timestamp, 2020.04.29. 12:00:00 UTC
    g.timestamp.tv_nsec = 123 * 1000000.0; // .123 sec
    
    // Ha false, nem generál file nevet, mert nincs időbélyeg. A setTimeByNow() állítja be.
    g.valid = true; 
    
    std::string fn = g.getFullPath();

    CPPUNIT_ASSERT_EQUAL(strExp, fn);
}