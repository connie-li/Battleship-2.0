// Admiral.h

#ifndef ADMIRAL_H
#define ADMIRAL_H
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Grid.h"
#include "Ship.h"
using namespace std;

class Admiral
{
	private:
		Grid m_board;
		int m_numShips;
		Ship* m_fleet;
		int m_numAfloat;
		// vector<string> m_powerUpsArr;

	public:
		Admiral(int numShips);
		~Admiral();

		//getters
		Grid* getBoard() const;
		int getNumShips() const;
		Ship* getFleet() const;
		int getNumAfloat() const;
		// string getPowerUps() const;

		//setters


		//helpers
		Ship buildShip(const int size);
		void decNumAfloat();
		void addPowerUp(const string powerUp);
};

#endif