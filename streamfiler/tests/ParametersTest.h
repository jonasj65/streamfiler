/*
 * File:   PatametersTest.h
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#ifndef PATAMETERSTEST_H
#define PATAMETERSTEST_H

#include <cppunit/extensions/HelperMacros.h>

#include "../parameters.h"


#define arg0 "streamfiler"
#define arg1S "-c"
#define arg1L "--connections"
#define arg1SWrong "--c"
#define arg1LWrong "--connections"
#define arg1SMissing "-C"
#define arg1LMissing "--Connections"
#define arg2 "3"
#define arg2Wrong "a"
#define arg3S "-f"
#define arg3L "--folder"
#define arg4 "/opt/temp/download"
#define arg5S "-l"
#define arg5L "--limit"
#define arg6 "10"
#define arg7S "-t"
#define arg7L "--timeout"
#define arg8 "10000"
#define arg9S "-h"
#define arg9L "--help"
#define arg10S "-v"
#define arg10L "--verbose"
#define port "12345"


namespace streamfiler_test
{
   class ParametersTest : public CPPUNIT_NS::TestFixture 
   {
        CPPUNIT_TEST_SUITE(ParametersTest);

        CPPUNIT_TEST(testInstancePointer);
        CPPUNIT_TEST(testConnectionsGood);
        CPPUNIT_TEST(testConnectionsWrong);
        CPPUNIT_TEST(testArg1SWrong);
        CPPUNIT_TEST(testArg1LWrong);
        CPPUNIT_TEST(testArg1SMissing);
        CPPUNIT_TEST(testArg1LMissing);
        CPPUNIT_TEST(testParametersAll);
        CPPUNIT_TEST(testParametersAllLong);

        CPPUNIT_TEST_SUITE_END();

    public:
        ParametersTest();
        virtual ~ParametersTest();
        void setUp();
        void tearDown();

    private:
        void testInstancePointer();
        void testConnectionsGood();
        void testConnectionsWrong();
        void testArg1SWrong();
        void testArg1LWrong();
        void testArg1SMissing();
        void testArg1LMissing();
        void testParametersAll();
        void testParametersAllLong();
    }; 
}


#endif /* PATAMETERSTEST_H */

