#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include <iostream>
#include <stdexcept>
#include "Admiral.h"
#include "AI.h"
#include <chrono>

class Executive
{
    private:
        Admiral* m_player1;
        Admiral* m_player2;
        int m_numShips;
        std::chrono::duration<unsigned long long> interval = std::chrono::seconds(2); //their timeout thing



    public:
    Executive();
    ~Executive();

    std::string askCoord();

    void run();

    int setup();

    bool validPos(std::string pos);

    void setNumShips();


};
#endif