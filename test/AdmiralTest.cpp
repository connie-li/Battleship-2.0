// ADMIRAL & SHIP TESTING

#include "Admiral.h"
#include <iostream>
#include <string>
using namespace std;

void testInitial(string admName, Admiral* admPtr)
{
	cout << "Testing Admiral creation:\n";
	cout << admName << " has:\n";
	cout << '\t' << admPtr->getNumShips() << " ships\n";
	cout << '\t' << admPtr->getNumAfloat() << " afloat.\n";
	cout << "\tfleet is empty = " << admPtr->getFleet().empty() << "\n";
}

void testAddShip(Admiral* admPtr)
{
	bool fleetSizeCorrect = false;
	bool coordsCorrect = true;

	cout << "Testing adding Ships:\n";
	string* coord1 = new string[1];
	coord1[0] = "1:1";
	string* coord5 = new string[5];
	coord5[0] = "2:1";
	coord5[1] = "2:2";
	coord5[2] = "2:3";
	coord5[3] = "2:4";
	coord5[4] = "2:5";

	admPtr->addShip(1, coord1);
	admPtr->addShip(5, coord5);
	vector<Ship*> tempFleet = admPtr->getFleet();

	if(tempFleet.size() == 2)
	{
		fleetSizeCorrect = true;
	}

	if(tempFleet[0]->getCoords()[0] != coord1[0])
	{
		coordsCorrect = false;
	}
	for(int i = 0; i < 5; i++)
	{
		if(tempFleet[1]->getCoords()[i] != coord5[i])
		{
			coordsCorrect = false;
		}
	}

	cout << "Fleet size: ";
	if(fleetSizeCorrect)
	{
		cout << "PASSED\n";
	}
	else
	{
		cout << "FAILED\n";
	}

	cout << "Coords: ";
	if(coordsCorrect)
	{
		cout << "PASSED\n";
	}
	else
	{
		cout << "FAILED\n";
	}

	delete[] coord1;
	delete[] coord5;	
}

void testGetBoard(Admiral* admPtr)
{
	Grid* gridPtr = admPtr->getBoard();
	cout << "\n\nTesting Admiral::getBoard():\n";
	gridPtr->printGrid(false);
	testAddShip(admPtr);
	gridPtr->printGrid(false);
}

void runTests(Admiral* admPtr)
{
	testInitial("testAdm1", admPtr);
	testAddShip(admPtr);
}

int main()
{
	Admiral* testAdm1 = new Admiral(5);
	Admiral* testAdm2 = new Admiral(2);

	runTests(testAdm1);
	testGetBoard(testAdm2);

	delete testAdm1;
	delete testAdm2;
	return(0);
}
