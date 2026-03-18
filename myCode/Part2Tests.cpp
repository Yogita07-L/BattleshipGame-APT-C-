/*
 * Part2Tests.cpp
 *
 *  Created on: 07-Jan-2024
 *      Author: Yogita
 */
#include "Part2Tests.h"
#include <iostream>
#include "Part1Tests.h"
using namespace std;

#include "Board.h"
#include "ConsoleView.h"


void part2tests()
{
	Board Board1(10,10);
	ConsoleView Console1(&Board1);

	cout<<"	Ships may not touch each other :"<<endl;
	assertTrue(Board1.getOwnGrid().placeShip(Ship{GridPosition{"D5"},
		GridPosition{"H5"}}),"Can not create a ship of size 5");
	assertTrue(!Board1.getOwnGrid().placeShip(Ship{GridPosition{"E4"},
			GridPosition{"G4"}}),"Can create a ship touching another ship");

	Console1.print();

	cout<<"	The grid fields occupied by a ship form a straight line :"<<endl;
	assertTrue(Board1.getOwnGrid().placeShip(Ship{GridPosition{"A1"},
		GridPosition{"A4"}}),"Can not create a first ship of size 4");
	assertTrue(!Board1.getOwnGrid().placeShip(Ship{GridPosition{"I7"},
		GridPosition{"J8"}}),"Can create a ship Diagonally");

	Console1.print();

	cout<<"	Ships may be positioned at the edges of the grid :"<<endl;
	assertTrue(Board1.getOwnGrid().placeShip(Ship{GridPosition{"A6"},
		GridPosition{"A9"}}),"Can not create a ship on the edge");

	Console1.print();

	cout<<"	Each player has 10 ships of size 5-1,4-2,3-3,2-4 :"<<endl;
	assertTrue(!Board1.getOwnGrid().placeShip(Ship{GridPosition{"B5"},
		GridPosition{"B9"}}),"Can create another ship with size 5");

	assertTrue(!Board1.getOwnGrid().placeShip(Ship{GridPosition{"B10"},
			GridPosition{"E10"}}),"Can create third ship of size 4");

	assertTrue(Board1.getOwnGrid().placeShip(Ship{GridPosition{"C1"},
		GridPosition{"C3"}}),"Can not create first ship of size 3");
	assertTrue(Board1.getOwnGrid().placeShip(Ship{GridPosition{"C7"},
		GridPosition{"C9"}}),"Can not create second ship of size 3");
	assertTrue(Board1.getOwnGrid().placeShip(Ship{GridPosition{"J1"},
		GridPosition{"J3"}}),"Can not create third ship of size 3");
	assertTrue(!Board1.getOwnGrid().placeShip(Ship{GridPosition{"H10"},
		GridPosition{"J10"}}),"Can create fourth ship of size 3");

	assertTrue(Board1.getOwnGrid().placeShip(Ship{GridPosition{"E2"},
		GridPosition{"E3"}}),"Can not create first ship of size 2");
	assertTrue(Board1.getOwnGrid().placeShip(Ship{GridPosition{"G1"},
		GridPosition{"G2"}}),"Can not create second ship of size 2");
	assertTrue(Board1.getOwnGrid().placeShip(Ship{GridPosition{"E8"},
		GridPosition{"E9"}}),"Can not create third ship of size 2");
	assertTrue(Board1.getOwnGrid().placeShip(Ship{GridPosition{"J5"},
		GridPosition{"J6"}}),"Can not create fifth fourth of size 2");

	assertTrue(!Board1.getOwnGrid().placeShip(Ship{GridPosition{"J5"},
		GridPosition{"J6"}}),"Can create fifth ship of size 2");


	Console1.print();
}


