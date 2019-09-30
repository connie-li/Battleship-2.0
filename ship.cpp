// ship.cpp

Ship::Ship(int size);
Ship::~Ship();

// setters
void Ship::setStatus();
void Ship::incNumHits();
void Ship::setCoords(const string* coordsArr);

// getters
int Ship::getSize() const;
string* Ship::getCoords() const;
bool Ship::getAfloat() const;
int Ship::getNumHits() const;