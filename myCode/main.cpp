
#include "Part1Tests.h"

#include "Board.h"

#include"Ship.h"
#include "ConsoleView.h"
#include "ConsoleView.h"
#include "Part1tests.h"
#include "Part2tests.h"
#include "Part3tests.h"

int main ()
{
    // TODO: Add your program code here
	cout << "BattleShip1 started. Part1 tests start here!" << endl << endl;
	//part1tests();
	Board board(10,10);
	std::cout<<"Part 1 testing:"<<endl;
	part1tests();

	std::cout<<"Part 2 testing:"<<endl;
	part2tests();

	std::cout<<"Part 3 testing:"<<endl;
	part3tests();


	return 0;
}
