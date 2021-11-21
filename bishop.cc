#include "bishop.h"
#include <iostream>
#include "cell.h"

using namespace std;

Bishop::Bishop(char type, char colour) : Piece(type, colour)  {}
bool Bishop::firstMove(){
	return true;
}

bool Bishop::validMove(int r1, int c1, int r2, int c2,  std::vector<std::vector<Cell>> &cb)
{
	int rdiff = r1 - r2;
	int cdiff = c1 - c2;
	if (abs(rdiff) != abs(cdiff)) { // if bishop is not moving diagonally
		//cout<<"Bishops can only move diagonally."<<endl;
		return false;
	}

	if (rdiff == 0 && cdiff == 0){
		return false;
	}

	if (cb[r2][c2].getInfo().piece != nullptr && cb[r2][c2].getInfo().piece->getColour() == this->getColour()){
		return false;
	}





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
	// To check that path from current position to final position has no pieces in between
	if (rdiff > 0 && cdiff > 0) { // move in south west direction
		for (int i = r1-1; i > r2; i--){
			for (int j = c1-1; j > c2; j--){
				if (cb[i][j].getInfo().piece != nullptr) {
					//cout<<"There is a piece blocking the path of your move."<<endl;
					return false;
				}
			}
		}
	}
	else if (rdiff < 0 && cdiff < 0) { // move in north east direction
		for (int i = r1+1; i < r2; i++){
			for (int j = c1+1; j < c2; j++){
				if (cb[i][j].getInfo().piece != nullptr) {
					//cout<<"There is a piece blocking the path of your move."<<endl;
					return false;
				}
			}
		}
	}
	else if (rdiff > 0 && cdiff < 0) { // move in south east direction
		for (int i = r1-1; i > r2; i--){
			for (int j = c1+1; j < c2; j++){
				if (cb[i][j].getInfo().piece != nullptr) {
					//cout<<"There is a piece blocking the path of your move."<<endl;
					return false;
				}
			}
		}
	}
	else if (rdiff < 0 && cdiff > 0) { // move in north west direction
		for (int i = r1+1; i < r2; i++){
			for (int j = c1-1; j > c2; j--){
				if (cb[i][j].getInfo().piece != nullptr) {
					//cout<<"There is a piece blocking the path of your move."<<endl;
					return false;
				}
			}
		}
	}
	*/

	return true;
}
