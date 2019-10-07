#ifndef POWERUPS_H
#define POWERUPS_H
#include <string>
#include <stdexcept>

class PowerUps
{
    private:
    //are we using an enum for the powerup storage (not ptr/array)?

    //pointer for the list of aquired powerups
    char* m_powerUpslist = nullptr;
    int m_size = 0;

    public:

    /**
     * the default constructor that takes no parameters
     * @param none
     */
    PowerUps();
    ~PowerUps();

    /**
     * launches insta-kill torpedo
     */
    void useTorpedo();

    /**
     * reveals locations around the chosen coordinate
     */
    void useRadar();

    /**
     * hits random locations around the map
     */
    void useScatterShot();

    /**
     * seeks the smallest ship and fires upon it
     */
    void useUberCommander();

    /**
     * returns the list of collected powerups to the player
     * @return a list of powerup symbols
     */
    char* getPowerUps();

    /**
     * adds a powerup in the player's arsenal
     * @param char the char symbol used to repesent a specific power up
     */
    void addPowerUp(char symbol);
};
#endif