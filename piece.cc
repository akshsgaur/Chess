#include "piece.h"
#include <iostream>
#include "cell.h"

using namespace std;

Piece::Piece(char type, char colour) : type{type}, colour{colour} {}

char Piece::getColour() { return colour; }

char Piece::getType() { return type; }

int Piece::getValue() { return value; }

void Piece::setfirstMove(bool val) {}

void Piece::movePiece(int r1, int c1, int r2, int c2, std::vector<std::vector<Cell>> &cb) {

        cout << "piece at row: " << r1 << " column: " << c1 << " moved to row: " << r2 << " column: " << c2 << endl;

		cb[r2][c2].setPiece(cb[r1][c1].getInfo().piece);
		cb[r2][c2].notifyObservers();
		
		// need to delete the piece here
		cb[r1][c1].setPiece(nullptr);
		cb[r1][c1].notifyObservers();



}

Cell &Piece::getCell(std::vector<std::vector<Cell>> &cb)
{

	for(int i = 0; i < 8; ++i)
	{
		for(int j = 0; j < 8; ++j)
		{
			if(cb[i][j].getInfo().piece == this)
			{
				return cb[i][j];
			}
		}
	}

	// shouldnt be possible so throw an error
}
