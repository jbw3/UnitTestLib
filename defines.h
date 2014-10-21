/**
 * @brief defines.h
 * @author John Wilkes
 *
 * @todo
 * - Add EXPECT_CSTR_EQ
 * - Add EXPECT_CSTR_NE
 * - Add EXPECT_THROW
 * - Add EXPECT_NO_THROW
 * - Add ASSERT_CSTR_EQ
 * - Add ASSERT_CSTR_NE
 * - Add ASSERT_THROW
 * - Add ASSERT_NO_THROW
 * - Add FAIL_TEST
 */

#ifndef UNIT_TEST_DEFINES_H
#define UNIT_TEST_DEFINES_H

#define FUNCTION_AND_NAME(fPtr) fPtr, #fPtr

#define UNIT_TEST_FUNCTION(name) void name(bool& _passed, std::string& _errorStr)

// ----- EXPECT -----

#define EXPECT_BLOCK(eval, errorMsg) \
    if (!(eval)) \
    { \
        _passed = false; \
        std::stringstream ss; \
        ss << "Line " << __LINE__ << ": " << errorMsg << '\n'; \
        _errorStr += ss.str(); \
    }

#define EXPECT_TRUE(a) EXPECT_BLOCK(a, #a << " is false")

#define EXPECT_FALSE(a) EXPECT_BLOCK(!(a), #a << " is true")

#define EXPECT_EQ(a, b) EXPECT_BLOCK((a) == (b), #a << " != " << #b << " (" << (a) << " != " << (b) << ")")

#define EXPECT_NE(a, b) EXPECT_BLOCK((a) != (b), #a << " == " << #b << " (" << (a) << " == " << (b) << ")")

#define EXPECT_LT(a, b) EXPECT_BLOCK((a) < (b), #a << " >= " << #b << " (" << (a) << " >= " << (b) << ")")

#define EXPECT_LE(a, b) EXPECT_BLOCK((a) <= (b), #a << " > " << #b << " (" << (a) << " > " << (b) << ")")

#define EXPECT_GT(a, b) EXPECT_BLOCK((a) > (b), #a << " <= " << #b << " (" << (a) << " <= " << (b) << ")")

#define EXPECT_GE(a, b) EXPECT_BLOCK((a) >= (b), #a << " < " << #b << " (" << (a) << " < " << (b) << ")")

// ----- ASSERT -----

#define ASSERT_BLOCK(eval, errorMsg) \
    if (!(eval)) \
    { \
    	_passed = false; \
    	std::stringstream ss; \
    	ss << "Line " << __LINE__ << ": " << errorMsg << '\n'; \
    	_errorStr += ss.str(); \
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

#endif // UNIT_TEST_DEFINES_H
