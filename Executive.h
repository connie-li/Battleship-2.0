#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include <iostream>
#include <stdexcept>
#include "Admiral.h"
// #include "AI.h"
#include <chrono>
using namespace std;

class Executive
{
    private:
        Admiral* m_player1; //Admiral object for player 1
        Admiral* m_player2; //Admiral object for player 2
        int m_numShips; //int of the number of ships used in the game
        std::chrono::duration<unsigned long long> interval = std::chrono::seconds(2); //their timeout thing



    public:
    /** A constructor that takes no parameters.
     * @param none
     */
    Executive();

    /** 
     * Destructor that deletes the 2 player Admiral objects
     * @param none
     */
    Executive();

    
    ~Executive();

    /**
     * Asks for a coordinate from the user in the form 1A. Checks the input to make sure it is 
     * valid on the board size 8x8 and in the correct syntax. 
     * @param none
     * @return std::string of the coordinate in the form 1A
     */
    std::string askCoord();

    /**
     * Places ships for a user. Asking the user the coordinate from the beginning, then displays the possible 
     * ending coordinates for the user. Then asks the user to input one of the ending coordinate from list. 
     * @param size is an int for the length of the ship being placed
     * @param player is an Admiral object for the player placing ship
     * @param AI true if player is AI (don't interact with user)
     * @return none
     * @post sends a string array of the coordinates of the ship to Admiral
     */
    void placeShip(int size, Admiral* player, bool AI);

    /**
     * Runs the Battleship game
     * @param none
     * @return none
     */
    void run();

    /**
     * Runs the menu for the game
     * @param none
     * @return int of the user's selection on the menu
     * 1 start game or
     * 3 quit
     */
    int setup();

    /**
     * Translates a letter coordinate to a number coordinate
     * Only works for letters A-H
     * @param char c is the character of the letter you are changing to an int
     * @return int of the number equivalent
     */
    int charCoordtoIntCoord(char c);

    /**
     * Evaluates a coordinate and returns if it is valid or not
     * @param pos is a string of the coordinate in the form 1A
     * @return true if the position is valid on the 8x8 board
     */
    bool validPos(std::string pos);

    /**
     * Asks and sets the number of ships used for the game
     * @param none
     * @return none
     * @post sets the m_numShips to the number obtained from user
     */
    void setNumShips();


};
#endif