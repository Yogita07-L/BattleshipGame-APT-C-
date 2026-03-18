/*
 * ConsoleView.h
 *
 *  Created on: 23-Jun-2024
 *      Author: Yogita
 */

#include "Board.h"

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_

/*
 *
 */
class ConsoleView
{
private:
	Board* board; //Pointer to the class Board.

	char** ownGrid; //pointer to point to the board of char to store the data from ownGrid

	char** opponentGrid; //pointer to point to the board of char to store the data from opponentGrid

	void fillArray();

	void printArray(int row, int typeOfBoard);
public:
	ConsoleView(Board* board);


	virtual ~ConsoleView();

	void print();
};

#endif /* CONSOLEVIEW_H_ */
