// ship.cpp
#include "Ship.h"

Ship::Ship(int size)
{
	m_size = size;
	m_coords = new string[m_size];
	m_status = true;
	m_numHits = 0;
}

Ship::Ship(int size, string* coords, bool status, int hits)
{
	m_size = size;
	m_coords = new string[m_size];
	for(int i=0; i<m_size; i++)
	{
		m_coords[i]=coords[i];
	}
	m_status = status;
	m_numHits = hits;
}

Ship::~Ship()
{
	delete[] m_coords;
}

// setters
void Ship::setStatusFalse()
{
	m_status = false;
}

void Ship::incNumHits()
{
	if(m_status)
	{
		m_numHits++;
		if(m_numHits >= m_size)
		{
			setStatusFalse();
		}
	}
	else
	{
		cout << "ERROR in Ship::incNumHits -- cannot make the number of hits greater than the size of the Ship.";
	}
}

void Ship::setCoords(const string* coordsArr, const int size)
{
	if(size != m_size)
	{
		throw(runtime_error("ERROR in Ship::setCoords -- array passed in is too large!"));
	}
	else
	{
		for(int i = 0; i < m_size; i++)
		{
			m_coords[i] = coordsArr[i];
		}
	}
}

// getters
int Ship::getSize() const
{
	return(m_size);
}

string* Ship::getCoords() const
{
	return(m_coords);
}

bool Ship::getStatus() const
{
	return(m_status);
}

int Ship::getNumHits() const
{
	return(m_numHits);
}