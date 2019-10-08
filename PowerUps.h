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
     */
    void useTorpedo(std::string coord, bool isPlayer1);

    /**
     * reveals locations around the chosen coordinate
     * @param string coordinate to use the powerup on
     */
    void useRadar(std::string coord);

    /**
     * hits random locations around the map
     * @param string coordinate to use the powerup on
     */
    void useScatterShot(std::string coord);

    /**
     * seeks the smallest ship and fires upon it
     * @param string coordinate to use the powerup on
     */
    void useUberCommander(std::string coord);

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