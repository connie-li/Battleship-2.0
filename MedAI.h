#ifndef MEDAI_H
#define MEDAI_H
#include <iostream>
#include "Admiral.h"
#include "Grid.h"
#include "Ship.h"
#include "stdlib.h"
#include <ctype.h>

using namespace std;

class MedAI : public Admiral
{
    private: 
        
        Grid* opponentBoard;
        int counter;
        string prevShot;
        bool hit;
        int prevShipAfloat;
        int direction;
        int current;
        Admiral* opponent;


    public:
    
    MedAI();

    /** the med AI helper function
     * call this in exec if the fire was a hit
     */
    void updateHit(string coor);

    ~MedAI();

    /**
     * Returns coordinate to fire in exec based on hard medium
     * @param none
     * @return std::string of the coor in form 1:1
     */
    string fire();

    string checkDirection();


};
#endif