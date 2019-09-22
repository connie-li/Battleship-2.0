// @File Name: exec.h
// @Assignment: EECS 448 Project 1
// @Brief: This program is the .h file for the exec class. It begins the game

#ifndef EXEC_H
#define EXEC_H
#include "map.h"
#include <iostream>

class exec
{
  private:
    map* playerOneMap; //player1 map
    map* playerTwoMap; //player2 map
  public:
    void run(); //begins the game
};

#endif
