#ifndef __LEVELONE_H__
#define __LEVELONE_H__
#include "level.h"

// HumanPlayer class
class LevelOne : public Level {
    // Add private variables and methods here:

  public:
    virtual void makeMove(std::vector<Piece *>, std::vector<std::vector<Cell>> &theBoard, char); // consumes the board
                                                                                                // and players pieces

    virtual void movePiece(std::vector<Piece *>, std::vector<std::vector<Cell>> &theBoard, char);
    virtual bool capturePiece(std::vector<Piece *>, std::vector<std::vector<Cell>> &theBoard, char);
    virtual bool canBeCaptured(int, int, std::vector<std::vector<Cell>> &theBoard, char);
    virtual bool avoidCapture(std::vector<Piece *>, std::vector<std::vector<Cell>> &, char);
    
   
};

#endif