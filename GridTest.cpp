#include "GridTest.h"

GridTest::GridTest(){
    cout<< "Starting Grid Test\n";
}

void GridTest::run(){
    Test::testFunc("Testing Location: ", (Test::func) testLocRet());
    Test::testFunc("Testing Random: ", (Test::func) testRand());
    Test::testFunc("Testing Read Ship: ", (Test::func)testRead());
    Test::testFunc("Testing Printing: ", (Test::func) testPrint());
}

bool GridTest::testLocRet(){
    bool hasPassed = 1;
    try{
        cout<<"\t\tSetting Coordinate: ";
        m_grid.setCoor("1:1", "X");
        cout<< Test::pass;
    }catch(exception){
        hasPassed = 0;
        cout<< Test::fail;
    }
    try{
        cout<<"\t\tGetting Coordinate: ";
        if(m_grid.getCoor("1:1") == "X"){
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

GridTest::~GridTest(){
    cout<<"GridTesting Complete\n";
}

bool GridTest::testRand(){
    bool hasPassed = 1;
    string temp = "\0";
    try{
        cout<<"\t\tCompletely Rand Coord: ";
        temp = m_grid.randCoor(false);
        cout<<"\n\n" << temp <<"\n\n";
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
    bool hasPassed = 1;
    try{
        cout<< "\t\tTested Ship Grid: \n";
        m_grid.printGrid(false);
        cout<<pass;
    }catch(exception){
        hasPassed = 0;
        cout<< Test::fail;
    }
    try{
        cout<<"\t\tTested Fire Grid: \n";
        m_grid.printGrid(true);
        cout<<pass;
    }catch(exception){
        hasPassed = 0;
        cout<< Test::fail;
    }
    return hasPassed;
}

bool GridTest::testRead(){
    bool hasPassed = 1;
    string arr[3] = {"1:1", "1:2", "1:3"};
    try{
        cout<< "\t\tChecking Ship Creation: ";
        m_grid.readShip(arr, 3);
        if(m_grid.getCoor("1:1") == "3" && m_grid.getCoor("2:2") == "3" && m_grid.getCoor("3:3") == "3"){
            cout<<pass;
        }else{
            hasPassed = 0;
            cout<<unkno;
            cout<< m_grid.getCoor("1:1");
        }
    }catch(exception){
        hasPassed = 0;
        cout<<fail;
    }
    return hasPassed;
}