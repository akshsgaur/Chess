#include "pawn.h"
#include <iostream>
#include "cell.h"

using namespace std;

Pawn::Pawn(char type, char colour) : SpecialPiece(type, colour)  {}

bool Pawn::validMove(int r1, int c1, int r2, int c2,  std::vector<std::vector<Cell>> &cb)
{

	int rdiff = r1 - r2;
	int cdiff = c1 - c2;

	if (this->getColour() == 'b')
	{
		rdiff = r2 - r1;
		cdiff = c2 - c1;
	}

	if (rdiff == 0 && cdiff == 0){                                                                                                                                                        return false;                                                                                                                                                         }                                                                                                                                                                                                                                                                                                                                                           if (cb[r2][c2].getInfo().piece != nullptr && cb[r2][c2].getInfo().piece->getColour() == this->getColour()){                                                                           return false;                                                                                                                                                         }

	// To keep in check that pawn can only move 2 spaces forward on its first move and not afterwards
	if (!this->firstMove() && rdiff >= 2){ 
		//cout<<"Pawn cannot move more than 1 space after its very first move."<<endl;
		return false;
	}
	// when its first move but player tries to move the pawn on more than 2 spaces
	else if (this->firstMove() && rdiff > 2){ 
		//cout<<"Pawn can only move maximum of 2 spaces on its first move"<<endl;
		return false;
	}
	// if rdiff is negative that means pawn moved backward which is not possible and rdiff also cant be zero because pawns dont move sidewards
	else if(rdiff <=0) { 
		//cout<<"Pawn cannot move like that."<<endl;
		return false;
	}
	// pawn can only move one column (that is also when it attacks) at max
	else if(abs(cdiff) > 1){ 
		//cout<<"Pawn cannot move like that."<<endl;
		return false;
	}
	// if they try to move diagonally but there is no opponent piece there
	else if(abs(cdiff) == 1 && rdiff == 1 && cb[r2][c2].getInfo().piece == nullptr){ 
		//cout<<"There must be an enemy piece at "<<c2<<r2<<" for you to be able to move there."<<endl;
		return false;
	}
	// if they try to move 1 space forward but it is occupied by an opponent's piece
	else if (rdiff == 1 && cdiff == 0 && cb[r2][c2].getInfo().piece != nullptr && cb[r2][c2].getInfo().piece->getColour() != cb[r1][c1].getInfo().piece->getColour()){
		//cout<<"An enemy piece is blocking your move."<<endl;
		return false;
	} 
	
	return true;
}
