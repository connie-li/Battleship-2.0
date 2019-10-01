#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include <iostream>
#include <stdexcept>
#include "Admiral.h"
#include "AI.h"

class Executive
{
    private:
        Admiral* m_player1;
        Admiral* m_player2;
        int m_numShips;


    public:
    Executive();
    ~Executive();

    std::string askCoord();

    void run();

    void setup();

    void setNumShips();


};
#endif