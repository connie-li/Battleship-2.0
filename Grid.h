#ifndef GRID_H
#define GRID_H
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Grid{
private:
    const int m_BOARD_SIZE = 8; /** The size of the board to be created.*/
    string m_center;            /** The center or upper left corner of the center of the board based on the size*/ 
    string** m_arr;             /** The array representing the board.*/

    /**
     * Returns the column given a "#:#" format string
     * @param coord: Intakes a string in the "#:#" format and determines the coordinates.
     */
    int colCoor(const string coord);

    /**
     * Returns the row given a "#:#" format string
     * @param coord: Intakes a string in the "#:#" format and determines the coordinates.
     */
    int rowCoor(const string coord);

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
    string getCoor(const string coord);

    /**
     * Sets the value at a given coordinate pair.
     * @param coord: Intakes a string in the "#:#" format and determines the coordinates.
     * @param value: The given value to set the locations value to.
     */
    void setCoor(const string coord, const string value);

    /**
     * Returns a random coordinate from the grid.
     * @param allowOcc: If true, allowd for randCoor to include occupied(nonwater) coordinates. 
     *      If false, ignores occupied coordinates.
     * @return string: Returns the a coordinate string in the form "#:#".
     */
    string randCoor(const bool allowOcc);

    /**
     * Prints the grind to the console.
     * @param isFiring: If true, prints a firing grid. If false, prints a ship grid.
     */
    void printGrid(const bool isFiring);

    /**
     * Reads in an array of ship coordinates and sets those coordinates to the ship value
     * @param arr: An array of string coordinates in "#:#" format
     * @param length the length of the array of coordinates
     */
    void readShip(const string* arr, const int length);

    /**
     * Creates an string array of a give n by n size at the center location. If the given array 
     *      would write off of the grid the cells are populated with an *.
     * @param arr: A pointer to the arr to be created.
     * @param size (Optional): determines the size of the grid to return.
     * @param center (Optional): gives the center location of the array if it is an odd number. 
     *      If it is even it must be the upper left corner of the cell intersection.
     */
    void getPartialGrid(string** &arr, int size = -1, string center = "-1:-1");

    /**
     * Intakes an array and populates the grid.
     * @param arr: An array of strings that will be the content in grid.
     */
    void readGrid(string** arr);

    /**
     * Destroys a Grid object.
     */
    ~Grid();
};
#endif