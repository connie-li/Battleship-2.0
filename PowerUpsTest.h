#ifndef POWERUPSTEST_H
#define POWERUPSTEST_H
#include <string>
#include <iostream>
#include "Test.h"
#include "PowerUps.h"

class PowerUpsTest: protected Test{
private:
    PowerUps m_PowerUps;
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
     * tests getting, adding, removing, and if player has powerups
     */
    bool testGetAddRmHas();

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