/// File Name: exec.h.
/// Assignment: EECS 448 Project 1.
/// Brief: This program is the .h file for the exec class. It begins the game.
#ifndef EXEC_H
#define EXEC_H
#include "map.h"
#include <iostream>

class exec
{
  private:
    /// player1 map.
    map* playerOneMap;
    /// player2 map.
    map* playerTwoMap;
  public:
    /// begins the game.
    void run();
};

#endif
