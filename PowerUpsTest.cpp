#include "PowerUpsTest.h"

PowerUpsTest::PowerUpsTest(){
    cout << "Starting PowerUps Test\n";
}

void PowerUpsTest::run(){
    testFunc("Testing Get, Add, Rm , and Has: ", (Test::func) testGetAddRmHas());
    testFunc("Testing Torpedo: ", (Test::func) testTorpedo());
    testFunc("Testing Radar: ", (Test::func) testRadar());
    testFunc("Testing Scattershot: ", (Test::func) testScatter());
    testFunc("Testing Ubercommander: ", (Test::func) testUber());

    
}

PowerUpsTest::PowerUpsTest(){
    cout << "PowerUps Testing Complete";
}

bool PowerUpsTest::testGetAddRmHas(){
    bool hasPassed = 1;
    try{
        cout << "Adding a Power Up";
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
        cout << "Has a Powerup?";
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
    

}

bool PowerUpsTest::testTorpedo(){
    bool hasPassed = 1;
}