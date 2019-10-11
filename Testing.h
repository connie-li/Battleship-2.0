#ifndef TESTING_H
#define TESTING_H

#include <iostream>
#include <string>
#include "GridTest.h"
using namespace std;

class Testing{
private:
    GridTest grid;
public:
    Testing();
    void run();
};
#endif