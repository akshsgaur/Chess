#ifndef __QUEEN_H__
#define __QUEEN_H__
#include "piece.h"
#include <string>

using namespace std;

// Knight class
class Queen : public Piece {
    // Add private variables and methods here:

  public:
    Queen(char, char);
    // Add public methods here:
    virtual bool validMove(int, int, int, int, std::vector<std::vector<Cell>> &);
    bool firstMove() override;

};

#endif