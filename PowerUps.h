#ifndef POWERUPS_H
#define POWERUPS_H
#include <string>
#include <stdexcept>
#include "Admiral.h"
#include <ctype.h>
#include <vector>
#include <iostream>
using namespace std;
class PowerUps
{
    private:
    //are we using an enum for the powerup storage (not ptr/array)?
    /*
    T = torpedo
    R = radar
    U = uber commander
    S = scattershot
    */

    //pointer for the list of aquired powerups
    
    Admiral* m_admir1 = nullptr;
    Admiral* m_admir2 = nullptr;
    vector<string> m_admir1Powerups;
    vector<string> m_admir2Powerups;

    public:
    /**
     * the default constructor that takes no parameters
     * @param none
     */
    PowerUps();
    ~PowerUps();

    /**
     * launches insta-kill torpedo
     * @param string coordinate to use the powerup on
     * @param bool isPlayer1 true if player1 false if player2
     * @param int shipSize size of the ship, -1 if there is no ship at this coord
     * @param string* shipCoords list of ship coordinates
     */
    void useTorpedo(std::string coord, bool isPlayer1, int shipSize, string* shipCoords);

    /**
     * reveals locations around the chosen coordinate
     * @param string coordinate to use the powerup on
     * @param bool true if player1 false if player2
     */
    void useRadar(std::string coord,bool isPlayer1);

    /**
     * hits random locations around the map
     * @param string coordinate to use the powerup on
     * @param bool true if player1 false if player2
     */
    void useScatterShot(std::string coord,bool isPlayer1);

    /**
     * seeks the smallest ship and fires upon it
     * @param string coordinate to use the powerup on
     * @param bool true if player1 false if player2
     */
    void useUberCommander(std::string coord,bool isPlayer1);

    /**
     * chooses which map should be handed to the function
     * @param bool true if player1's turn, false if player2
     * @return Grid the grid owned by the other admiral (to fire upon)
     */
    Grid* mapPicker(bool isPlayer1);

    /** Gets the given player's powerups.
     * @param player 1 for player 1, 2 for player 2.
     * @return a pointer to the vector of powerup symbols.
     */
    vector<string> getPowerUps(const int player) const;

    /**
     * adds a powerup to the correct admiral's powerups vector
     * @param string the string value of the powerup
     * @param bool isPlayer1 true if player1 false if player2 
     */
    void addPowerUp(std::string value, bool isPlayer1);

    /**
     * removes the given powerup from the vector
     * @param string the string value of the powerup to be removed
     * @param bool isPlayer1 true if player1 false if player2
     */
    
    void removePowerUp(std::string value, bool isPlayer1);

    /**
     * Return  numeric equivalent of a letter column
     * @param c is the character letter
     * @return int equivalent (1-8)
     */
    int charCoordtoIntCoord(char c);

    /**
     * figures out whether the player has any powerups
     * @param isPlayer1 true if player1, false if player2
     * @return true if player has a powerup, false if they don't
     * */
    bool hasAPowerup(bool isPlayer1);
};
#endif