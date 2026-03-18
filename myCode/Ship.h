/*
 * Ship.h
 *
 *  Created on: 21-Jun-2024
 *      Author: Yogita
 */
#include <set>
#include "GridPosition.h"

using namespace std;


#ifndef SHIP_H_
#define SHIP_H_


/*
 *A ship has as data members two grid fields, named bow and stern
 */
class Ship
{
private:
	GridPosition bow;
	GridPosition stern;
public:
	Ship(const GridPosition& bow, const GridPosition& stern);
	virtual ~Ship();
	/*
	 * Method isValid checks if the grid positions for bow and stern are valid,
	 * whether the ship is positioned horizontally or vertically and whether the length is between 2 and 5.
	 */
	bool isValid() const;
	/*
	 * getter for bow
	 */
	GridPosition getBow()const;
	/*
	 * getter for stern
	 */
	GridPosition getStern() const;
	/*
	 *  Member function length returns the length of the ship,
	 *  calculated from the distance between bow and stern.
	 */
	int length() const;

	/*
	 * The method occupiedArea returns all grid positions that are occupied by the ship.
	 *  If e.g. the ship’s 2bow is at B2 and its stern at E2,
	 * then the function return B2, C2, D2, E2.
	 */
	std::set <GridPosition> occupiedArea() const;

	std::set <GridPosition> blockedArea() const;


};

#endif /* SHIP_H_ */
