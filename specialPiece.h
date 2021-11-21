#ifndef __SPECIALPIECE_H__
#define __SPECIALPIECE_H__
#include "piece.h"
#include <string>

using namespace std;

// King class
class SpecialPiece : public Piece {
    // Add private variables and methods here:
    bool firstMoveMade = false;
	public:
     SpecialPiece(char, char);
    // Add public methods here:
    void setfirstMove(bool) override;
     virtual void movePiece(int, int, int, int, std::vector<std::vector<Cell>> &) override;
     bool firstMove() override;
};

#endif
