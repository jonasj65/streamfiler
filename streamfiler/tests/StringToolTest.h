/*
 * File:   StringToolTest.h
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#ifndef STRINGTOOLTEST_H
#define STRINGTOOLTEST_H

#include <cppunit/extensions/HelperMacros.h>

class StriingToolTest : public CPPUNIT_NS::TestFixture 
{
    CPPUNIT_TEST_SUITE(StriingToolTest);

    CPPUNIT_TEST(testIntToStr);
    CPPUNIT_TEST(testStrToInt);
    CPPUNIT_TEST(testStrToIntWrong);
    CPPUNIT_TEST(testIsNumber);
    CPPUNIT_TEST(testIsNumberWrong);
    CPPUNIT_TEST(testSplit);
    CPPUNIT_TEST(testSplit2);

    CPPUNIT_TEST_SUITE_END();

public:
    StriingToolTest();
    virtual ~StriingToolTest();
    void setUp();
    void tearDown();

private:
    void testIntToStr();
    void testStrToInt();
    void testStrToIntWrong();
    void testIsNumber();
    void testIsNumberWrong();
    void testSplit();
    void testSplit2();

};

#endif /* STRINGTOOLTEST_H */

