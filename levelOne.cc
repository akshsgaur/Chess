#include "levelOne.h"
#include <iostream>
#include <stdlib.h>


void LevelOne::movePiece(std::vector<Piece *> pieces, std::vector<std::vector<Cell>> &theBoard, char playerColour)
{
        // level one
    bool moveMade = false;

    while(!moveMade)
    {
        int randomPosition = (rand() % pieces.size());
        Piece *randomPiece = pieces[randomPosition];

        
        int rOld = randomPiece->getCell(theBoard).getInfo().row;
        int cOld = randomPiece->getCell(theBoard).getInfo().col;
        int rNew = (rand() % 8);
        int cNew = (rand() % 8);

        if (randomPiece->validMove(rOld, cOld, rNew, cNew, theBoard))
        {
            // piece exists at destination
            if(theBoard[rNew][cNew].getInfo().piece)
            {
                //player's own piece"
                if(theBoard[rNew][cNew].getInfo().piece->getColour() != playerColour)
                    {
                        // move piece
                        randomPiece->movePiece(rOld, cOld, rNew, cNew, theBoard);
                        moveMade = true;
                    }
            }
            else
            {
                randomPiece->movePiece(rOld, cOld, rNew, cNew, theBoard);
                moveMade = true;
            }

        }
    }
}
void LevelOne::makeMove(std::vector<Piece *> pieces, std::vector<std::vector<Cell>> &theBoard, char playerColour)
{
    this->movePiece(pieces, theBoard, playerColour);
}


bool LevelOne::capturePiece(std::vector<Piece *> pieces, std::vector<std::vector<Cell>> &theBoard, char player) {}

bool LevelOne::canBeCaptured(int r1, int c1, std::vector<std::vector<Cell>> &theBoard, char playerColour) {}

bool LevelOne::avoidCapture(std::vector<Piece *> pieces, std::vector<std::vector<Cell>> &theBoard, char playerColour) {}