#ifndef __KING_H__
#define __KING_H__
#include "specialPiece.h"
#include <string>

using namespace std;

// King class
class King : public SpecialPiece {
    // Add private variables and methods here:

  public:
    King(char, char);
    // Add public methods here:
     virtual bool validMove(int, int, int, int, std::vector<std::vector<Cell>> &);
};

#endif