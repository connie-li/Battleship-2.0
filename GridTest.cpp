#include "GridTest.h"

GridTest::GridTest(){
    cout<< "Starting Grid Test\n";
}

void GridTest::run(){
    Test::testFunc("Testing Location: ", (Test::func) testLocRet());
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

    if(hasPassed == 1){ 
       return 1; 
    }
    return 0;
}

bool testRand();
bool testPrint();
bool testRead();