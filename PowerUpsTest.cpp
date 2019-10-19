#include "PowerUpsTest.h"

PowerUpsTest::PowerUpsTest(){
    std::cout << "Creating PowerUpsTest Object\n";
}

void PowerUpsTest::run(){
    std::cout << "Starting PowerUps Testing\n";
    testFunc("Testing Get, Add, Rm , and Has: ", (Test::func) testGetAddRmHas());
    testFunc("Testing Torpedo: ", (Test::func) testTorpedo());
    testFunc("Testing Radar: ", (Test::func) testRadar());
    testFunc("Testing Scattershot: ", (Test::func) testScatter());
    testFunc("Testing Ubercommander: ", (Test::func) testUber());
}

PowerUpsTest::~PowerUpsTest(){
    cout << "PowerUps Testing Complete\n";
}

bool PowerUpsTest::testGetAddRmHas(){
    bool hasPassed = 1;
    try{
        cout << "Adding a Power Up: ";
        m_PowerUps.addPowerUp("T",true);
        m_PowerUps.addPowerUp("R",true);
        m_PowerUps.addPowerUp("S",true);
        m_PowerUps.addPowerUp("U",true);
        cout << pass;
    }catch(exception){
        hasPassed = 0;
        cout << fail;
    }
    try{
        cout << "Has a Powerup?\n";
        bool temp1= m_PowerUps.hasAPowerup(true);
        bool temp2 = m_PowerUps.hasAPowerup(false);
        if(temp1 == false || temp2 == true){
            hasPassed = 0;
            cout << fail;
        }
    }catch(exception){
        hasPassed = 0;
        cout << fail;
    }
    try{
        cout << "Getting Power Ups: ";
        vector<string> tempUps= m_PowerUps.getPowerUps(true);
        vector<string> tempUps2= m_PowerUps.getPowerUps(false);
        cout << pass;

    }catch(exception){
        hasPassed = 0;
        cout << fail;
    }    
    try{
        cout << "Removing PowerUps Admiral1: ";
        m_PowerUps.removePowerUp("T",true);
        m_PowerUps.removePowerUp("R",true);
        m_PowerUps.removePowerUp("S",true);
        m_PowerUps.removePowerUp("U",true);
        cout << pass;
        cout << "Removing Powerups Admiral2: ";
        m_PowerUps.removePowerUp("T",false);
        cout << pass;

    }catch(exception){
        hasPassed = 0;
        cout << fail;
    }

    return(hasPassed);
}

bool PowerUpsTest::testTorpedo(){
    bool hasPassed = 1;
    return(true);
}

bool PowerUpsTest::testRadar(){
    bool hasPassed =1;
    return(true);
}

bool PowerUpsTest::testScatter(){
    bool hasPassed = 1;
    return(true);
}

bool PowerUpsTest::testUber(){
    bool hasPassed = 1;
    return(true);
}