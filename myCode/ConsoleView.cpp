/*
 * ConsoleView.cpp
 *
 *  Created on: 23-Jun-2024
 *      Author: Yogita
 */

#include "ConsoleView.h"

ConsoleView::ConsoleView(Board* board)
{
	this->board =board;
	int Rows = board->getRows();
	int Columns = board->getColumns();

// dynamic memory allocation for each grid
	ownGrid = new char*[Rows];
	opponentGrid = new char*[Rows];
	for(int i= 0; i<Rows; i++)
	{
		ownGrid[i] = new char[Columns];
		opponentGrid[i] = new char[Columns];
	}
//Initialize char array
	for(int i=0; i<Rows; i++)
	{
		for(int j=0; j<Columns; j++)
		{
			ownGrid[i][j]='~';
			opponentGrid[i][j]='~';//water sign for initial grids without ship
		}
	}
}


//print method to display game state in console
void ConsoleView::print()
{
	fillArray();
    for (int itr=0; itr < board->getOwnGrid().getRows()+2; itr++)
    {
    	printArray(itr, 0);
    	cout<<' '<<' ';
        printArray(itr, 1);
        cout << endl;
    }
}

//Private function to fill the char arrays using each grid information
void ConsoleView::fillArray()
{

	//filling char array of ownGrid
	for(auto& itrShips:board->getOwnGrid().getShips())
	{
		for(auto& itrGrid:itrShips.occupiedArea())
		{
			ownGrid[int(itrGrid.getRow()-'A')][itrGrid.getColumn()-1]='#';
		}
	}
	for(auto& itrShots:board->getOwnGrid().getShotAt())
	{
		ownGrid[itrShots.getRow()-'A'][itrShots.getColumn()-1]='O';
	}
	for(auto &itrmissed : board->getOwnGrid().getShotMissed())
	{
		ownGrid[int(itrmissed.getRow()-'A')][itrmissed.getColumn()-1] = '^';
	}

	//filling char array of opponentGrid
	for(auto& itroshot : board->getOpponentGrid().getShotsAt())
		{
			if(itroshot.second==Shot::HIT){
				opponentGrid[int(itroshot.first.getRow()-'A')]
						[itroshot.first.getColumn()-1] = 'O';
			}

			if(itroshot.second==Shot::NONE){
				opponentGrid[int(itroshot.first.getRow()-'A')]
						[itroshot.first.getColumn()-1] = '^';
			}
		}
		for(auto &itrsunken : board->getOpponentGrid().getsunkenShips())
			{
				for(auto &itrGrid : itrsunken.occupiedArea())
				{
					opponentGrid[int(itrGrid.getRow()-'A')]
					[itrGrid.getColumn()-1] = '#';
				}
			}

}

//Private function to print the ownGrid & opponentGrid
void ConsoleView::printArray(int row, int typeOfBoard)
{
	//for ownGrid gridType=0
	//for opponentGrid gridType=1

	int cols = board->getColumns();
	char row_ = row+63;

	//print column headers - tens
	if(row==0)
	{
		cout<<' '<<' ';
		for(int itr=0;itr<cols;itr++)
		{
			if((itr+1)/10==0)
			{
				cout<<" ";
			}
            else
            {
                cout << ((itr + 1) / 10);
            }
			cout<<" ";
		}
	}

	// Print column numbers (units place)
	if(row==1)
	{
		cout<<' '<<' ';
		for(int itr=0;itr<cols;itr++)
		{
			cout<<(itr+1)%10<<' ';
		}
	}
	if(row>1)
	{
		cout<<row_<<' ';
		for(int arrayItr=0 ; arrayItr<cols ; arrayItr++)
			{
			if(typeOfBoard==0)
			{
				cout<<ownGrid[row-2][arrayItr];
			}
			if(typeOfBoard==1)
			{
				cout<<opponentGrid[row-2][arrayItr];
			}
			cout<<' ';
			}
	}
}

ConsoleView::~ConsoleView()
{

		for(int i= 0; i<board->getRows(); i++)
		{
			delete[]ownGrid[i];
			delete[]opponentGrid[i];
		}
		delete[]ownGrid;
		delete[]opponentGrid;
}
