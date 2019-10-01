#ifndef GRID_H
#define GRID_H
#include <string>
#include <iostream>
using namespace std;

class Grid{
    private:
        const int m_BOARD_SIZE = 8;
        string** m_arr;

        int colCoor(string coord);

        int rowCoor(string coord);

        void printFiring();

        void printShip();
    public:
        Grid();

        string getCoor(string coord);

        void setCoor(string coord, string value);

        string randCoor(bool allowOcc);

        void printGrid(bool isFiring);

        ~Grid();
};

#endif