// SHIP TESTING

#include "Ship.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    Ship* ship1 = new Ship(1);
    string* coords = new string[1];
    coords[0] = "1:1";
    ship1->setCoords(coords, 1);

    Ship* ship5 = new Ship(5);
    delete[] coords;
    coords = new string[5];
    coords[0] = "1:1";
	coords[1] = "1:2";
	coords[2] = "1:3";
	coords[3] = "1:4";
	coords[4] = "1:5";
    cout << coords << '\n';
    ship5->setCoords(coords, 5);

    delete[] coords;
    delete ship1;
    delete ship5;
    return(0);
}
