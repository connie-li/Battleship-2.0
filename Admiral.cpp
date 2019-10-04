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

Admiral::~Admiral()
{
	delete m_board;
	delete m_fleet;
	//delete m_powerUpsVec;
}

//getters
Grid* Admiral::getBoard() const
{
	return(m_board);
}

int Admiral::getNumShips() const
{
	return(m_numShips);
}

Ship* Admiral::getFleet() const
{
	return(m_fleet);
}

int Admiral::getNumAfloat() const
{
	return(m_numAfloat);
}

// string Admiral::getPowerUps() const

