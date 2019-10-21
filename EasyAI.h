#ifndef EASYAI_H
#define EASYAI_H
#include <iostream>
#include "Admiral.h"
#include "Grid.h"
#include "Ship.h"
#include "stdlib.h"
#include <ctype.h>

using namespace std;

/**
 * Class definition for an Easy difficulty AI object, which inherits from Admiral.
 */
class EasyAI : public Admiral
{
    private: 
        //Grid to store the the real players map (so the AI can access it and shoot) 
        Grid* opponentBoard;

    public:
    
    /** Constructor for an Easy difficulty AI with 1 parameter.
     * @param grid is a pointer to the opponent player's Grid.
     * @post creates an Easy difficulty AI object.
     */
    EasyAI(Grid* grid);

    /** Constructor for an Easy difficulty AI with 2 parameters.
     * @param grid is a pointer to the opponent player's Grid.
     * @param numShips the number of Ships the AI will have.
     */
    EasyAI(Grid* grid, int numShips);

    /**
     * Returns a random coordinate for usage in exec to fire at a random coordinate
     * @return std::string of the coordinate in the form 1:1
     */
    string fire();

    /**
     * Sets the opponent's grid pointer to grid
     * @param grid is the Grid object
     */
    void setGrid(Grid* grid);

    /**
     * Returns the Grid object that the EasyAI is referencing
     * @return returns opponentBoard
     */
    Grid* getGrid();

    /**
     * Empty destructor for EasyAI. Opponent board gets deleted by the player
     */
    ~EasyAI();
};
#endif