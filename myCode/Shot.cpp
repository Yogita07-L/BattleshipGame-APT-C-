/*
 * Shot.cpp
 *
 *  Created on: 28-Jun-2024
 *      Author: Yogita
 */

#include "Shot.h"

/*@class If the shot doesn't hit a ship, the value Shot::Impact::NONE is returned.
 * If a ship is hit, 5Shot::Impact::HIT is returned.
 * If the hit is the final hit, i.e. the ship is sunk by the hit,
 * Shot::Impact::SUNKEN is returned.
 *
 */
Shot::Shot(GridPosition targetPosition)
:targetPosition(targetPosition)
{

}

Shot::~Shot()
{
	// TODO Auto-generated destructor stub
}

GridPosition Shot::getTargetPosition() const
{
	return this->targetPosition;
}
