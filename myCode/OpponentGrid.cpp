/*
 * OpponentGrid.cpp
 *
 *  Created on: 23-Jun-2024
 *      Author: Yogita
 */

#include "OpponentGrid.h"

OpponentGrid::OpponentGrid(int rows,int columns)
{
	this->rows=rows;
	this->columns=columns;

}

OpponentGrid::~OpponentGrid()
{
	// TODO Auto-generated destructor stub
}

void OpponentGrid::shotResult(const Shot& shot, Shot::Impact impact)
{
	if(shot.getTargetPosition().isValid())
	{
		const int directions[4][2] = {{-1, 0},{0, 1},{0, -1},{1, 0}};
		char row = shot.getTargetPosition().getRow();
		int column = shot.getTargetPosition().getColumn();
		bool SingleShip = false;


		switch(impact)
		{
		case Shot::HIT:
		case Shot::NONE:
			shots[shot.getTargetPosition()]= impact;
			break;
		case Shot::SUNKEN:
			//check the sunken ships and update the vector SunkenShips
			for(int pos = 0; pos <4; pos++)
			{
				char otherrow = row + directions[pos][0];
				int othercolumn = column + directions[pos][1];

				for(auto& itr : shots)
				{
                    if ((itr.first.getRow() == otherrow) &&
                        (itr.first.getColumn() == othercolumn) &&
                        (itr.second == Shot::HIT))
                    {
                    	 for (int nextpos = 0; nextpos < 4; ++nextpos)
                    	 {
                    		 otherrow += directions[pos][0];
                    		 othercolumn += directions[pos][1];
                             for (auto &itr1 : shots)
                             {
                                 if ((itr1.first.getRow() == otherrow) &&
                                     (itr1.first.getColumn() == othercolumn) &&
                                     (itr1.second == Shot::HIT))
                                 {
                                     SingleShip = true;
                                     break;
                                 }
                             }
							 if (!SingleShip)
							{
								otherrow -= directions[pos][0];
								othercolumn -= directions[pos][1];

								// Add the sunken ship to the sunkenShips vector
								sunkenShips.push_back(Ship{GridPosition{otherrow, othercolumn},
														  GridPosition{row, column}});
								break;
							}
							SingleShip = false;
						}
						break;
					}
				}
			}
			break;
		}
	}
}
int OpponentGrid::getRows()
{
	return rows;
}

int OpponentGrid::getColumns()
{
	return columns;
}

// Getter method to retrieve the map of shots
const map<GridPosition, Shot::Impact> OpponentGrid::getShotsAt()const
{
    return shots;
}
const vector<Ship> OpponentGrid::getsunkenShips() const
{
    return sunkenShips;
}
