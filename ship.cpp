// ship.cpp

Ship::Ship(int size)
{
	m_size = size;
	m_coords = new string[m_size];
	m_status = true;
	m_numHits = 0;
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
int Ship::getSize() const;
string* Ship::getCoords() const;
bool Ship::getAfloat() const;
int Ship::getNumHits() const;