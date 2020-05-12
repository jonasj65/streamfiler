/*
 * File:   newtestclass.h
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#ifndef PATHTEST_H
#define PATHTEST_H

#include <cppunit/extensions/HelperMacros.h>

#include "../path.h"

namespace streamfiler_test
{
    class PathTest : public CPPUNIT_NS::TestFixture {
        CPPUNIT_TEST_SUITE(PathTest);

        CPPUNIT_TEST(testEmptyPath);
        CPPUNIT_TEST(testInitPath1);
        CPPUNIT_TEST(testInitPath2);
        CPPUNIT_TEST(testAppendPath1);
        CPPUNIT_TEST(testAppendPath2);
        CPPUNIT_TEST(testAppendPath3);
        CPPUNIT_TEST(testAppendPath4);
        CPPUNIT_TEST(testAppendPath5);
        CPPUNIT_TEST(testGetDirectory1);
        CPPUNIT_TEST(testGetDirectoryNotExistingFile);
        CPPUNIT_TEST(testGetDirectoryExistingFile);

        CPPUNIT_TEST_SUITE_END();

    public:
        PathTest();
        virtual ~PathTest();
        void setUp();
        void tearDown();

    private:
        void testEmptyPath();
        void testInitPath1();
        void testInitPath2();
        void testAppendPath1();
        void testAppendPath2();
        void testAppendPath3();
        void testAppendPath4();
        void testAppendPath5();
        void testGetDirectory1();
        void testGetDirectoryNotExistingFile();
        void testGetDirectoryExistingFile();

    };
    
}

#endif /* PATHTEST_H */

