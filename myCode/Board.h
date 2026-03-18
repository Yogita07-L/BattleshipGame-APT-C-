/*
 * Board.h
 *
 *  Created on: 23-Jun-2024
 *      Author: Yogita
 */

#include "OwnGrid.h"
#include "OpponentGrid.h"

#ifndef BOARD_H_
#define BOARD_H_

/*
 *
 */
class Board
{
private:
	OwnGrid ownGrid;
	OpponentGrid opponentGrid;
	int rows;
	int columns;

public:
	Board(int rows=10, int columns=10);

	virtual ~Board();

	int getRows();

	int getColumns();

	OwnGrid& getOwnGrid();

	OpponentGrid getOpponentGrid();

};

#endif /* BOARD_H_ */
