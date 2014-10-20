/**
 * @file unittestgroup.cpp
 * @author John Wilkes
 */

#include <iostream>
#include "unittest.h"

UnitTestGroup::UnitTestGroup()
{
}

UnitTestGroup::~UnitTestGroup()
{
}

void UnitTestGroup::AddUnitTest(void(*test)(bool&, std::string&), const std::string& name)
{
    TestData data;
    data.test = test;
    data.name = name;
    tests.push_back(data);
}

void UnitTestGroup::RunUnitTests()
{
    bool passed;
    std::string errorStr;
    unsigned int numTests = tests.size();
    unsigned int numPassed = 0;

    std::cout << "------------------------------\n"
              << "Running " << numTests << " test";
    if (numTests != 1)
        std::cout << 's';
    std::cout << "...\n" << std::flush;

    for (std::list<TestData>::iterator iter = tests.begin(); iter != tests.end(); ++iter)
    {
        passed = true;
        errorStr = "";
        (iter->test)(passed, errorStr);
        if (passed)
        {
            ++numPassed;
        }
        else
        {
            std::cout << "------------------------------\n"
                      << "FAILED: " << iter->name << '\n'
                      << errorStr << std::flush;
        }
    }
    std::cout << "------------------------------\n"
              << numPassed << " of " << numTests << " tests passed\n"
              << "------------------------------\n" << std::flush;
}
