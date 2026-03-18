/*
 * Ship.cpp
 *
 *  Created on: 21-Jun-2024
 *      Author: Yogita
 */

#include "Ship.h"


Ship::Ship(const GridPosition& bow,const GridPosition& stern)
:bow(bow),stern(stern)
{
}

Ship::~Ship()
{
	// TODO Auto-generated destructor stub
}
bool Ship::isValid() const
{
	if(bow.getRow()==stern.getRow() || bow.getColumn()==stern.getColumn())
	{
		if(this->length()>=2 && this->length()<=5)
		{
			return true;
		}
	}
	return false;
}



GridPosition Ship::getBow()const
{
	return bow;

}

GridPosition Ship::getStern()const
{
	return stern;
}

int Ship::length() const
{
	int len=0;
	if(bow < stern)
	{
		if(bow.getRow()==stern.getRow())
		{
			len =(stern.getColumn()- bow.getColumn())+1;
		}
		if(stern.getColumn()==bow.getColumn())
		{
			len = (stern.getRow()- bow.getRow())+1;
		}
		return len;
	}
	else
	{
		if(bow.getRow()==stern.getRow())
		{
			len =(stern.getColumn()- bow.getColumn())+1;
		}
		if(stern.getColumn()==bow.getColumn())
		{
			len = (stern.getRow()- bow.getRow())+1;
		}
		return len;
	}
}

std::set<GridPosition> Ship::occupiedArea() const
{
	std::set<GridPosition> setofGridPos;
	if(bow < stern)
	{
		int pos = 0;
		//ship is horizontal
		if(bow.getRow()==stern.getRow())
		{
			for(int itr=1;itr<=(this->length());itr++)
			{
				setofGridPos.insert(GridPosition{bow.getRow(),  bow.getColumn()+pos});
				pos++;
			}
		}
		//ship is vertical
		else if(bow.getColumn()==stern.getColumn())
		{
			for(int itr=1;itr<=(this->length());itr++)
			{
				setofGridPos.insert(GridPosition{char(bow.getRow()+pos), bow.getColumn()});
				pos++;
			}
		}

	}
	else if(stern < bow)
	{
		int pos = 0;
		//ship is horizontal
		if(bow.getRow()==stern.getRow())
		{
			for(int itr=1;itr<=(this->length());itr++)
			{
				setofGridPos.insert(GridPosition{stern.getRow(), stern.getColumn()+pos});
				pos++;
			}
		}
		//ship is vertical
		else if(bow.getColumn()==stern.getColumn())
		{
			for(int itr=1;itr<=(this->length());itr++)
			{
				setofGridPos.insert(GridPosition{char(stern.getRow()+pos), stern.getColumn()});
				pos++;
			}
		}
	}
	return setofGridPos;
}

std::set<GridPosition> Ship::blockedArea() const
{
	std::set<GridPosition> blocked;
	for(const auto& pos : occupiedArea())
	{
		blocked.insert(pos);
		int row = pos.getRow();
		int col = pos.getColumn();
		for(char r = row-1; r <= row+1; r++)
		{
			for(int c = col-1; c<=col+1; c++)
			{
				blocked.insert(GridPosition(r, c));
			}
		}
	}
	return blocked;
}

