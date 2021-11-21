#include "cell.h"
#include "piece.h"
#include <iostream>

// Constructor
Cell::Cell(size_t r, size_t c) : r(r), c(c) {}


// setting a piece
void Cell::setPiece(Piece *piece)  
{
    this->unsetPiece();
    this->piece = piece;

}

void Cell::unsetPiece() 
{
    Piece *temp = this->piece;
    this->piece = nullptr;
    delete piece;
}

void Cell::setColour(Colour colour) 
{
    this->colour = colour;
}

// Notify
void Cell::notify(Subject<Info, State> &whoFrom)  
{
}

// getInfo
// returns the information of the cell
Info Cell::getInfo() const 
{
    Info inf;
    inf.row = r;
    inf.col = c;
    inf.colour = colour;
    inf.piece = piece;

    return inf;
}

