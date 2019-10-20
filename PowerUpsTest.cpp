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
    delete m_tempAdmir;
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
    string* tempCoords = new string[3];
    tempCoords[0] = "1:1";
    tempCoords[1] ="1:2";
    tempCoords[2] = "1:3";
    
    try{
        createAdmiral("T", 1);
        m_tempAdmir->addShip(3, tempCoords);

        cout << "Firing on top coordinate: ";
        m_PowerUps.useTorpedo("1:1", true, 3, tempCoords);
        cout << pass;
        delete m_tempAdmir;

    }catch(exception){
        hasPassed = 0;
        cout << fail;
    }
    try{
        createAdmiral("T", 1);
        m_tempAdmir->addShip(3, tempCoords);

        cout << "Firing on middle coordinate: ";
        m_PowerUps.useTorpedo("1:2",true,3,tempCoords);
        cout << pass;
        delete m_tempAdmir;

    }catch(exception){
        hasPassed = 0;
        cout << fail;
    }
    try{
        createAdmiral("T", 1);
        m_tempAdmir->addShip(3, tempCoords);

        cout << "Firing on bottom coordinate: ";
        m_PowerUps.useTorpedo("1:3",true,3,tempCoords);
        cout << pass;
        delete m_tempAdmir;

    }catch(exception){
        hasPassed = 0;
        cout << fail;
    }

    delete[] tempCoords;
    
    return(hasPassed);
}

bool PowerUpsTest::testRadar(){
    bool hasPassed =1;

    return(true);
}

bool PowerUpsTest::testScatter(){
    bool hasPassed = 1;
    string* tempCoords = new string[3];
    tempCoords[0] = "1:1";
    tempCoords[1] ="1:2";
    tempCoords[2] = "1:3";
    try{
        createAdmiral("S", 1);
        m_tempAdmir->addShip(3, tempCoords);
        cout<< "Firing Scattershot: ";
        m_PowerUps.useScatterShot(true);
        m_tempAdmir->getBoard()->printGrid(false);
        cout<<pass;
    }catch(exception){
        hasPassed = 0;
        cout<< fail;
    }
    return(hasPassed);
}

bool PowerUpsTest::testUber(){
    bool hasPassed = 1;
    string* tempCoords1 = new string[1];
    tempCoords1[0] = "2:1";
    string* tempCoords2 = new string[2];
    tempCoords2[0] = "1:1";
    tempCoords2[1] ="1:2";

  

    //testing if uber fires on the smallest ship
    try{
        createAdmiral("U", 2);
        m_tempAdmir->addShip(1, tempCoords1);
        m_tempAdmir->addShip(2,tempCoords2);

        std::cout << "Firing on the smallest ship: ";
        m_PowerUps.useUberCommander("1:1",true);
        if(m_tempAdmir->getBoard()->getCoor("2:1")=="X"){
            cout << pass;
        }
        else{
            cout << unkno;
        }
        
    }catch(exception e){
        
        hasPassed = 0;
        cout << fail;
    }
    
    delete[] tempCoords1;
    delete[] tempCoords2;

    return(hasPassed);
}

void PowerUpsTest::createAdmiral(string powerup, int ships){
    m_tempAdmir = new Admiral(ships);
    m_PowerUps.addPowerUp(powerup,true);
    m_PowerUps.setAdmirals(m_tempAdmir,m_tempAdmir);
}

void PowerUpsTest::deleteAdmiral(){
    if(m_tempAdmir != nullptr){
        delete m_tempAdmir; 
    }
    
}