#include "king.h"
#include <iostream>
#include "cell.h"

using namespace std;

King::King(char type, char colour) : SpecialPiece(type, colour)  {}


bool King::validMove(int r1, int c1, int r2, int c2,  std::vector<std::vector<Cell>> &cb)
{   
	int rdiff = r1 - r2;
	int cdiff = c1 - c2;

	if (this->firstMove() == true && cdiff == -2 && cb[r1][c1+1].getInfo().piece == nullptr && cb[r1][c1+2].getInfo().piece == nullptr && (cb[r1][c1+3].getInfo().piece->getType() == 'r' || cb[r1][c1+3].getInfo().piece->getType() == 'R') && cb[r1][c1+3].getInfo().piece->firstMove() == true){
		return true;
	}

	if (this->firstMove() == true && cdiff == 2 && cb[r1][c1-1].getInfo().piece == nullptr && cb[r1][c1-2].getInfo().piece == nullptr && cb[r1][c1-3].getInfo().piece == nullptr &&  cb[r1][c1-4].getInfo().piece->getType() == 'R' && cb[r1][c1-4].getInfo().piece->firstMove() == true){
		//cout<<"here"<<endl;
		return true;
	}

	if (this->firstMove() == true && cdiff == 2 && cb[r1][c1-1].getInfo().piece == nullptr && cb[r1][c1-2].getInfo().piece == nullptr && cb[r1][c1-3].getInfo().piece == nullptr && cb[r1][c1-4].getInfo().piece->getType() == 'r' && cb[r1][c1-4].getInfo().piece->firstMove() == false){
		return true;
	} 


	if (abs(rdiff) > 1 || abs(cdiff) > 1) 
    { // if king is moving more than one space at a time
		//cout<<"King may only move one space at a time."<<endl;
		return false;
	
	}

	if (rdiff == 0 && cdiff ==0){
		return false;                                                                                                                                                         } 


	if (cb[r2][c2].getInfo().piece != nullptr && cb[r2][c2].getInfo().piece->getColour() == this->getColour()){
		//cout<<"dsvafbgfh"<<endl;
		return false;                                                                                                                                                         }

    return true;
}
