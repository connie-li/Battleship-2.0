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
    
    /**
     * Creates an Easy difficulty AI
     * @param grid is a Grid object for the real player
     */
    EasyAI(Grid* grid);

    /**
     * Returns a random coordinate for usage in exec to fire at a random coordinate
     * @param none
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
     * @param none
     */
    ~EasyAI();
};
#endif