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

// --- getters ---
Grid Admiral::getBoard() const
{
	return(m_board);
}

int Admiral::getNumShips() const
{
	return(m_numShips);
}

vector<Ship>& Admiral::getFleet() const
{
	return(m_fleet);
}

int Admiral::getNumAfloat() const
{
	return(m_numAfloat);
}

// string Admiral::getPowerUps() const

// --- setters ---
void setNumShips(const int numShips)
{
	m_numShips = numShips;
}

void setNumAfloat(const int num)
{
	m_numAfloat = num;
}

void addShip(const int size, const string* coordsArr)
{
	m_fleet.emplace_back(Ship(size));
	m_fleet.back.setCoords(coordsArr, size);
	m_board.readShip(coordsArr, size);
}

int decNumAfloat()
{
	m_numAfloat--;
	return(m_numAfloat);
}