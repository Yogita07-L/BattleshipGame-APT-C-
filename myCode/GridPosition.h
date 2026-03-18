/*
 * GridPosition.h
 *
 *  Created on: 16-Jun-2024
 *      Author: Yogita
 */

#include<iostream>
#include <string>
#include <sstream>

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_


using std::string;
using std::to_string;

/*
 *
 */
class GridPosition
{
private:
	char row;
	int column;
public:
	GridPosition();
	GridPosition(char row, int column);

	GridPosition(string position);

	~GridPosition();

	bool isValid() const;

	char getRow() const;

	int getColumn() const;

	operator string() const;

	bool operator==(const GridPosition& other) const;

	bool operator<(const GridPosition& other) const;

};

#endif /* GRIDPOSITION_H_ */
