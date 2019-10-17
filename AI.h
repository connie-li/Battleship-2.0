#ifndef AI_H
#define AI_H
#include <iostream>
#include "Admiral.h"
#include "Grid.h"
#include "Ship.h"
#include "stdlib.h"

using namespace std;

class AI : public Admiral
{
    private: 
        Grid ai_board;	/* a Grid to store the AI's game map. */
    public:
    
    AI();

    /**
     * Returns a random coordinate for usage in exec to fire at a random coordinate
     * @param none
     * @return std::string of the coordinate in the form 1:1
     */
    string randomFiringCoord();

    ~AI();

    /**
     * Returns coordinate to fire in exec based on hard AI
     * @param none
     * @return std::string of the coor in form 1:1
     */
    string hardFire(Grid* board);


};
#endif