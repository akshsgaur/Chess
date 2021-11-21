#ifndef __COMPUTERPLAYER_H__
#define __COMPUTERPLAYER_H__
#include "player.h"
#include "level.h"

// HumanPlayer class
class ComputerPlayer : public Player {
    // Add private variables and methods here:

  Level *level = nullptr; 
  public:
    ComputerPlayer(char, std::vector<Piece *>, Level *);
    virtual void makeMove(std::vector<std::vector<Cell>> &theBoard);
    
};

#endif