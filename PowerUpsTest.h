#ifndef POWERUPSTEST_H
#define POWERUPSTEST_H
#include <string>
#include <iostream>
#include "Test.h"
#include "PowerUps.h"

class PowerUpsTest: protected Test{
private:
    //private methods
    /**
     * Tests using the Torpedo powerup
     * @return bool: If true, success. If false, failure.
     */
    bool testTorpedo();
    
    /**
     * Tests using the Radar powerup
     * @return bool: If true, success. If false, failure.
     */
    bool testRadar();

    /**
     * Tests using the ScatterShot powerup
     * @return bool: If true, success. If false, failure.
     */
    bool testScatter();

    /**
     * Tests using the UberCommander powerup
     * @return bool: If true, success. If false, failure.
     */
    bool testUber();

    /**
     * Tests getting the vector of powerups
     * @return bool: If true, success. If false, failure.
     */
    bool testGetPwrUps();

    /**
     * Tests adding a powerup to the vector list
     * @return bool: If true, success. If false, failure.
     */
    bool testAddPwrUp();

    /**
     * Tests removing a powerup from the list
     * @return bool: If true, success. If false, failure.
     */
    bool testRmPwrUp();

    /**
     * Tests whether or not a player has a powerup
     * @return bool: If true, success. If false, failure.
     */
    bool testHasPwrUp();


public:

    /**
     * Tests the PowerUps class
     */
    PowerUpsTest();

    /**
     * runs all the test functions for PowerUps
     */
    void run();

    /**
     * Takes care of cleanup
     */
    ~PowerUpsTest();

};
#endif