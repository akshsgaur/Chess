#include "levelTwo.h"
#include <iostream>
#include <stdlib.h>


void LevelTwo::movePiece(std::vector<Piece *> pieces, std::vector<std::vector<Cell>> &theBoard, char playerColour)
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


bool LevelTwo::capturePiece(std::vector<Piece *> pieces, std::vector<std::vector<Cell>> &theBoard, char playerColour)
{
    for(int i = 0; i < pieces.size(); ++i){

        int rOld = pieces[i]->getCell(theBoard).getInfo().row;
        int cOld = pieces[i]->getCell(theBoard).getInfo().col;

        for(int r = 0; r < theBoard.size(); ++r)
        {
            for(int c = 0; c < theBoard.size(); ++c)
            {
                if(pieces[i]->validMove(rOld, cOld, r, c, theBoard))
                {
                    // piece exists at destination
                    if(theBoard[r][c].getInfo().piece)
                    {
                        //player's own piece"
                        if(theBoard[r][c].getInfo().piece->getColour() != playerColour)
                        {   
                            // move piece
                            pieces[i]->movePiece(rOld, cOld, r, c, theBoard);
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}


void LevelTwo::makeMove(std::vector<Piece *> pieces, std::vector<std::vector<Cell>> &theBoard, char playerColour)
{
    if(!capturePiece(pieces, theBoard, playerColour))
    {
        movePiece(pieces, theBoard, playerColour);
    }

}


bool LevelTwo::canBeCaptured(int r1, int c1, std::vector<std::vector<Cell>> &theBoard, char playerColour) {}

bool LevelTwo::avoidCapture(std::vector<Piece *> pieces, std::vector<std::vector<Cell>> &theBoard, char playerColour) {}