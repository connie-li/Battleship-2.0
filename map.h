#ifndef MAP_H
#define MAP_H
#include "ship.h"
#include <iostream>


class map
{
  private:
    char** gridMap; //2D array of chars for 8x8 grid of positions to hide boats and land shots.
    ship* fleet; //Possible dynamically allocated array of ships, not sure on ship class implementation.
  public:
    map(int shipNum); //constructor is likely needed, implementation will depend on ship class implementation.
    bool validPos(std::string pos); //returns if valid position in bool.
    void printEnemyShotMap(); //Prints the map with ships filtered out, so opponent can see their fired shots.
    void printCurrentMap(); //Map with ships for the player to see what the opponent has done to their field.
    void incomingShot(std::string pos); //Shot landing on player's map, fired by opponent.
    bool gameOver(); //Checks if all ships are sunk
    ~map(); //2D array might not have to be dynamically allocated, in which case remove this.
};

#endif
