/**
 * @brief defines.h
 * @author John Wilkes
 *
 * @todo
 * - Add EXPECT_THROW
 * - Add EXPECT_NO_THROW
 * - Add ASSERT_THROW
 * - Add ASSERT_NO_THROW
 */

#ifndef UNIT_TEST_DEFINES_H
#define UNIT_TEST_DEFINES_H

#include <cstring>

#define FUNCTION_AND_NAME(fPtr) fPtr, #fPtr

#define UNIT_TEST_FUNCTION(name) void name(bool& passed__, std::string& errorStr__)

#define FAIL_TEST(errorMsg) \
    { \
        passed__ = false; \
        std::stringstream error_ss__; \
        error_ss__ << "Line " << __LINE__ << ": " << errorMsg << '\n'; \
        errorStr__ += error_ss__.str(); \
        return; \
    }

// ----- EXPECT -----

#define EXPECT_BLOCK(eval, errorMsg) \
    if (!(eval)) \
    { \
        passed__ = false; \
        std::stringstream error_ss__; \
        error_ss__ << "Line " << __LINE__ << ": " << errorMsg << '\n'; \
        errorStr__ += error_ss__.str(); \
    }

#define EXPECT_TRUE(a) EXPECT_BLOCK(a, #a << " is false")

#define EXPECT_FALSE(a) EXPECT_BLOCK(!(a), #a << " is true")

#define EXPECT_EQ(a, b) EXPECT_BLOCK((a) == (b), #a << " != " << #b << " (" << (a) << " != " << (b) << ")")

#define EXPECT_NE(a, b) EXPECT_BLOCK((a) != (b), #a << " == " << #b << " (" << (a) << " == " << (b) << ")")

#define EXPECT_LT(a, b) EXPECT_BLOCK((a) < (b), #a << " >= " << #b << " (" << (a) << " >= " << (b) << ")")

#define EXPECT_LE(a, b) EXPECT_BLOCK((a) <= (b), #a << " > " << #b << " (" << (a) << " > " << (b) << ")")

#define EXPECT_GT(a, b) EXPECT_BLOCK((a) > (b), #a << " <= " << #b << " (" << (a) << " <= " << (b) << ")")

#define EXPECT_GE(a, b) EXPECT_BLOCK((a) >= (b), #a << " < " << #b << " (" << (a) << " < " << (b) << ")")

#define EXPECT_CSTR_EQ(a, b) EXPECT_BLOCK(strcmp(a, b) == 0, '"' << a << "\" != \"" << b << '"')

#define EXPECT_CSTR_NE(a, b) EXPECT_BLOCK(strcmp(a, b) != 0, '"' << a << "\" == \"" << b << '"')

// ----- ASSERT -----

#define ASSERT_BLOCK(eval, errorMsg) \
    if (!(eval)) \
    { \
    	passed__ = false; \
    	std::stringstream error_ss__; \
    	error_ss__ << "Line " << __LINE__ << ": " << errorMsg << '\n'; \
    	errorStr__ += error_ss__.str(); \
    	return; \
    }

#define ASSERT_TRUE(a) ASSERT_BLOCK(a, #a << " is false")

#define ASSERT_FALSE(a) ASSERT_BLOCK(!(a), #a << " is true")

#define ASSERT_EQ(a, b) ASSERT_BLOCK((a) == (b),  #a << " != " << #b << " (" << (a) << " != " << (b) << ")")

#define ASSERT_NE(a, b) ASSERT_BLOCK((a) != (b),  #a << " == " << #b << " (" << (a) << " == " << (b) << ")")

#define ASSERT_LT(a, b) ASSERT_BLOCK((a) < (b), #a << " >= " << #b << " (" << (a) << " >= " << (b) << ")")

#define ASSERT_LE(a, b) ASSERT_BLOCK((a) <= (b), #a << " > " << #b << " (" << (a) << " > " << (b) << ")")

#define ASSERT_GT(a, b) ASSERT_BLOCK((a) > (b), #a << " <= " << #b << " (" << (a) << " <= " << (b) << ")")

#define ASSERT_GE(a, b) ASSERT_BLOCK((a) >= (b), #a << " < " << #b << " (" << (a) << " < " << (b) << ")")

#define ASSERT_CSTR_EQ(a, b) ASSERT_BLOCK(strcmp(a, b) == 0, '"' << a << "\" != \"" << b << '"')

#define ASSERT_CSTR_NE(a, b) ASSERT_BLOCK(strcmp(a, b) != 0, '"' << a << "\" == \"" << b << '"')

#endif // UNIT_TEST_DEFINES_H
