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


    public:
    /** Constructor for a Medium difficulty AI with 1 parameter.
     * @param grid is a Grid object for the real player
     * @post Creates an Medium difficulty AI.
     */
    MedAI(Grid* grid);

    /** Constructor for a Medium difficulty AI with 2 parameters.
     * @param grid is a Grid object for the real player
     * @param numShips the number of Ships the AI object will have.
     * @post Creates an Medium difficulty AI.
     */
    MedAI(Grid* grid, int numShips);

    /**
     * Empty destructor for EasyAI. Opponent board gets deleted by the player
     */
    ~MedAI();

    /**
     * Returns coordinate to fire in exec based on medium AI
     * Fires randomly until a hit, then fires orthogonally
     * @return std::string of the coor in form 1:1
     */
    string fire();

    /**
     * Helper function that creates a random coordinate to fire on
     * Sets the direction orientation for the ship if it is a hit
     */
    string checkDirection();


    /**
     * Function to be called/used in Exec when there is a miss registered after a hit
     * i.e. a ship was found, and the AI then guessed got a miss (wrong direction)
     * This is to switch the direction of shots if an initial hit was in the middle of a ship
     * @post reverses direction of firing
     */
    void updateMiss();


};
#endif