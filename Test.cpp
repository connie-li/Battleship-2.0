#include "Test.h"

Test::Test(){

}

void Test::testFunc(string write, func testFunction){
    cout << "\t" <<write;
    if(testFunction){
        cout << "\t" << pass;
    }else{
        cout << "\t" << fail;
    }
}