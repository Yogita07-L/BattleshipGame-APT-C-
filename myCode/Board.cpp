/*
 * Board.cpp
 *
 *  Created on: 23-Jun-2024
 *      Author: Yogita
 */

#include "Board.h"

Board::Board(int rows, int columns):ownGrid(rows,columns),
opponentGrid(rows,columns)
{
	this->rows=rows;
	this->columns=columns;
}

Board::~Board()
{
	// TODO Auto-generated destructor stub
}

int Board::getRows()
{
	return rows;
}

int Board::getColumns()
{
	return columns;
}
OwnGrid& Board::getOwnGrid()
{
	return ownGrid;
}

OpponentGrid Board::getOpponentGrid()
{
	return opponentGrid;
}
