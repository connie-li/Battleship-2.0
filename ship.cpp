// ship.cpp

Ship::Ship(int size)
{
	m_size = size;
	m_coords = new string[m_size];
	m_afloat = true;
	m_numHits = 0;
}

Ship::~Ship()
{
	delete[] m_coords;
}

// setters
void Ship::setStatus();
void Ship::incNumHits();
void Ship::setCoords(const string* coordsArr);

// getters
int Ship::getSize() const;
string* Ship::getCoords() const;
bool Ship::getAfloat() const;
int Ship::getNumHits() const;