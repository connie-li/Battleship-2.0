// ship.h
#ifndef SHIP_H
#define SHIP_H
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

/** Class that represents a Ship.
 *
 */
class Ship
{
	private: 
		int m_size;
		string* m_coords;
		bool m_status;
		int m_numHits;

	public:
		/** A constructor with one parameter.
		 * @param size the size (1-5) of the Ship.
		 * @post creates a Ship of the given size, with an empty array of coordinates.
		 */
		Ship(int size);

		/** A constructor with one parameter.
		 * @param size the size (1-5) of the Ship.
		 * @param coords string array containing coordinates like 1:1
		 * @param status if sunk or not
		 * @param hits number of hits
		 * @post creates a Ship of the given parameters, with an empty array of coordinates.
		 */
		Ship(int size, string* coords, bool status, int hits);

		/** A destructor.  Deletes the member array of coordinates.
		 *
		 */
		~Ship();

		// --- SETTERS ---
		/** Sets the ship's status to false when it has been sunk.
		 * @pre the ship has taken enough hits to sink.
		 * @post sets m_status to false.
		 */
		void setStatusFalse();

		/** Increments the number of hits the ship has taken, and sinks the ship if enough hits have been taken.
		 * @pre the hit on the ship has been validated.
		 * @post increases m_numHits by 1.  If the ship has taken enough hits to sink, calls setStatusFalse().
		 */
		void incNumHits();

		/** Assigns coords to the ship's coordinate array.
		 * @pre the given coordinates are valid.
		 * @param coordsArr a pointer to an array of coordinates.
		 * @param size the size of the given array.  Should be equal to the size of the ship.
		 * @post assigns the given coordinates to the Ship's coordinate array.
		 */
		void setCoords(const string* coordsArr, const int size);

		// --- GETTERS ---
		/** Gets the size of the Ship.
		 * @return the size of the Ship, m_size.
		 */
		int getSize() const;

		/** Gets the Ship's coordinates.
		 * @return a pointer to the array of the Ship's coordinates.
		 */
		string* getCoords() const;

		/** Gets the Ship's status.
		 * @return true if the Ship is still afloat, else false.
		 */
		bool getStatus() const;

		/** Gets the number of hits the Ship has taken.
		 * @return the number of hits the Ship has taken, m_numHits.
		 */
		int getNumHits() const;
};

#endif