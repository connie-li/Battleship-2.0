#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include <iostream>
#include <stdexcept>
#include "Admiral.h"
// #include "AI.h"
#include <chrono>
using namespace std;

class Executive
{
    private:
        Admiral* m_player1;
        Admiral* m_player2;
        int m_numShips;
        std::chrono::duration<unsigned long long> interval = std::chrono::seconds(2); //their timeout thing



    public:
    /** A constructor that takes no parameters.
     *
     */
    Executive();
    ~Executive();

    std::string askCoord();

    void placeShip(int size, Admiral player);
    void run();

    int setup();

    int charCoordtoIntCoord(char c);

    bool validPos(std::string pos);

    void setNumShips();


};
#endif