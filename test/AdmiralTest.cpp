// ADMIRAL & SHIP TESTING

#include "Admiral.h"
#include <iostream>
#include <string>
using namespace std;

string* generateCoords(string startCoord, int size, bool orientation)
{
	string* coordsArr = new string[size];
	// parse startCoord
	int row = stoi(startCoord.substr(0, 1), nullptr, 10);
	int col = stoi(startCoord.substr(2, 1), nullptr, 10);

	if(orientation)		// horizontal
	{
		int k = 0;
		int l = col;
		
		while((l <= col + size - 1) && (k < size))
		{
			coordsArr[k] = to_string(row) + ":" + to_string(l);
			k++;
			l++;
		}
	}
	else	// vertical
	{
		int i = 0;
		int j = row;
		while((j <= row + size - 1) && (i < size))
		{
			coordsArr[i] = to_string(j) + ":" + to_string(col);
			i++;
			j++;
		}
	}

	// print coords for verification
	for(int x = 0; x < coordsArr->length(); x++)
	{
		cout << coordsArr[x] << ", ";
	}
	cout << '\n';
	return(coordsArr);
}

int main()
{
	Admiral stackAdm1 = Admiral();
	Admiral stackAdm2 = Admiral(5);
	Admiral* heapAdm1 = new Admiral();
	Admiral* heapAdm2 = new Admiral(4);

	// ADMIRAL TESTS
	// test constructors & getters: CLEARED
	cout << "-- TEST ADMIRAL CONSTRUCTORS & GETTERS --\n";
	cout << "stackAdm1 has:\n";
	cout << '\t' << stackAdm1.getNumShips() << " ships\n";
	cout << '\t' << stackAdm1.getNumAfloat() << " afloat.\n";
	cout << "\tfleet is empty = " << stackAdm1.getFleet().empty() << "\n";

	cout << "stackAdm2 has:\n";
	cout << '\t' << stackAdm2.getNumShips() << " ships\n";
	cout << '\t' << stackAdm2.getNumAfloat() << " afloat.\n";
	cout << "\tfleet is empty = " << stackAdm2.getFleet().empty() << "\n";

	// cout << "heapAdm1 has:\n";
	// cout << '\t' << heapAdm1->getNumShips() << " ships\n";
	// cout << '\t' << heapAdm1->getNumAfloat() << " afloat.\n";
	// cout << "\tfleet is empty = " << heapAdm1->getFleet().empty() << "\n";

	// cout << "heapAdm2 has:\n";
	// cout << '\t' << heapAdm2->getNumShips() << " ships\n";
	// cout << '\t' << heapAdm2->getNumAfloat() << " afloat.\n";
	// cout << "\tfleet is empty = " << heapAdm2->getFleet().empty() << "\n";

	// test setters & all getters
	cout << "-- TEST ADMIRAL SETTERS, ADDING SHIPS, & ADMIRAL & SHIP GETTERS --\n";
	cout << "Give stackAdm1 1 Ship at coord 1:1.\n";
	string* coord1 = new string[1];
	coord1[0] = "1:1";
	stackAdm1.setNumShips(1);
	stackAdm1.setNumAfloat(1);
	stackAdm1.addShip(1, coord1);
	cout << "stackAdm1 has:\n";
	cout << '\t' << stackAdm1.getNumShips() << " ships\n";
	cout << '\t' << stackAdm1.getNumAfloat() << " afloat.\n";
	cout << "\tfleet is empty = " << stackAdm1.getFleet().empty() << "\n";
	cout << "\ta Ship of size " << stackAdm1.getFleet()[0]->getSize() << " at " << stackAdm1.getFleet()[0]->getCoords()[0] << "\n";

	cout << "\nGive stackAdm2 5 Ships, all horizontal.\n";
	// string* stack2coords = generateCoords("1:1", 1, true);
	// stackAdm2.addShip(1, stack2coords);
	string* stack2coords = generateCoords("2:1", 2, true);
	delete stack2coords;
	// stackAdm2.addShip(2, stack2coords);
	stack2coords = generateCoords("3:1", 3, true);
	// stackAdm2.addShip(3, stack2coords);
	stack2coords = generateCoords("4:1", 4, true);
	// stackAdm2.addShip(4, stack2coords);
	stack2coords = generateCoords("5:1", 5, true);
	// stackAdm2.addShip(5, stack2coords);
	cout << "stackAdm2 has:\n";
	cout << '\t' << stackAdm2.getNumShips() << " ships\n";
	cout << '\t' << stackAdm2.getNumAfloat() << " afloat.\n";
	cout << "\tfleet is empty = " << stackAdm2.getFleet().empty() << "\n";
	cout << "\tShips of size:\n";
	for(int i = 0; i < stackAdm2.getNumShips(); i++)
	{
		cout << "\t\t" << stackAdm2.getFleet()[i]->getSize() << " at coord " << stackAdm1.getFleet()[i]->getCoords()[i] << "\n";
	}

	delete coord1;
	delete stack2coords;
	delete heapAdm1;
	delete heapAdm2;
	return(0);
}