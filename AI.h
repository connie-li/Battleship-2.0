#ifndef AI_H
#define AI_H
#include <iostream>
#include "Admiral.h"
#include "Grid.h"
#include "Ship.h"
#include "stdlib.h"
#include <ctype.h>

using namespace std;

class AI : public Admiral
{
    private: 
        /* a Grid to store the the real players map (so the AI can access it and shoot) */
        Grid* opponentBoard;

        //for the med AI
        string* medAI_arr; //keeps track of hits
        int counter;
        bool hit;


    public:
    
    AI();

    /** the med AI helper function
     * call this in exec if the fire was a hit
     */
    void updateHit();

    /**
     * Returns a random coordinate for usage in exec to fire at a random coordinate
     * @param none
     * @return std::string of the coordinate in the form 1:1
     */
    string easyFire();

    ~AI();

    /**
     * Returns coordinate to fire in exec based on hard AI
     * @param none
     * @return std::string of the coor in form 1:1
     */
    string hardFire();


    /**
     * Returns coordinate to fire in exec based on hard medium
     * @param none
     * @return std::string of the coor in form 1:1
     */
    string medFire();


};
#endif