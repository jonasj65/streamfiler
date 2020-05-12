/*
 * File:   newtestclass.cpp
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#include "PathTest.h"

#include <iostream>
#include <fstream>

using namespace streamfiler_test;
using namespace streamfiler;


CPPUNIT_TEST_SUITE_REGISTRATION(PathTest);

PathTest::PathTest() 
{
}

PathTest::~PathTest() 
{
}

void PathTest::setUp() 
{
}

void PathTest::tearDown() 
{
}

void PathTest::testEmptyPath() 
{
    Path p;
    std::string s = p.path;
    CPPUNIT_ASSERT(s.empty());
}

void PathTest::testInitPath1() 
{
    std::string str = "/opt/temp";
    
    Path p(str);
    std::string s = p.path;
    CPPUNIT_ASSERT_EQUAL(str, s);
}

void PathTest::testInitPath2() 
{
    std::string str = "/opt/temp";
    
    Path p(str);
    std::string s = p.getPath();
    CPPUNIT_ASSERT_EQUAL(str, s);
}

void PathTest::testAppendPath1() 
{
    std::string str1 = "/opt/temp";
    std::string str2 = "pathtest";
    std::string strExp = "/opt/temp/pathtest";

    Path p(str1);
    p.append(str2);
    std::string s = p.path;
    CPPUNIT_ASSERT_EQUAL(strExp, s);
}

void PathTest::testAppendPath2() 
{
    std::string str1 = "/opt/temp/";
    std::string str2 = "pathtest";
    std::string strExp = "/opt/temp/pathtest";

    Path p(str1);
    p.append(str2);
    std::string s = p.path;
    CPPUNIT_ASSERT_EQUAL(strExp, s);
}

void PathTest::testAppendPath3() 
{
    std::string str1 = "/opt/temp";
    std::string str2 = "/pathtest";
    std::string strExp = "/opt/temp/pathtest";

    Path p(str1);
    p.append(str2);
    std::string s = p.path;
    CPPUNIT_ASSERT_EQUAL(strExp, s);
}

void PathTest::testAppendPath4() 
{
    std::string str1 = "/opt/temp/";
    std::string str2 = "/pathtest";
    std::string strExp = "/opt/temp/pathtest";

    Path p(str1);
    p.append(str2);
    std::string s = p.path;
    CPPUNIT_ASSERT_EQUAL(strExp, s);
}


void PathTest::testAppendPath5() 
{
    std::string str1 = "/opt/temp/";
    std::string str2 = "../pathtest";
    std::string strExp = "/opt/pathtest";

    Path p(str1);
    p.append(str2);
    std::string s = p.path;
    CPPUNIT_ASSERT_EQUAL(strExp, s);
}

void PathTest::testGetDirectory1()
{
    std::string str1 = "/opt/temp/";
    
    Path p(str1);
    std::string s = p.getDirectory();
    CPPUNIT_ASSERT_EQUAL(str1, s);
}

void PathTest::testGetDirectoryNotExistingFile()
{
    std::string str1 = "/opt/temp/filename.txt";
    remove(str1.c_str());

    Path p(str1);
    std::string s = p.getDirectory();;
    CPPUNIT_ASSERT(s.empty());
}

void PathTest::testGetDirectoryExistingFile()
{
    std::string str1 = "/opt/temp/filename.txt";
    std::string strExp = "/opt/temp";
    
    std::ofstream of(str1.c_str());
    of.close();
  
    Path p(str1);
    std::string s = p.getDirectory();
    
    remove(str1.c_str());
    CPPUNIT_ASSERT_EQUAL(strExp, s);
}

