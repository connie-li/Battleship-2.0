// Admiral.cpp

#include "Admiral.h"

Admiral::Admiral(int numShips)
{
	m_board = new Grid();
	m_numShips = numShips;
	m_fleet = new Ship*[numShips];
	for(int i = 0; i < numShips; i++)
	{
		m_fleet[i] = buildShip(i + 1);
	}
	m_numAfloat = numShips;
}

Admiral::~Admiral();

//getters
Grid* Admiral::getBoard() const;
int Admiral::getNumShips() const;
Ship* Admiral::getFleet() const;
int Admiral::getNumAfloat() const;
string Admiral::getPlayerName() const;
string Admiral::getPowerUps() const;