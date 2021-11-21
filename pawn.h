#ifndef __PAWN_H__
#define __PAWN_H__
#include "specialPiece.h"
#include <string>

using namespace std;

// Pawn Class
class Pawn : public SpecialPiece {
    // Add private variables and methods here:

  public:
    Pawn(char, char);
    // Add public methods here:
     virtual bool validMove(int, int, int, int, std::vector<std::vector<Cell>> &);

};

#endif