#include "knight.h"
#include <iostream>
#include <cstdlib>
#include "cell.h"

using namespace std;

Knight::Knight(char type, char colour) : Piece(type, colour)  {}
bool Knight::firstMove(){
	return true;
}

bool Knight::validMove(int r1, int c1, int r2, int c2,  std::vector<std::vector<Cell>> &cb)
{
    int rdiff = r1 - r2;
	int cdiff = c1 - c2;

	if (abs(rdiff)*abs(cdiff) != 2) 
    {

		//cout<<"Knight don't move like that."<< endl;
		return false;
	}

	if (rdiff == 0 && cdiff == 0){                                                                                                                                                        return false;                                                                                                                                                         }                                                                                                                                                                                                                                                                                                                                                           if (cb[r2][c2].getInfo().piece != nullptr && cb[r2][c2].getInfo().piece->getColour() == this->getColour()){                                                                           return false;                                                                                                                                                         }

    return true;
}
