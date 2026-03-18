/*
 * OwnGrid.h
 *
 *  Created on: 23-Jun-2024
 *      Author: Yogita
 */

#include "Ship.h"
#include "Shot.h"
#include <vector>
#include <map>

#ifndef OWNGRID_H_
#define OWNGRID_H_

/*
 *
 */
class OwnGrid
{

private:
	int rows;

	int columns;

	vector<Ship> ships;

	/**
	 * A map containing two components of datatype int: lengths of ship
	 * and number of ship of that lengths.
	 	 */
	map<int, int> LenAndNum{{2,4},{3,3},{4,2},{5,1}};
	set<GridPosition> shotAt;

	set<GridPosition> shotMissed;

public:
	OwnGrid(int rows, int columns);

	virtual ~OwnGrid();

	int getRows();

	int getColumns();

	bool placeShip(const Ship& ship);

	const std::vector<Ship> getShips() const;

	Shot::Impact takeBlow(const Shot& shot);

	const set<GridPosition> getShotAt() const;

	const set<GridPosition> getShotMissed() const;
};


#endif /* OWNGRID_H_ */
