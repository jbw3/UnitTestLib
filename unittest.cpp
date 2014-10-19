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

void UnitTestGroup::AddUnitTest(void(*test)(), const std::string& name)
{
	TestData data;
	data.test = test;
	data.name = name;
    tests.push_back(data);
}

void UnitTestGroup::RunUnitTests()
{
	for (std::list<TestData>::iterator iter = tests.begin(); iter != tests.end(); ++iter)
	{
		std::cout << "Running " << iter->name << "...\n" << std::flush;
		(iter->test)();
	}
}
