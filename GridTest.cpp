#include "GridTest.h"

GridTest::GridTest(){
    cout<< "Creating Grid Test\n";
}

void GridTest::run(){
    cout<< "Starting Grid Test\n";
    testFunc("Testing Location: ", (func) testLocRet());
    testFunc("Testing Random: ", (func) testRand());
    testFunc("Testing Read Ship: ", (func)testRead());
    testFunc("Testing Particular Grid: ", (func) testParticularGrid());
    testFunc("Testing Printing: ", (func) testPrint());
}

bool GridTest::testLocRet(){
    bool hasPassed = 1;
    try{
        cout<<"\t\tSetting Coordinate: ";
        m_grid.setCoor("7:7", "O");
        cout<< pass;
    }catch(exception){
        hasPassed = 0;
        cout<< fail;
    }
    try{
        cout<<"\t\tGetting Coordinate: ";
        if(m_grid.getCoor("7:7") == "O"){
            cout<< pass;
        }else{
            cout<< unkno;
        }
    }catch(exception){
        hasPassed = 0;
        cout<< fail;
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
        if((stoi(temp.substr(0, 1)) <= M_BOARD_SIZE && stoi(temp.substr(2)) <= M_BOARD_SIZE) && (stoi(temp.substr(0, 1)) > 0 && stoi(temp.substr(2)) > 0)){
            cout<< pass;
        }else{
            cout<< unkno;
        }
    }catch(exception){
        hasPassed = 0;
        cout<< fail;
    }
    try{
        cout<<"\t\tPartially Rand Coord: ";
        temp = m_grid.randCoor(true);
        if((stoi(temp.substr(0, 1)) <= M_BOARD_SIZE && stoi(temp.substr(2)) <= M_BOARD_SIZE) && (stoi(temp.substr(0, 1)) > 0 && stoi(temp.substr(2)) > 0)){
            if(m_grid.getCoor(temp) != "~"){
                cout<<m_grid.getCoor(temp);
                cout<< fail;
            }else{
                cout<< pass;
            }
        }else{
            cout<< unkno;
        }
    }catch(exception){
        hasPassed = 0;
        cout<< fail;
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
        cout<< fail;
    }
    try{
        cout<<"\t\tTested Fire Grid: \n";
        m_grid.printGrid(true);
        cout<<pass;
    }catch(exception){
        hasPassed = 0;
        cout<< fail;
    }
    return hasPassed;
}

bool GridTest::testRead(){
    bool hasPassed = 1;
    int arrLength = 3;
    string size = to_string(arrLength);
    string arr[3] = {"1:1", "1:2", "1:3"};
    try{
        bool isUnknown = 0;
        cout<< "\t\tChecking Ship Creation: ";
        m_grid.readShip(arr, arrLength);
        for(int i = 0; i < arrLength; i++){
            if(m_grid.getCoor(arr[i]) != size){
                isUnknown = 1;
                break;
            }
        }
        if(!isUnknown){
            cout<<pass;
        }else{
            hasPassed = 0;
            cout<<unkno;
        }
    }catch(exception){
        hasPassed = 0;
        cout<<fail;
    }
    return hasPassed;
}

bool GridTest::testParticularGrid(){
    string** arr = nullptr;
    int size = 3;
    string center = "7:6";
    
    //Partial
    try{
        cout<< "\t\tTesting Partial Retrieval: ";
        m_grid.getPartialGrid(arr, size, center);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                cout << arr[i][j] << "\t";
            }
            cout<<"\n";
        }
        cout<< pass;
    }catch(exception){
        cout<< fail;
    }
    for(int i = 0; i < size; i++){
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;

    //Full
    try{
        size = 8;
        cout<< "\t\tTesting Full Retrieval: ";
        m_grid.getPartialGrid(arr);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                cout << arr[i][j] << "\t";
            }
            cout<<"\n";
        }
        cout<< pass;
    }catch(exception){
        cout<< fail;
    }
    for(int i = 0; i < size; i++){
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;
}