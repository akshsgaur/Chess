#include "levelFour.h"
#include <iostream>
#include <stdlib.h>


void LevelFour::movePiece(std::vector<Piece *> pieces, std::vector<std::vector<Cell>> &theBoard, char playerColour)
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


bool LevelFour::capturePiece(std::vector<Piece *> pieces, std::vector<std::vector<Cell>> &theBoard, char playerColour)
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

// if any of our pieces can be captured in original position
// if moving a piece puts our piece in the capture position

bool LevelFour::canBeCaptured(int rOld, int cOld, std::vector<std::vector<Cell>> &theBoard, char playerColour)
{

    for(int r = 0; r < theBoard.size(); ++r)
    {
        for(int c = 0; c < theBoard.size(); ++c)
        {
            // if our original piece can be captured
            if(theBoard[r][c].getInfo().piece)
            {
                if(theBoard[r][c].getInfo().piece->getColour() != playerColour)
                {
                    if(theBoard[r][c].getInfo().piece->validMove(r, c, rOld, cOld, theBoard))
                    {
                        return true;
                    }
                }
            }
            
        }
    }

    return false;
}

bool LevelFour::avoidCapture(std::vector<Piece *> pieces, std::vector<std::vector<Cell>> &theBoard, char playerColour)
{
    for(int i = 0; i < pieces.size(); ++i)
    {
         int rOld = pieces[i]->getCell(theBoard).getInfo().row;
         int cOld = pieces[i]->getCell(theBoard).getInfo().col;

        // if piece is under attack
        if(canBeCaptured(rOld, cOld, theBoard, playerColour))
        {
            for(int r = 0; r < theBoard.size(); ++r)
            {
                for(int c = 0; c < theBoard.size(); ++c)
                {
                    // this piece has a valid move
                    if(pieces[i]->validMove(rOld, cOld, r, c, theBoard))
                    {
                        // piece exists at the destination
                        if(theBoard[r][c].getInfo().piece)
                        {
                            // the destination piece is opponents
                            if(theBoard[r][c].getInfo().piece->getColour() != playerColour)
                            {
                                // we capture the opponents piece and make our move
                                pieces[i]->movePiece(rOld, cOld, r, c, theBoard);
                                return true;
                            }
                        }
                        // no piece exists at the destination
                        else
                        {
                            // if this move does not put our piece under attack
                            if(!canBeCaptured(r, c, theBoard, playerColour))
                            {
                                pieces[i]->movePiece(rOld, cOld, r, c, theBoard);
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}


void LevelFour::makeMove(std::vector<Piece *> pieces, std::vector<std::vector<Cell>> &theBoard, char playerColour)
{
    if(!avoidCapture(pieces, theBoard, playerColour))
    {
        if(!capturePiece(pieces, theBoard, playerColour))
        {
            movePiece(pieces, theBoard, playerColour);
        }
    }

}
