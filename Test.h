#ifndef TEST_H
#define TEST_H

#include <string>
#include <iostream>
using namespace std;

class Test{
protected:
    const string pass = "SUCCESS\n";
    const string fail = "FAILURE\n";
    const string unkno = "UNKNOWN\n";

public:
    typedef bool (*func)();
    void testFunc(string write, func testFunction);
    Test();
};
#endif