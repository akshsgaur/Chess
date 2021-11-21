#include "computerPlayer.h"


ComputerPlayer::ComputerPlayer(char colour, std::vector<Piece *> pieces, Level *level) : Player(colour, pieces), level(level) {}


void ComputerPlayer::makeMove(std::vector<std::vector<Cell>> &theBoard)
{
    level->makeMove(getPieces(), theBoard, getColour());
}