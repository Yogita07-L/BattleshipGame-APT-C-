/*
 * Shot.h
 *
 *  Created on: 28-Jun-2024
 *      Author: Yogita
 */
#include "GridPosition.h"

#ifndef SHOT_H_
#define SHOT_H_

/*
 *
 */
class Shot
{
private:
	GridPosition targetPosition;


public:
	enum Impact
	{
		NONE,
		HIT,
		SUNKEN
	};

	Shot(GridPosition targetPosition);

	GridPosition getTargetPosition() const;

	virtual ~Shot();

};

#endif /* SHOT_H_ */
