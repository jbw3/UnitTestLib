/**
 * @file unittestgroup.h
 * @author John Wilkes
 */

#ifndef UNIT_TEST_GROUP_H
#define UNIT_TEST_GROUP_H

#include <list>
#include <string>

struct TestData
{
    void(*test)(bool&);
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

    void AddUnitTest(void(*test)(bool&), const std::string& name);

    void RunUnitTests();

private:
    std::list<TestData> tests;
};

#endif // UNIT_TEST_GROUP_H
