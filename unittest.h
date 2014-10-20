/**
 * @file unittest.h
 * @author John Wilkes
 */

#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <list>
#include <string>

#define FUNCTION_AND_NAME(fPtr) fPtr, #fPtr

#define UNIT_TEST_FUNCTION(name) void name(bool& passed)

#define EXPECT_EQ(a, b) \
    if ( !((a) == (b)) ) \
    { \
        passed = false; \
        std::cout << (a) << " != " << (b) << std::endl; \
    }

#define EXPECT_NEQ(a, b) \
    if ( !((a) != (b)) ) \
    { \
        passed = false; \
        std::cout << (a) << " == " << (b) << std::endl; \
    }

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

#endif // UNIT_TEST_H
