#ifndef __LEVELTHREE_H__
#define __LEVELTHREE_H__
#include "level.h"

// HumanPlayer class
class LevelThree : public Level {
    // Add private variables and methods here:
  
      
  public:
      virtual void makeMove(std::vector<Piece *>, std::vector<std::vector<Cell>> &theBoard, char) override;  // consumes the board
                                                                                            // and players pieces
    
      virtual void movePiece(std::vector<Piece *>, std::vector<std::vector<Cell>> &theBoard, char) override;
      virtual bool capturePiece(std::vector<Piece *>, std::vector<std::vector<Cell>> &theBoard, char) override;
      virtual bool canBeCaptured(int, int, std::vector<std::vector<Cell>> &theBoard, char) override;
      virtual bool avoidCapture(std::vector<Piece *>, std::vector<std::vector<Cell>> &, char) override;
};

#endif