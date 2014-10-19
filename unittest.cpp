/**
 * @file unittest.cpp
 * @author John Wilkes
 */

#include "unittest.h"

UnitTestGroup::UnitTestGroup()
{
}

UnitTestGroup::~UnitTestGroup()
{
}

void UnitTestGroup::AddUnitTest(void(*test)())
{
    tests.push_back(test);
}
