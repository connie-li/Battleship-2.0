#ifndef GRID_TEST_H
#define GRID_TEST_H
#include <string>
#include <iostream>
#include "Test.h"
#include "Grid.h"
using namespace std;

class GridTest: protected Test{
private:
    Grid m_grid; /** A grid object to be tested */
    const int M_BOARD_SIZE = 8; /** The size of the board being tested. */
    
    /**
     * Tests the get and set functions of the grid.
     * @return bool: If true, success. If false, failure.
     */
    bool testLocRet();

    /**
     * Tests the random functionality of the grid.
     * @return bool: If true, success. If false, failure.
     */
    bool testRand();

    /**
     * Tests both prints of the grid
     * @return bool: If true, success. If false, failure.
     */
    bool testPrint();

    /**
     * Tests the coordinate Array read in
     * @return bool: If true, success. If false, failure.
     */
    bool testRead();
public:
    /**
     * Tests the grid class
     */
    GridTest();

    /**
     * Runs all of the test functions.
     */
    void run();
};
#endif