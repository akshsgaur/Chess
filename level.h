#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <vector>
#include "piece.h"
#include "cell.h"

// HumanPlayer class
class Level {
    // Add private variables and methods here:

  public:
    virtual void makeMove(std::vector<Piece *>, std::vector<std::vector<Cell>> &theBoard, char) = 0; // consumes the board
                                                                                                // and players pieces

    virtual void movePiece(std::vector<Piece *>, std::vector<std::vector<Cell>> &theBoard, char) = 0;
    virtual bool capturePiece(std::vector<Piece *>, std::vector<std::vector<Cell>> &theBoard, char) = 0;
    virtual bool canBeCaptured(int, int, std::vector<std::vector<Cell>> &theBoard, char) = 0;
    virtual bool avoidCapture(std::vector<Piece *>, std::vector<std::vector<Cell>> &, char) = 0;
    
};

#endif