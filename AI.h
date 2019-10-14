#ifndef AI_H
#define AI_H
#include <iostream>
#include "Admiral.h"
#include "Grid.h"
#include "Ship.h"
#include "stdlib.h"

class AI : public Admiral
{
    private: 
        Grid ai_board;	/* a Grid to store the AI's game map. */
    public:
    
    AI();

    /**
     * Returns a random coordinate for usage in exec to fire at a random coordinate
     * @param none
     * @return std::string of the coordinate in the form 1A
     */
    string randomFiringCoord();

    ~AI();


};
#endif