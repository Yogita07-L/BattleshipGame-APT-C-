/*
 * OpponentGrid.h
 *
 *  Created on: 23-Jun-2024
 *      Author: Yogita
 */

#include "Ship.h"
#include "Shot.h"
#include<vector>
#include <map>

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

/**
 * @class OpponentGrid  The opponent grid is used to track the player’s interaction with the opponent.
 * It holds e.g. the information about the ships that have been sunken.
 * Of course, initially,
 * when the game starts, there are no sunken ships.
 * @brief
 *
 */
class OpponentGrid
{
private:
	int rows;

	int columns;

	map<GridPosition, Shot::Impact> shots;

	//vector for sunken ships of opponent
	vector<Ship> sunkenShips;


public:
	OpponentGrid(int rows, int columns);

	virtual ~OpponentGrid();

	/**
		 * @fn void shotResult(const Shot&, Shot::Impact)
	 * @brief This method stores the impact of the shot. It takes the
	 * GridPosition and Impact enum value as an arguments and update the
	 * sunkenships and map of impact and GridPosition.
	 *
	 * @param shot
	 * shot as a GridPosition type
	 * @param impact
	 * impact as a Impact enum type
	 */
	void shotResult(const Shot& shot, Shot::Impact impact);

	int getRows();

	int getColumns();

	const map<GridPosition,Shot::Impact> getShotsAt() const;

	const vector<Ship> getsunkenShips() const;

};

#endif /* OPPONENTGRID_H_ */
