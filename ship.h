// ship.h
#ifndef SHIP_H
#define SHIP_H
#include <string>
using namespace std;

/** Class that represents a Ship.
 *
 */
class Ship
{
	private: 
		int m_size;
		string* m_coords;
		bool m_afloat;
		int m_numHits;

	public:
		Ship(int size);
		~Ship();

		// setters
		void setStatus();
		void incNumHits();
		void setCoords(const string* coordsArr);

		// getters
		int getSize() const;
		string* getCoords() const;
		bool getAfloat() const;
		int getNumHits() const;
};

#endif