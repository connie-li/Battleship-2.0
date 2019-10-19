#ifndef HARDAI_H
#define HARDAI_H
#include <iostream>
#include "Admiral.h"
#include "Grid.h"
#include "Ship.h"
#include "stdlib.h"
#include <ctype.h>

using namespace std;

class HardAI : public Admiral
{
    private: 
        //For hard AI
        Admiral* opponent;
        Grid* opponentBoard;

    public:
    
    /**
     * Creates an Hard difficulty AI
     * @param players is a pointer to the real player
     */
    HardAI(Admiral* player);

    /**
     * Empty destructor for EasyAI. Opponent board gets deleted by the player
     * @param none
     */
    ~HardAI();

    /**
     * Returns coordinate to fire in exec based on hard AI
     * @param none
     * @return std::string of the coor in form 1:1
     */
    string fire();

};
#endif