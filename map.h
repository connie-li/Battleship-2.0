// @File Name: map.h
// @Assignment: EECS 448 Project 1
// @Brief: This program is the .h file for the map class. It defines the functions used for playing the game

#ifndef MAP_H
#define MAP_H

#include <iostream>


class map
{
  private:
    char** gridMap;

    //2D array of chars for 8x8 grid of positions to hide boats and land shots.

    std::string fleet[5]={"Tug", "Destroyer", "Cruiser", "BattleShip", "Carrier"};

    //Names of the Boats

    bool checkShipLength(std::string start, std::string end, int length);

    /*
		* @pre: Map created and coordinates given
		* @post: Returns true or false if ship length is correct
		* @param start: starting coordinate
		* @param end: ending coordinate
    * @param length: length of the ship
		* @return: true for corect length, else false
		*/

    bool checkShipPosition(std::string start, std::string end);

    /*
    * @pre: Map created and coordinates given
    * @post: Returns true or false if ship position is correct
    * @param start: starting coordinate
    * @param end: ending coordinate
    * @return: true if boat does not overlap another boat or out of bounds, else false
    */

    void addShip(std::string start, std::string end);

    /*
    * @pre: Map created and coordinates given
    * @post: Boat is placed onto the map
    * @param start: starting coordinate
    * @param end: ending coordinate
    * @return: none
    */

    int charCoordtoIntCoord(char c);

    /*
    * @pre: Map created and coordinates given
    * @post: Returns conversion of A-H to 0-7
    * @param c: Character A-H
    * @return: Int conversion from A-H to 0-7
    */

  public:
    map(int shipNum); //constructor

    /*
    * @pre: Exec object is created
    * @post: Map is created with ships
    * @param shipNum: How many ships are used
    * @return: none
    */

    bool validPos(std::string pos);

    /*
    * @pre: Map created, boats placed, coordinates given
    * @post: Returns if valid position
    * @param pos: Coordinate to check
    * @return: Return true if coordinate valid, else false
    */

    void printEnemyShotMap();

    /*
    * @pre: Map created, boats placed
    * @post: Prints opposite player's map
    * @return: none
    */

    void printCurrentMap();

    /*
    * @pre: Map created, boats placed
    * @post: Prints current player's map
    * @return: none
    */

    void incomingShot(std::string pos);

    /*
    * @pre: Map created, boats placed, coordinates given
    * @post: Updates map to show current game status, prints message if hit, sunk, or missed
    * @param pos: Coordinate to be fired
    * @return: none
    */

    bool gameOver();

    /*
    * @pre: Map created, boats placed
    * @post: Checks if there are any boats left on a map, ends game
    * @return: True if there are no boats, else false
    */

    ~map(); //destructor

    /*
    * @pre: map object is created
    * @post: map object is deleted
    * @return: none
    */

};

#endif
