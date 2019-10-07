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
        Admiral* m_player1; //Player 1
        Admiral* m_player2; //player 2 
        int m_numShips; //the number of ships the players are using in the game
        std::chrono::duration<unsigned long long> interval = std::chrono::seconds(2); //their timeout thing



    public:
    /** A constructor that takes no parameters.
     * @param = none
     */
    Executive();

    
    ~Executive();

    std::string askCoord();

    void placeShip(int size, Admiral* player);
    void run();

    int setup();

    int charCoordtoIntCoord(char c);

    bool validPos(std::string pos);

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

    /** TODO: I/O, gets the firing coordinate from the user
     *
     */
    string getFireCoord();

    /** TODO: call Admiral::incomingShot() on the opponent; get whatever it returns
     *
     */
    void fire(string coord);

    /** Adds the given powerup to the current player's powerup vector. [NOT USED YET]
     * @param powerup a string representing the powerup.
     */
    void updatePowerups(const string powerup);

    /** Prints the result of the turn: hit, miss, powerup, etc.
     * @param result represents whether the turn result was a hit, miss, or powerup.
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