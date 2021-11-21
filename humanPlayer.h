#ifndef __HUMANPLAYER_H__
#define __HUMANPLAYER_H__
#include "player.h"
#include "board.h" // include for invalidMove(need to shift that class temp fix)
// HumanPlayer class

class HumanPlayer : public Player {
    // Add private variables and methods here:

  public:

    HumanPlayer(char, std::vector<Piece *>);
    virtual void makeMove(std::vector<std::vector<Cell>> &theBoard);
};

#endif