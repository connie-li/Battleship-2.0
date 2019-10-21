#ifndef TESTING_H
#define TESTING_H

#include <iostream>
#include <string>
#include "GridTest.h"
#include "PowerUpsTest.h"
using namespace std;

class Testing{
private:
    GridTest grid; /** Test for a grid */
    PowerUpsTest PowerUps; /**Test for a PowerUps object */
public:
    /**
     * Testing manages and runs all tests that inherit from Test
     * It can be called when running by passing in a -t flag.
     */
    Testing();

    /**
     * Calls the run function for each test.
     */
    void run();
};
#endif