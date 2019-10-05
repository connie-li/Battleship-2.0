#ifndef GRID_H
#define GRID_H
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class Grid{
private:
    const int m_BOARD_SIZE = 8; /** The size of the board to be created.*/
    string** m_arr;             /** The array representing the board.*/

    /**
     * Returns the column given a "#:#" format string
     * @param coord: Intakes a string in the "#:#" format and determines the coordinates.
     */
    int colCoor(string coord);

    /**
     * Returns the row given a "#:#" format string
     * @param coord: Intakes a string in the "#:#" format and determines the coordinates.
     */
    int rowCoor(string coord);

    /**
     * Prints a firing map or a map that only shows hits and misses
     */
    void printFiring();

    /**
     * Prints a map that shows ships, hits, and misses
     */
    void printShip();
public:
    
    /**
     * Creates a new grid object.
     */
    Grid();

    /**
     * Returns the value at given coordinate pair.
     * @param coord: Intakes a string in the "#:#" format and determines the coordinates.
     * @return string: returns the value at a given coordinate without any modifiers.
     */
    string getCoor(string coord);

    /**
     * Sets the value at a given coordinate pair.
     * @param coord: Intakes a string in the "#:#" format and determines the coordinates.
     * @param value: The given value to set the locations value to.
     */
    void setCoor(string coord, string value);

    /**
     * Returns a random coordinate from the grid.
     * @param allowOcc: If true, allowd for randCoor to include occupied(nonwater) coordinates. 
     *      If false, ignores occupied coordinates.
     */
    string randCoor(bool allowOcc);

    /**
     * Prints the grind to the console.
     * @param isFiring: If true, prints a firing grid. If false, prints a ship grid.
     */
    void printGrid(bool isFiring);

    /**
     * Reads in an array of ship coordinates and sets those coordinates to the ship value
     * @param arr: An array of string coordinates in "#:#" format
     */
    void readShip(string* arr, int length);

    /**
     * Destroys a Grid object.
     */
    ~Grid();
};

#endif