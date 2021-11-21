#include "specialPiece.h"
#include <iostream>
#include "cell.h"

SpecialPiece::SpecialPiece(char type, char colour) : Piece(type, colour)  {}

bool SpecialPiece::firstMove(){ return !firstMoveMade; }

void SpecialPiece::setfirstMove(bool val){firstMoveMade = val; }

void SpecialPiece::movePiece(int r1, int c1, int r2, int c2, std::vector<std::vector<Cell>> &cb)
{
    //cout << "move for special piece called: " << endl;
    if(this->firstMove())
    {
        firstMoveMade = true;
    }
    else
    {
        
    }
    
    cout << "piece at row: " << r1 << " column: " << c1 << " moved to row: " << r2 << " column: " << c2 << endl;

    cb[r2][c2].setPiece(cb[r1][c1].getInfo().piece);
    cb[r2][c2].notifyObservers();
    
    cb[r1][c1].setPiece(nullptr);
    cb[r1][c1].notifyObservers();

}
