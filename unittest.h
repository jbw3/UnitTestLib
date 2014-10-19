/**
 * @file unittest.h
 * @author John Wilkes
 */

#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <list>

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

    void AddUnitTest(void(*test)());

private:
    std::list<void(*)()> tests;
};

#endif // UNIT_TEST_H
