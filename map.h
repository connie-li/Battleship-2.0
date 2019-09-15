#ifndef MAP_H
#define MAP_H
#include "ship.h"
#include <iostream>


class map
{
  private:
    char** gridMap; //2D array of chars for 8x8 grid of positions to hide boats and land shots.
    std::string fleet[5]={"Tug", "Destroyer", "Cruiser", "BattleShip", "Carrier"}; //Names of the Boats
    bool checkShipLength(std::string start, std::string end, int length);
    bool checkShipPosition(std::string start, std::string end);
    void addShip(std::string start, std::string end);

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
