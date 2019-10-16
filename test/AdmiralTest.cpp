// ADMIRAL & SHIP TESTING

#include "Admiral.h"
#include <iostream>
#include <string>
using namespace std;

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

	cout << "heapAdm1 has:\n";
	cout << '\t' << heapAdm1->getNumShips() << " ships\n";
	cout << '\t' << heapAdm1->getNumAfloat() << " afloat.\n";
	cout << "\tfleet is empty = " << heapAdm1->getFleet().empty() << "\n";

	cout << "heapAdm2 has:\n";
	cout << '\t' << heapAdm2->getNumShips() << " ships\n";
	cout << '\t' << heapAdm2->getNumAfloat() << " afloat.\n";
	cout << "\tfleet is empty = " << heapAdm2->getFleet().empty() << "\n";

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
	cout << "\ta Ship of size " << stackAdm1.getFleet()[0].getSize() << " at " << stackAdm1.getFleet()[0].getCoords()[0] << "\n";
	

	delete heapAdm1;
	delete heapAdm2;
	return(0);
}