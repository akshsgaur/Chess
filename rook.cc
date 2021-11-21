#include "rook.h"
#include "cell.h"
#include <iostream>

using namespace std;



Rook::Rook(char type, char colour) : SpecialPiece(type, colour)  {}

bool Rook::validMove(int r1, int c1, int r2, int c2,  std::vector<std::vector<Cell>> &cb)
{
	int rdiff = r1 - r2;
	int cdiff = c1 - c2;

	if(rdiff != 0 && cdiff !=0){
		//cout<<"Rookcannot move like this."<<endl;
		return false;
	}

	if (rdiff == 0 && cdiff == 0){                                                                                                                                                        return false;                                                                                                                                                         }                                                                                                                                                                                                                                                                                                                                                           if (cb[r2][c2].getInfo().piece != nullptr && cb[r2][c2].getInfo().piece->getColour() == this->getColour()){                                                                           return false;                                                                                                                                                         }

	// To check if there is no piece in the path of the move
	if(rdiff == 0 && cdiff > 0){ // if movement is in west direction
		for (int i = c1-1; i > c2; i--){
			if (cb[r1][i].getInfo().piece != nullptr){
				//cout<<"There is a piece blocking the path of your move"<<endl;
				return false;
			}
		}
	}
	else if(rdiff == 0 && cdiff < 0){ // if movement is in east direction
		for (int i = c1+1; i < c2; i++){
			if (cb[r1][i].getInfo().piece != nullptr){
				//cout<<"There is a piece blocking the path of your move"<<endl;
				return false;
			}
		}
	}
	else if(rdiff > 0 && cdiff == 0){ // if movement is in south direction
		for (int i = r1-1; i > r2; i--){
			if (cb[i][c1].getInfo().piece != nullptr){
				//cout<<"There is a piece blocking the path of your move"<<endl;
				return false;
			}
		}
	}
	else if(rdiff < 0 && cdiff == 0){ // if movement is in north direction
		for (int i = r1+1; i < r2; i++){
			if (cb[i][c1].getInfo().piece != nullptr){
				//cout<<"There is a piece blocking the path of your move"<<endl;
				return false;
			}
		}
	}

	return true;
}
