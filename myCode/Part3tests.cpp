/*
 * Part3tests.cpp
 *
 *  Created on: 07-Jan-2024
 *      Author: Yogita
 */

#include "ConsoleView.h"
#include "Shot.h"
#include "Part1tests.h"

void part3tests()
{
	Board B1(10,10);
	ConsoleView Console1(&B1);

	B1.getOwnGrid().placeShip(Ship{GridPosition{"D3"},GridPosition{"H3"}}); // size = 5
	B1.getOwnGrid().placeShip(Ship{GridPosition{"A1"},GridPosition{"A4"}}); // size = 4
	B1.getOwnGrid().placeShip(Ship{GridPosition{"B7"},GridPosition{"B10"}}); // size = 4
	B1.getOwnGrid().placeShip(Ship{GridPosition{"C1"},GridPosition{"E1"}}); // size = 3
	B1.getOwnGrid().placeShip(Ship{GridPosition{"D7"},GridPosition{"D9"}}); // size = 3
	B1.getOwnGrid().placeShip(Ship{GridPosition{"J3"},GridPosition{"J5"}}); // size = 3
	B1.getOwnGrid().placeShip(Ship{GridPosition{"C5"},GridPosition{"D5"}}); // size = 2
	B1.getOwnGrid().placeShip(Ship{GridPosition{"G1"},GridPosition{"H1"}}); // size = 2
	B1.getOwnGrid().placeShip(Ship{GridPosition{"F8"},GridPosition{"F9"}}); // size = 2
	B1.getOwnGrid().placeShip(Ship{GridPosition{"H7"},GridPosition{"H8"}}); // size = 2

	cout<<"OwnGrid shots Testing:"<<endl;

	assertTrue((B1.getOwnGrid().takeBlow(GridPosition{"E3"})==Shot::HIT),
			"HITting the GridPosition with ship is not a HIT shot");
	assertTrue((B1.getOwnGrid().takeBlow(GridPosition{"J3"})==Shot::HIT),
			"HITting the GridPosition with ship is not a HIT shot");

	assertTrue((B1.getOwnGrid().takeBlow(GridPosition{"A5"})==Shot::NONE),
			"HITting the GridPosition without ship is not a missed shot");
	assertTrue((B1.getOwnGrid().takeBlow(GridPosition{"C4"})==Shot::NONE),
			"HITting the GridPosition without ship is not a missed shot");
	assertTrue((B1.getOwnGrid().takeBlow(GridPosition{"J2"})==Shot::NONE),
			"HITting the GridPosition without ship is not a missed shot");

	assertTrue((B1.getOwnGrid().takeBlow(GridPosition{"H7"})==Shot::HIT),
			"HITting the GridPosition with ship is not a HIT shot");
	assertTrue((B1.getOwnGrid().takeBlow(GridPosition{"H8"})==Shot::SUNKEN),
			"HITting the GridPosition without ship is not a missed shot");


	cout<<"OpponentGrid shots Testing:"<<endl;

	B1.getOpponentGrid().shotResult(Shot(GridPosition{"C3"}),Shot::HIT);
	B1.getOpponentGrid().shotResult(Shot(GridPosition{"C4"}),Shot::HIT);
	B1.getOpponentGrid().shotResult(Shot(GridPosition{"G5"}),Shot::HIT);
	B1.getOpponentGrid().shotResult(Shot(GridPosition{"G6"}),Shot::HIT);
	B1.getOpponentGrid().shotResult(Shot(GridPosition{"E3"}),Shot::HIT);
	B1.getOpponentGrid().shotResult(Shot(GridPosition{"C2"}),Shot::NONE);
	B1.getOpponentGrid().shotResult(Shot(GridPosition{"F5"}),Shot::NONE);
	B1.getOpponentGrid().shotResult(Shot(GridPosition{"G4"}),Shot::NONE);
	B1.getOpponentGrid().shotResult(Shot(GridPosition{"I5"}),Shot::NONE);

	Console1.print();
	B1.getOpponentGrid().shotResult(GridPosition{"D3"},Shot::SUNKEN);

	Console1.print();

}
