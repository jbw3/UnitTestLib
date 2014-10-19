/**
 * @file unittest.h
 * @author John Wilkes
 */

#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <list>
#include <string>

#define FUNCTION_AND_NAME(fPtr) fPtr, #fPtr

#define UNIT_TEST_FUNCTION(name) void name()

struct TestData
{
    void(*test)();
    std::string name;
};

class UnitTestGroup
{
public:
    /**
     * @brief Constructor
     */
    UnitTestGroup();

    /**
     * @brief Destructor
     */
    ~UnitTestGroup();

    void AddUnitTest(void(*test)(), const std::string& name);

    void RunUnitTests();

private:
    std::list<TestData> tests;
};

#endif // UNIT_TEST_H
