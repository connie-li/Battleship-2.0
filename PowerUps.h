#ifndef POWERUPS_H
#define POWERUPS_H
#include <string>
#include <stdexcept>
#include "Grid.h"
#include <ctype.h>
#include "Ship.h"

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
    
    Grid* m_admir1Map = nullptr;
    Grid* m_admir2Map = nullptr;

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
     */
    Grid* mapPicker(bool isPlayer1);

    /**
     * returns the list of collected powerups to the player
     * @return a list of powerup symbols
     */
    string* getPowerUps();

    /**
     * adds a powerup in the player's arsenal
     * @param char the char symbol used to repesent a specific power up
     */
    void addPowerUp(char symbol);

    /**
     * removes the given powerup from the list
     * @param char the symbol of the powerup to be removed
     */
    
    void removePowerUp(char symbol);
};
#endif