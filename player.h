#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cell.h"
#include <iostream>
class piece;

using namespace std;

// King class
class Player {
    // Add private variables and methods here:
    char colour;
    std::vector<Piece *> pieces;

  public:
    Player(char, std::vector<Piece *>);
    virtual void makeMove(std::vector<std::vector<Cell>> &) = 0;
    virtual bool IsInCheck(std::vector<std::vector<Cell>> &theBoard, char Colour);
    virtual bool CanMove(std::vector<std::vector<Cell>> &theBoard, char Colour);
    char getColour();
    std::vector<Piece *> getPieces();

};

#endif
