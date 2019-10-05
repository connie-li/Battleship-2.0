// Admiral.h

#ifndef ADMIRAL_H
#define ADMIRAL_H
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Grid.h"
#include "Ship.h"
using namespace std;

class Admiral
{
	private:
		Grid m_board;	/* a Grid to store the Admiral's game map. */
		int m_numShips;	/* the number of Ships in Admiral. */
		vector<Ship> m_fleet;	/* an array of Ships that belong to the Admiral. */
		int m_numAfloat;	/* the number of ships that are still afloat. */
		// vector<string> m_powerUpsVec;	/* a vector containing an PowerUps that the Admiral currently has. */

	public:
		/** A constructor that takes no parameters.
		 *
		 */
		Admiral();

		/** A constructor that takes one parameter.
		 * @param numShips the number of Ships the Admiral will have.
		 */
		Admiral(int numShips);

		/** The destructor.  Manually deletes the pointer m_fleet.
		 *
		 */
		~Admiral();

		// --- getters ---

		/** Gets the Admiral's game board.
		 * @return a reference to m_board.
		 */
		Grid getBoard() const;

		/** Gets the Admiral's total number of Ships.
		 * @return the number of Ships, aka the size of the m_fleet array.
		 */
		int getNumShips() const;

		/** Gets the Admiral's fleet of Ships.
		 * @return a reference to the fleet vector.
		 */
		vector<Ship> getFleet() const;

		/** Gets the number of the Admiral's Ships that are still afloat.
		 * @return the number of Ships afloat.
		 */
		int getNumAfloat() const;
		// string getPowerUps() const;

		// --- setters ---

		/** Sets the number of Ships that Admiral has.
		 * @param numShips the number of Ships.
		 */
		void setNumShips(const int numShips);

		/** Sets the number of Ships that are still afloat; initially, the same number as the total number of Ships.
		 * @param num the number of Ships.
		 */
		void setNumAfloat(const int num);

		// --- helpers ---

		/** Constructs a Ship object with size and coordinates, adds it to the m_fleet vector, and assigns the Ship's coordinates to m_board.
		 * @param size the size of the Ship.
		 * @param coordsArr a pointer to an array of coordinates that the new Ship will occupy.
		 */
		void addShip(const int size, const string* coordsArr);

		/** Decrements the number of Ships still afloat; this function is called when a Ship sinks.
		 * @return the number of Ships still afloat.
		 */
		int decNumAfloat();

		/**
		 *
		 */
		// void addPowerUp(const string powerUp);
};
 
#endif