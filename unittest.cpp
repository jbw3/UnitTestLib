/**
 * @file unittest.cpp
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

void UnitTestGroup::AddUnitTest(void(*test)(bool&), const std::string& name)
{
    TestData data;
    data.test = test;
    data.name = name;
    tests.push_back(data);
}

void UnitTestGroup::RunUnitTests()
{
    bool passed;
    unsigned int numTests = tests.size();
    unsigned int numPassed = 0;

    std::cout << "Running " << numTests << " test";
    if (numTests != 1)
        std::cout << 's';
    std::cout << "...\n" << std::flush;

    for (std::list<TestData>::iterator iter = tests.begin(); iter != tests.end(); ++iter)
    {
        passed = true;
        (iter->test)(passed);
        if (passed)
            ++numPassed;
    }
    std::cout << numPassed << " of " << numTests << " tests passed\n" << std::flush;
}
