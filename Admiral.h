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

		//getters
		/** Gets the Admiral's game board.
		 * @return a reference to m_board.
		 */
		Grid getBoard() const;

		/** Gets the Admiral's total number of Ships.
		 * @return the number of Ships, aka the size of the m_fleet array.
		 */
		int getNumShips() const;

		/** Gets the Admiral's fleet of Ships.
		 * @return a pointer to the fleet array.
		 */
		Ship* getFleet() const;

		/** Gets the number of the Admiral's Ships that are still afloat.
		 * @return the number of Ships afloat.
		 */
		int getNumAfloat() const;
		// string getPowerUps() const;

		//setters


		//helpers
		/**
		 *
		 */
		Ship buildShip(const int size);

		/**
		 *
		 */
		void decNumAfloat();

		/**
		 *
		 */
		void addPowerUp(const string powerUp);
};

#endif