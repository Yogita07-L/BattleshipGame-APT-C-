/*
 * OwnGrid.cpp
 *
 *  Created on: 23-Jun-2024
 *      Author: Yogita
 */

#include "OwnGrid.h"
#include "Ship.h"


OwnGrid::OwnGrid(int rows, int columns)
{
	this->rows=rows;
	this->columns=columns;

}

OwnGrid::~OwnGrid()
{
	// TODO Auto-generated destructor stub
}

int OwnGrid::getRows()
{
	return rows;
}

int OwnGrid::getColumns()
{
	return columns;
}

bool OwnGrid::placeShip(const Ship& ship)
{
	// Checks if the ship is valid (straight line, within boundaries)

	if (ship.isValid())
	{
	set<GridPosition> intersect;

	//finding the intersection between two ships
	for(const auto& itrOcc: ship.occupiedArea())
	{
		for(const auto& itrShips:this->getShips())
		{
			for(const auto& itrExis:itrShips.blockedArea())
			{
				if(itrOcc==itrExis)
				{
					intersect.insert(itrOcc);
				}
			}
		}
	}
	// checks if the new ship intersects with any existing ship
	if(intersect.size()==0 && LenAndNum[ship.length()] != 0)
	{
	    LenAndNum[ship.length()]--;
	    ships.push_back(ship);
	    return true;
	}
	}
	return false;
}

const std::vector<Ship> OwnGrid::getShips() const
{
	return ships;
}

Shot::Impact OwnGrid::takeBlow(const Shot& shot)
{
	set<GridPosition> intersect;
	if(shot.getTargetPosition().isValid())
	{
		for(auto& itrShips : ships)
		{
			for(auto& itrOcc : itrShips.occupiedArea())
			{
				if(itrOcc == shot.getTargetPosition())
				{
					for(auto& itrShotAt : shotAt)
					{
						if(itrShotAt == itrOcc)
						{
							intersect.insert(itrShotAt);
						}
					}
					if(intersect.size()==itrShips.occupiedArea().size()-1)
					{
						return Shot::SUNKEN;
					}

					shotAt.insert(shot.getTargetPosition());
					return Shot::HIT;
				}

			}
		}
		shotMissed.insert(shot.getTargetPosition());
	}
	return Shot::NONE;
}
const set<GridPosition> OwnGrid::getShotAt() const
{
	return this->shotAt;
}

const set<GridPosition> OwnGrid::getShotMissed() const
{
	return this->shotMissed;
}
