#ifndef EASYAI_H
#define EASYAI_H
#include <iostream>
#include "Admiral.h"
#include "Grid.h"
#include "Ship.h"
#include "stdlib.h"
#include <ctype.h>

using namespace std;

class EasyAI : public Admiral
{
    private: 
        //Grid to store the the real players map (so the AI can access it and shoot) 
        Grid* opponentBoard;

    public:
    
    EasyAI();

    /**
     * Returns a random coordinate for usage in exec to fire at a random coordinate
     * @param none
     * @return std::string of the coordinate in the form 1:1
     */
    string fire();

    ~EasyAI();
};
#endif