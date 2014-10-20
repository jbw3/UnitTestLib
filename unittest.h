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

#define EXPECT_BLOCK(eval, errorMsg) \
    if (!(eval)) \
    { \
        passed = false; \
        std::cout << "Failed: line " << __LINE__ << ": " << errorMsg << std::endl; \
    }

#define EXPECT_TRUE(a) EXPECT_BLOCK(a, "expression is false")

#define EXPECT_FALSE(a) EXPECT_BLOCK(!(a), "expression is true")

#define EXPECT_EQ(a, b) EXPECT_BLOCK((a) == (b), (a) << " != " << (b))

#define EXPECT_NEQ(a, b) EXPECT_BLOCK((a) != (b), (a) << " == " << (b))

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
