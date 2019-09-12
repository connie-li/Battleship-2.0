#ifndef EXEC_H
#define EXEC_H
#include "map.h"
#include <iostream>

class exec
{
  private:
    map* playerOneMap;
    map* playerTwoMap;
  public:
    void run();
};

#endif
