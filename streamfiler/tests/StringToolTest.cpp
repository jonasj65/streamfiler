/*
 * File:   StringToolTest.cpp
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#include "StringToolTest.h"
#include "../stringtool.h"


CPPUNIT_TEST_SUITE_REGISTRATION(StriingToolTest);

StriingToolTest::StriingToolTest() 
{
}

StriingToolTest::~StriingToolTest() 
{
}

void StriingToolTest::setUp() 
{
}

void StriingToolTest::tearDown() 
{
}

void StriingToolTest::testIntToStr() 
{
    std::string expected = "123";
    int i = 123;
    std::string result = streamfiler::StringTool::intToStr(i);
    
    CPPUNIT_ASSERT_EQUAL(result, expected);
}

void StriingToolTest::testStrToInt() 
{
    int expected = 123;
    std::string str = "123";
    int i = 0;
    bool result = streamfiler::StringTool::strToInt(str, i);
    
    CPPUNIT_ASSERT(result);
    CPPUNIT_ASSERT_EQUAL(i, expected);
}

void StriingToolTest::testStrToIntWrong() 
{
    int expected = 0;
    std::string str = "123a";
    int i = 0;
    bool result = streamfiler::StringTool::strToInt(str, i);
    
    CPPUNIT_ASSERT(!result);
    CPPUNIT_ASSERT_EQUAL(i, expected);
}

void StriingToolTest::testIsNumber() 
{
    const std::string str = "123";
    streamfiler::StringTool stringTool;
    bool result = stringTool.isNumber(str);
    CPPUNIT_ASSERT(result);
}

void StriingToolTest::testIsNumberWrong() 
{
    const std::string str = "123a";
    bool result = streamfiler::StringTool::isNumber(str);
    CPPUNIT_ASSERT(!result);
}

void StriingToolTest::testSplit() 
{
    const char str[] = "abc/def/ghi";
    const char separator[] = "/";
    std::vector<std::string> result = streamfiler::StringTool::split(str, separator);
    CPPUNIT_ASSERT(result.size() == 3);
}

void StriingToolTest::testSplit2() 
{
    std::string str = "abc/def/ghi";
    std::string separator = "/";
    std::vector<std::string> result = streamfiler::StringTool::split(str, separator);
    CPPUNIT_ASSERT(result.size() == 3);
}

