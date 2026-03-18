/*
 * GridPosition.cpp
 *
 *  Created on: 16-Jun-2024
 *      Author: Yogita
 */

#include "GridPosition.h"

GridPosition::GridPosition()
{
}
GridPosition::GridPosition(char row, int column)
:row(row), column(column)
{
}

GridPosition::GridPosition(std::string position)
{
	this->row = position[0];

	string column1 = position.substr(1,position.size()-1);

	this->column = stoi(column1);
}

GridPosition::~GridPosition()
{

}
bool GridPosition::isValid() const
{
	if(getRow()>= 'A' && getRow()<='Z' && getColumn()>0)
	{
		return true;
	}
	else
	{
		return false;
	}

}
char GridPosition::getRow() const
{
	return row;
}

int GridPosition::getColumn() const
{
	return column;
}

GridPosition::operator string() const
{
	string s1 = to_string(column);
	string s2 = row + s1;
	return s2;
}

bool GridPosition::operator==(const GridPosition& other) const
{
	return  row==other.row && column==other.column;
}
bool GridPosition::operator<(const GridPosition& other) const
{
	return this->getRow()<other.getRow() || this->getColumn()<other.getColumn();
}
