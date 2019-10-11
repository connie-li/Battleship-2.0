#include "GridTest.h"

GridTest::GridTest(){
    cout<< "Starting Grid Test\n";
}

void GridTest::run(){
    Test::testFunc("Testing Location: ", (Test::func) testLocRet());
    Test::testFunc("Testing Random: ", (Test::func) testRand());
}

bool GridTest::testLocRet(){
    bool hasPassed = 1;
    try{
        cout<<"\t\tSetting Coordinate: ";
        m_grid.setCoor("1:1", ":-)");
        cout<< Test::pass;
    }catch(exception){
        hasPassed = 0;
        cout<< Test::fail;
    }
    try{
        cout<<"\t\tGetting Coordinate: ";
        if(m_grid.getCoor("1:1") == ":-)"){
            cout<< Test::pass;
        }else{
            cout<< Test::unkno;
        }
    }catch(exception){
        hasPassed = 0;
        cout<< Test::fail;
    }

    return hasPassed;
}

bool GridTest::testRand(){
    bool hasPassed = 1;
    string temp = "\0";
    try{
        cout<<"\t\tCompletely Rand Coord: ";
        temp = m_grid.randCoor(false);
        if((stoi(temp.substr(0, 1)) < M_BOARD_SIZE && stoi(temp.substr(2)) < M_BOARD_SIZE) && (stoi(temp.substr(0, 1)) < 0 && stoi(temp.substr(2)) < 0)){
            cout<< pass;
        }else{
            cout<< unkno;
        }
    }catch(exception){
        hasPassed = 0;
        cout<< Test::fail;
    }
    try{
        cout<<"\t\tPartially Rand Coord: ";
        temp = m_grid.randCoor(true);
        if(stoi(temp.substr(0, 1)) < M_BOARD_SIZE && stoi(temp.substr(2)) < M_BOARD_SIZE){
            cout<< pass;
        }else{
            cout<< unkno;
        }
        if(m_grid.getCoor(temp) != "~"){
            cout<< fail;
        }else{
            cout<< pass;
        }
    }catch(exception){
        hasPassed = 0;
        cout<< Test::fail;
    }

    return hasPassed;
}

bool GridTest::testPrint(){
    try{

    }catch(exception){
        
    }
}

bool GridTest::testRead(){

}