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

    cout << "CONSTRUCTOR & COORDS\n";
    Ship* ship5 = new Ship(5);
    delete[] coords;
    coords = new string[5];
    coords[0] = "1:1";
	coords[1] = "1:2";
	coords[2] = "1:3";
	coords[3] = "1:4";
	coords[4] = "1:5";
    ship5->setCoords(coords, 5);
    string* coordPtr = ship5->getCoords();
    cout << "GETTERS\nship5 stats:\n";
    cout << "\tsize: " << ship5->getSize() << '\n';
    cout << "\tcoordinates: ";
    for(int i = 0; i < ship5->getSize(); i++)
    {
        cout << coordPtr[i] << ", ";
    }
    
    cout << "\n\tstatus: " << ship5->getStatus() << '\n';
    cout << "\tnumber of hits: " << ship5->getNumHits() << '\n';

    cout << "SETTERS\n";
    for(int i = 0; i < ship5->getSize(); i++)
    {
        cout << "number of hits: " << ship5->getNumHits() << " -> ";
        ship5->incNumHits();
        cout << ship5->getNumHits() << '\n';
        cout << "status = " << ship5->getStatus() << '\n';
    }

    delete[] coords;
    delete ship1;
    delete ship5;
    return(0);
}
