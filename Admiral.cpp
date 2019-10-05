// Admiral.cpp

#include "Admiral.h"

Admiral::Admiral()
{
	m_numShips = 0;
	m_numAfloat = 0;
}

Admiral::Admiral(int numShips)
{
	m_numShips = numShips;
	m_numAfloat = numShips;
}

Admiral::~Admiral()
{
	delete m_fleet;
	//delete m_powerUpsVec;
}

//getters
Grid Admiral::getBoard() const
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

