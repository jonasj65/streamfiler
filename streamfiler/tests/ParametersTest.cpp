/*
 * File:   ParametersTest.cpp
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#include "ParametersTest.h"

using namespace streamfiler_test;
using namespace streamfiler;

CPPUNIT_TEST_SUITE_REGISTRATION(ParametersTest);

ParametersTest::ParametersTest() 
{

}

ParametersTest::~ParametersTest() 
{
}

void ParametersTest::setUp() 
{
}

void ParametersTest::tearDown() 
{
    Parameters::releaseInstance();
}

void ParametersTest::testInstancePointer() 
{
    Parameters* p0 = Parameters::instance;
    Parameters* p = Parameters::getInstance();
    CPPUNIT_ASSERT((p0 == nullptr) && (p != nullptr));
}


void ParametersTest::testConnectionsGood() 
{
    char* arg[] = {arg0,arg1S,arg2,port};
    int c0 = Parameters::getInstance()->getConnections();
    std::string f0 = Parameters::getInstance()->getDirectoryStr();
    int l0 = Parameters::getInstance()->getLimit();
    int t0 = Parameters::getInstance()->getTimeout();
    bool h0 = Parameters::getInstance()->getHelp();
    bool v0 = Parameters::getInstance()->getVerbose();
    
    bool ok = Parameters::getInstance()->parseParams(4, arg);

    int c1 = Parameters::getInstance()->getConnections();
    std::string f1 = Parameters::getInstance()->getDirectoryStr();
    int l1 = Parameters::getInstance()->getLimit();
    int t1 = Parameters::getInstance()->getTimeout();
    bool h1 = Parameters::getInstance()->getHelp();
    bool v1 = Parameters::getInstance()->getVerbose();
    
    CPPUNIT_ASSERT(ok);
    CPPUNIT_ASSERT(c0 == -10 && f0.empty() && l0 == -10 && t0 == -10 && h0 == false && v0 == false);
    CPPUNIT_ASSERT(c1 == 3 && f1.length() > 0 && l1 == DEFAULT_LIMIT && t1 == DEFAULT_TIMEOUT && h1 == false && v1 == false);
}

void ParametersTest::testConnectionsWrong() 
{
    char* arg[] = {arg0,arg1S,arg2Wrong,port};
    int c0 = Parameters::getInstance()->getConnections();
    std::string f0 = Parameters::getInstance()->getDirectoryStr();
    int l0 = Parameters::getInstance()->getLimit();
    int t0 = Parameters::getInstance()->getTimeout();
    bool h0 = Parameters::getInstance()->getHelp();
    bool v0 = Parameters::getInstance()->getVerbose();
    
    bool ok = Parameters::getInstance()->parseParams(4, arg);

    int c1 = Parameters::getInstance()->getConnections();
    std::string f1 = Parameters::getInstance()->getDirectoryStr();
    int l1 = Parameters::getInstance()->getLimit();
    int t1 = Parameters::getInstance()->getTimeout();
    bool h1 = Parameters::getInstance()->getHelp();
    bool v1 = Parameters::getInstance()->getVerbose();
    
    CPPUNIT_ASSERT(ok);
    CPPUNIT_ASSERT(c0 == -10 && f0.empty() && l0 == -10 && t0 == -10 && h0 == false && v0 == false);
    CPPUNIT_ASSERT(c1 == DEFAULT_CONNECTIONS && f1.length() > 0 && l1 == DEFAULT_LIMIT && t1 == DEFAULT_TIMEOUT && h1 == false && v1 == false);
}

void ParametersTest::testArg1SWrong()
{
    char* arg[] = {arg0,arg1SWrong,arg2,port};
    int c0 = Parameters::getInstance()->getConnections();
    std::string f0 = Parameters::getInstance()->getDirectoryStr();
    int l0 = Parameters::getInstance()->getLimit();
    int t0 = Parameters::getInstance()->getTimeout();
    bool h0 = Parameters::getInstance()->getHelp();
    bool v0 = Parameters::getInstance()->getVerbose();
    
    bool ok = Parameters::getInstance()->parseParams(4, arg);

    int c1 = Parameters::getInstance()->getConnections();
    std::string f1 = Parameters::getInstance()->getDirectoryStr();
    int l1 = Parameters::getInstance()->getLimit();
    int t1 = Parameters::getInstance()->getTimeout();
    bool h1 = Parameters::getInstance()->getHelp();
    bool v1 = Parameters::getInstance()->getVerbose();
    
    CPPUNIT_ASSERT(ok);
    CPPUNIT_ASSERT(c0 == -10 && f0.empty() && l0 == -10 && t0 == -10 && h0 == false && v0 == false);
    CPPUNIT_ASSERT(c1 == DEFAULT_CONNECTIONS && f1.length() > 0 && l1 == DEFAULT_LIMIT && t1 == DEFAULT_TIMEOUT && h1 == false && v1 == false);
    
}

void ParametersTest::testArg1LWrong()
{
    char* arg[] = {arg0,arg1LWrong,arg2,port};
    int c0 = Parameters::getInstance()->getConnections();
    std::string f0 = Parameters::getInstance()->getDirectoryStr();
    int l0 = Parameters::getInstance()->getLimit();
    int t0 = Parameters::getInstance()->getTimeout();
    bool h0 = Parameters::getInstance()->getHelp();
    bool v0 = Parameters::getInstance()->getVerbose();  
    
    bool ok = Parameters::getInstance()->parseParams(4, arg);

    int c1 = Parameters::getInstance()->getConnections();
    std::string f1 = Parameters::getInstance()->getDirectoryStr();
    int l1 = Parameters::getInstance()->getLimit();
    int t1 = Parameters::getInstance()->getTimeout();
    bool h1 = Parameters::getInstance()->getHelp();
    bool v1 = Parameters::getInstance()->getVerbose();    
    
    CPPUNIT_ASSERT(ok);
    CPPUNIT_ASSERT(c0 == -10 && f0.empty() && l0 == -10 && t0 == -10 && h0 == false && v0 == false);
    CPPUNIT_ASSERT(c1 == DEFAULT_CONNECTIONS && f1.length() > 0 && l1 == DEFAULT_LIMIT && t1 == DEFAULT_TIMEOUT && h1 == false && v1 == false);
}

void ParametersTest::testArg1SMissing()
{
    char* arg[] = {arg0,arg1SMissing,arg2,port};
    int c0 = Parameters::getInstance()->getConnections();
    std::string f0 = Parameters::getInstance()->getDirectoryStr();
    int l0 = Parameters::getInstance()->getLimit();
    int t0 = Parameters::getInstance()->getTimeout();
    bool h0 = Parameters::getInstance()->getHelp();
    bool v0 = Parameters::getInstance()->getVerbose();    
    
    bool ok = Parameters::getInstance()->parseParams(4, arg);

    int c1 = Parameters::getInstance()->getConnections();
    std::string f1 = Parameters::getInstance()->getDirectoryStr();
    int l1 = Parameters::getInstance()->getLimit();
    int t1 = Parameters::getInstance()->getTimeout();
    bool h1 = Parameters::getInstance()->getHelp();
    bool v1 = Parameters::getInstance()->getVerbose();    
    
    CPPUNIT_ASSERT(ok);
    CPPUNIT_ASSERT(c0 == -10 && f0.empty() && l0 == -10 && t0 == -10 && h0 == false && v0 == false);
    CPPUNIT_ASSERT(c1 == DEFAULT_CONNECTIONS && f1.length() > 0 && l1 == DEFAULT_LIMIT && t1 == DEFAULT_TIMEOUT && h1 == false && v1 == false);
}

void ParametersTest::testArg1LMissing()
{
    char* arg[] = {arg0,arg1LMissing,arg2,port};
    int c0 = Parameters::getInstance()->getConnections();
    std::string f0 = Parameters::getInstance()->getDirectoryStr();
    int l0 = Parameters::getInstance()->getLimit();
    int t0 = Parameters::getInstance()->getTimeout();
    bool h0 = Parameters::getInstance()->getHelp();
    bool v0 = Parameters::getInstance()->getVerbose();    
    
    bool ok = Parameters::getInstance()->parseParams(4, arg);

    int c1 = Parameters::getInstance()->getConnections();
    std::string f1 = Parameters::getInstance()->getDirectoryStr();
    int l1 = Parameters::getInstance()->getLimit();
    int t1 = Parameters::getInstance()->getTimeout();
    bool h1 = Parameters::getInstance()->getHelp();
    bool v1 = Parameters::getInstance()->getVerbose();    
    
    CPPUNIT_ASSERT(ok);
    CPPUNIT_ASSERT(c0 == -10 && f0.empty() && l0 == -10 && t0 == -10 && h0 == false && v0 == false);
    CPPUNIT_ASSERT(c1 == DEFAULT_CONNECTIONS && f1.length() > 0 && l1 == DEFAULT_LIMIT && t1 == DEFAULT_TIMEOUT && h1 == false && v1 == false);
}

void ParametersTest::testParametersAll() 
{
    char* arg[] = {arg0,arg1S,arg2,arg3S,arg4,arg5S,arg6,arg7S,arg8,port};
    
    int c0 = Parameters::getInstance()->getConnections();
    std::string f0 = Parameters::getInstance()->getDirectoryStr();
    int l0 = Parameters::getInstance()->getLimit();
    int t0 = Parameters::getInstance()->getTimeout();
    bool h0 = Parameters::getInstance()->getHelp();
    bool v0 = Parameters::getInstance()->getVerbose();    
    
    bool ok = Parameters::getInstance()->parseParams(10, arg);

    int c1 = Parameters::getInstance()->getConnections();
    std::string f1 = Parameters::getInstance()->getDirectoryStr();
    int l1 = Parameters::getInstance()->getLimit();
    int t1 = Parameters::getInstance()->getTimeout();
    bool h1 = Parameters::getInstance()->getHelp();
    bool v1 = Parameters::getInstance()->getVerbose();    
    
    CPPUNIT_ASSERT(ok);
    CPPUNIT_ASSERT(c0 == -10 && f0.empty() && l0 == -10 && t0 == -10 && h0 == false && v0 == false);
    //CPPUNIT_ASSERT(c1 == 3 && f1.length() > 0 && l1 == 10 && t1 == 10000 && h1 == false && v1 == false);

}

void ParametersTest::testParametersAllLong() 
{
    char* arg[] = {arg0,arg1L,arg2,arg3L,arg4,arg5L,arg6,arg7L,arg8,port};
    
    int c0 = Parameters::getInstance()->getConnections();
    std::string f0 = Parameters::getInstance()->getDirectoryStr();
    int l0 = Parameters::getInstance()->getLimit();
    int t0 = Parameters::getInstance()->getTimeout();
    bool h0 = Parameters::getInstance()->getHelp();
    bool v0 = Parameters::getInstance()->getVerbose();    
    
    bool ok = Parameters::getInstance()->parseParams(10, arg);

    int c1 = Parameters::getInstance()->getConnections();
    std::string f1 = Parameters::getInstance()->getDirectoryStr();
    int l1 = Parameters::getInstance()->getLimit();
    int t1 = Parameters::getInstance()->getTimeout();
    bool h1 = Parameters::getInstance()->getHelp();
    bool v1 = Parameters::getInstance()->getVerbose();    
    
    CPPUNIT_ASSERT(ok);
    CPPUNIT_ASSERT(c0 == -10 && f0.empty() && l0 == -10 && t0 == -10 && h0 == false && v0 == false);
    //CPPUNIT_ASSERT(c1 == 3 && f1.length() > 0 && l1 == 10 && t1 == 10000 && h1 == false && v1 == false);
    
}