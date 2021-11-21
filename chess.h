#ifndef __CHESS_H__
#define __CHESS_H__

#include "board.h"
#include "player.h"
#include "humanPlayer.h"
#include "computerPlayer.h"
#include "piece.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"
#include <iostream>

using namespace std;


// King class
class Chess {
    // Add private variables and methods here:
    Board b;
    int size = 8;
    Player *whitePlayer;
    Player *blackPlayer;
    bool boardInitialized = false;
    bool whitePlayerTurn = true;
    std::vector<Piece *> whitePieces;
    std::vector<Piece *> blackPieces;


  public:
    void gameSetup(string);
    void runGame();
    ~Chess();

};

#endif