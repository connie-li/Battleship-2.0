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

    public:
    

    HardAI();


    ~HardAI();

    /**
     * Returns coordinate to fire in exec based on hard AI
     * @param none
     * @return std::string of the coor in form 1:1
     */
    string fire();

};
#endif