#ifndef __KNIGHT_H__
#define __KNIGHT_H__
#include "piece.h"
#include <string>

using namespace std;

// Knight class
class Knight : public Piece {
    // Add private variables and methods here:

  public:
    Knight(char, char);
    // Add public methods here:
     virtual bool validMove(int, int, int, int, std::vector<std::vector<Cell>> &);
     bool firstMove() override;

};

#endif