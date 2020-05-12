/* 
 * File:   FileNameGeneratorTest.h
 * Author: Janos Jonas
 *
 * Created on April 29, 2020, 12:00 AM
 */

#ifndef FILENAMEGENERATORTEST_H
#define FILENAMEGENERATORTEST_H

#include <cppunit/extensions/HelperMacros.h>

#include "../filenamegenerator.h"

namespace streamfiler_test
{
    class FileNameGeneratorTest : public CPPUNIT_NS::TestFixture  
    {
    
        CPPUNIT_TEST_SUITE(FileNameGeneratorTest);

        CPPUNIT_TEST(testCreatePath);
        CPPUNIT_TEST(testGenerateFileName);

        CPPUNIT_TEST_SUITE_END();
    public:
        FileNameGeneratorTest();
        virtual ~FileNameGeneratorTest();
        void setUp();
        void tearDown();
        
    private:
        void testCreatePath();
        void testGenerateFileName();

    };
}

#endif /* FILENAMEGENERATORTEST_H */

