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
    
    /**
     * Creates an Medium difficulty AI
     * @param grid is a Grid object for the real player
     */
    MedAI();


    void updateHit(string coor);


    /**
     * Empty destructor for EasyAI. Opponent board gets deleted by the player
     * @param none
     */
    ~MedAI();

    /**
     * Returns coordinate to fire in exec based on medium AI
     * Fires randomly until a hit, then fires orthogonally
     * @param none
     * @return std::string of the coor in form 1:1
     */
    string fire();

    /**
     * Helper function that creates a random coordinate to fire on
     * Sets the direction orientation for the ship if it is a hit
     * @param none
     */
    string checkDirection();


};
#endif