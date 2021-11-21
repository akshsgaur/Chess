#include "queen.h"
#include <vector>
#include <iostream>
#include "cell.h"
using namespace std;

Queen::Queen(char type, char colour) : Piece(type, colour)  {}

bool Queen::firstMove(){
	return true;
}


bool Queen::validMove(int r1, int c1, int r2, int c2,  std::vector<std::vector<Cell>> &cb)
{
	int rdiff = r1 - r2;
	int cdiff = c1 - c2;

	//if they just try to move to some random spot i.e. neither in a up-down or sideways direction nor diagonally
	if(abs(rdiff) != abs(cdiff) && rdiff != 0 && cdiff != 0){
		//cout<<"Queen cannot move like that."<<endl;
		return false;
	}

	if (rdiff == 0 && cdiff == 0){                                                                                                                                                        return false;                                                                                                                                                         }                                                                                                                                                                                                                                                                                                                                                           if (cb[r2][c2].getInfo().piece != nullptr && cb[r2][c2].getInfo().piece->getColour() == this->getColour()){                                                                           return false;                                                                                                                                                         }
	
	// To check if there is no piece in the path of the move
	if (rdiff > 0 && cdiff > 0){ // if movement is in south west direction
		for (int i = r1-1, j = c1-1; i > r2, j > c2; i--, j--){
			if (cb[i][j].getInfo().piece != nullptr){
				//cout<<"There is a piece blocking the path of your move"<<endl;
				return false;
			}
		}
	}

	else if (rdiff < 0 && cdiff < 0) {// if movement is in north east direction
		for (int i = r1+1, j = c1+1; i < r2, j < c2; i++, j++){
			if (cb[i][j].getInfo().piece != nullptr){
				//cout<<"There is a piece blocking the path of your move"<<endl;
				return false;
			}
		}
	}
	
	else if(rdiff > 0 && cdiff < 0){ // if movement is in south east direction
		for (int i = r1-1, j = c1+1; i > r2, j < c2; i--, j++){
			if (cb[i][j].getInfo().piece != nullptr){
				//cout<<"There is a piece blocking the path of your move"<<endl;
				return false;
			}
		}
	}
	
	else if(rdiff < 0 && cdiff > 0){ // if movement is in north west direction
		for (int i = r1+1, j = c1-1; i < r2, j > c2; i++, j--){
			if (cb[i][j].getInfo().piece != nullptr){
				//cout<<"There is a piece blocking the path of your move"<<endl;
				return false;
			}
		}
	}


	/*
	// To check if there is no piece in the path of the move
	if (rdiff > 0 && cdiff > 0){ // if movement is in south west direction
		for (int i = r1-1; i > r2; i--){
			for(int j = c1-1; j > c2; j--){
				if (cb[i][j].getInfo().piece != nullptr){
					//cout<<"There is a piece blocking the path of your move"<<endl;
					return false;
				}
			}
		}
	}
	else if (rdiff < 0 && cdiff < 0) {// if movement is in north east direction
		for (int i = r1+1; i < r2; i++){
			for(int j = c1+1; j < c2; j++){
				if (cb[i][j].getInfo().piece != nullptr){
					//cout<<"There is a piece blocking the path of your move"<<endl;
					return false;
				}
			}
		}
	}
	else if(rdiff > 0 && cdiff < 0){ // if movement is in south east direction
		for (int i = r1-1; i > r2; i--){
			for(int j = c1+1; j < c2; j++){
				if (cb[i][j].getInfo().piece != nullptr){
					//cout<<"There is a piece blocking the path of your move"<<endl;
					return false;
				}
			}
		}
	}
	else if(rdiff < 0 && cdiff > 0){ // if movement is in north west direction
		for (int i = r1+1; i < r2; i++){
			for(int j = c1-1; j > c2; j--){
				if (cb[i][j].getInfo().piece != nullptr){
					//cout<<"There is a piece blocking the path of your move"<<endl;
					return false;
				}
			}
		}
	}
	*/

	else if(rdiff == 0 && cdiff > 0){ // if movement is in west direction
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

