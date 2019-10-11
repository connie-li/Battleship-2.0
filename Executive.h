#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include <iostream>
#include <stdexcept>
#include "Admiral.h"
// #include "PowerUps.h"
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
        // PowerUps m_powerups;    /* Contains both players' powerups and methods to use them. */


    public:
    /** A constructor that takes no parameters.
     * @param none
     */
    Executive();

    /** 
     * Destructor that deletes the 2 player Admiral objects
     * @param none
     */
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

    // GAMEPLAY TODOS: (multiple funcs; rename/refactor as necessary)
    // - turn handling func
    // - get firing coord from player
    // - call fire() on that coord to process the other player
    // - update the current player's powerups if necessary (implement later)
    // - cout messages to player

    /** TODO: handles everything necessary to complete one turn, using many of the funcs below
     * call getFireCoord, fire
     * update powerups if necessary
     * call printTurnResult
     *  
     */
    void handleTurn();

    /** Asks the player whether they want to use a powerup.
     * @param player 1 for player 1, 2 for player 2.
     * @return an initial representing the powerup chosen, or N if the player chooses not to use one.
     */
    string askForPowerUp(const int player);

    /** Gets the firing coordinate from the user.
     * @param playerNum the current player turn, 1 for player 1, 2 for player 2.
     * @return a validated coordinate input by the player.
     */
    string askForFireCoord(const int player);

    /** TODO: call Admiral::incomingShot() on the opponent; get whatever it returns
     * @param player a pointer to the current player's Admiral.
     * @param coord the map coordinate to fire on.
     * @post updates the relevant data and alerts the player depending on whether the shot misses, hits a Ship, or finds a powerup.
     */
    void fire(const Admiral* player, const string coord);

    /** Gets the given player's current powerups.
     * @param player 1 for player 1, 2 for player 2.
     * @return a pointer to the array of the player's powerups.
     */
    string* getPowerups(const int player) const;

    /** Adds the given powerup to the current player's powerup vector. [NOT USED YET]
     * @param powerup a string representing the powerup.
     */
    void updatePowerups(const string powerup);

    /** Prints the result of the turn: hit, miss, powerup, etc.
     * @param result represents whether the turn result was a hit, miss, sink, or powerup.
     * @post Prints messages for the current player based on the given result
     */
    void printTurnResult(const string result, const bool wasSunk) const;

    /** Helper function: converts coords from the form "1A" to the form "<row>:<col>".
     * @param orig the original coordinate.
     * @return the coordinate in "<row>:<col>" form.
     */
    string convertCoord(string orig);


};
#endif