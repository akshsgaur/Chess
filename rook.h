#ifndef __ROOK_H__
#define __ROOK_H__
#include "piece.h"
#include "specialPiece.h"
#include <string>

using namespace std;

// Knight class
class Rook : public SpecialPiece {
    // Add private variables and methods here:

  public:
    Rook(char, char);
    // Add public methods here:
     virtual bool validMove(int, int, int, int, std::vector<std::vector<Cell>> &);

};

#endif