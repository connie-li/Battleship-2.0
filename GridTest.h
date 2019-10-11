#ifndef GRID_TEST_H
#define GRID_TEST_H

#include <string>
#include <iostream>
#include "Test.h"
#include "Grid.h"
using namespace std;

class GridTest: protected Test{
private:
    Grid m_grid;
    bool testLocRet();
    bool testRand();
    bool testPrint();
    bool testRead();
public:
    GridTest();
    void run();
};
#endif