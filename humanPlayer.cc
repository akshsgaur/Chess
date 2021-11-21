#include "humanPlayer.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"
#include <iostream>

using namespace std;

HumanPlayer::HumanPlayer(char colour, std::vector<Piece *> pieces) : Player(colour, pieces) {}

void pawnPromotion(std::vector<std::vector<Cell>> &theBoard, int r1, int c1, int r2, int c2 ,string newPiece, char colour){
   if(colour == 'w'){
    Piece* p;
    if(newPiece == "B"){
        p = new Bishop('B','w');
        theBoard[r2][c2].setPiece(p);  
    }
    if(newPiece == "R"){
        p = new Rook('R','w');
        theBoard[r2][c2].setPiece(p); 
        }
    if(newPiece == "K"){
        p = new Knight('N','w');
        theBoard[r2][c2].setPiece(p); 
        
        }
    if(newPiece == "Q"){
        p = new Queen('Q','w');
        theBoard[r2][c2].setPiece(p); 
    }
    theBoard[r2][c2].notifyObservers();
    theBoard[r1][c1].setPiece(nullptr);
    theBoard[r1][c1].notifyObservers();
   }
   else {
       Piece* p;
       if(newPiece == "b"){
        p = new Bishop('b','b');
        theBoard[r2][c2].setPiece(p); 
        }
        if(newPiece == "r"){
        p = new Rook('r','b');
        theBoard[r2][c2].setPiece(p);    
        }
        if(newPiece == "k"){
        p = new Knight('n','b');
        theBoard[r2][c2].setPiece(p);      
        }
        if(newPiece == "q"){
        p = new Queen('q','b');
        theBoard[r2][c2].setPiece(p);     
        }
        theBoard[r2][c2].notifyObservers();
        theBoard[r1][c1].setPiece(nullptr);
        theBoard[r1][c1].notifyObservers();
    }
}



void HumanPlayer::makeMove(std::vector<std::vector<Cell>> &theBoard)
{
    int size = 8; // need to fix the player access to size
    
    int r1 = 0, r2 = 0;
    char c1 = 'a', c2 = 'a';

    int rOld = 0, cOld = 0, rNew = 0, cNew = 0;
    cin >> c1 >> r1 >> c2 >> r2; // read the row and column value

    cOld = c1 - 'a';
    rOld = 8- r1;

    cNew = c2 - 'a';
    rNew = 8 -r2;

    if(!((rOld >= 0) && (rOld <= (size - 1)) && (cOld >= 0) && (cOld <= (size - 1))))
    {
        // Invalid Move:
        cout << "Invalid source coordinates" << endl;
        throw InvalidMove{};

    }
    else if (!((rNew >= 0) && (rNew <= (size - 1)) && (cNew >= 0) && (cNew <= (size - 1))))
    {
        // Invalid Move:
        cout << "Invalid final location coordinates" << endl;
        throw InvalidMove{};   
    }
    else 
    {   
        if(theBoard[rOld][cOld].getInfo().piece)
        {   
            if(theBoard[rOld][cOld].getInfo().piece->getColour() != this->getColour())
            {
                //Invalid move:
                cout << "You cannot move the opponent's piece!" << endl;
                throw InvalidMove{};  
            }
    
            else
            {   
                if(theBoard[rOld][cOld].getInfo().piece->validMove(rOld, cOld, rNew, cNew, theBoard))
                {

                    // piece exists at destination
                    if(theBoard[rNew][cNew].getInfo().piece)
                    {
                        //player's own piece"
                        if(theBoard[rNew][cNew].getInfo().piece->getColour() == this->getColour())
                        {
                            //Invalid move:
                            cout << "Your own piece exists at the destination!" << endl;
                            throw InvalidMove{};

                        }
                        // capture piece
                        else if(theBoard[rOld][cOld].getInfo().piece->getType() == 'P' && rNew == 0)
                        {
                            string newPiece; 
                            cin >> newPiece;
                            pawnPromotion(theBoard,  rOld,  cOld,  rNew, cNew ,newPiece, 'w');
                        }
                        else if(theBoard[rOld][cOld].getInfo().piece->getType() == 'p' && rNew == 7)
                        {
                            string newPiece; 
                            cin >> newPiece;
                            pawnPromotion(theBoard, rOld, cOld, rNew, cNew ,newPiece, 'b');
                        }
                        else
                        {
                            // we capture the piece *** for now just movePiece ***
                            Piece* ptemp =  theBoard[rNew][cNew].getInfo().piece;
                            theBoard[rOld][cOld].getInfo().piece->movePiece(rOld, cOld, rNew, cNew, theBoard);
                            if (this->IsInCheck(theBoard, this->getColour()) == false) { // if king is not under check then we are good
                                cout << "successful piece capture by human Player" << endl;
                                ptemp=nullptr;
                            }
                            else 
                            { // if king comes under check then we undo the move
                                theBoard[rNew][cNew].getInfo().piece->movePiece(rNew, cNew, rOld, cOld, theBoard);
				                theBoard[rNew][cNew].setPiece(ptemp);
                                cout << "You cannot move this piece in this manner as it puts King in check" << endl;
                                throw InvalidMove{};
                            }
                            
                        }
                           
                    }
                    else
                    {
                        if(theBoard[rOld][cOld].getInfo().piece->getType() == 'P' && rNew == 0){
                            string newPiece; 
                            cin >> newPiece;
                            pawnPromotion(theBoard, rOld,  cOld, rNew, cNew ,newPiece, 'w');
                        }
                        else if(theBoard[rOld][cOld].getInfo().piece->getType() == 'p' && rNew == 7)
                        {
                            string newPiece; 
                            cin >> newPiece;
                            pawnPromotion(theBoard, rOld, cOld, rNew,cNew,newPiece, 'b');
                        }
                        else {
			           Piece* ptemp = theBoard[rNew][cNew].getInfo().piece;
                        if ((theBoard[rOld][cOld].getInfo().piece->getType() == 'k' || theBoard[rOld][cOld].getInfo().piece->getType() == 'K') && abs(cOld - cNew) == 2){
                            int cdiff = cOld - cNew;
                            //cout<<"start"<<endl;
			    bool flag = false;
                            if (cdiff<0){
                                while(cOld != cNew && !this->IsInCheck(theBoard, this->getColour())) {
				
                                    theBoard[rOld][cOld].getInfo().piece->movePiece(rOld, cOld, rOld, cOld+1, theBoard);
				    
                                    cOld+=1;
                                }
                                if(cOld == cNew && !this->IsInCheck(theBoard, this->getColour())) {
                                    flag = true;
                                }
                            } else if (cdiff>0){
                                while(cOld != cNew && !this->IsInCheck(theBoard, this->getColour())) {
                                    theBoard[rOld][cOld].getInfo().piece->movePiece(rOld, cOld, rOld, cOld-1, theBoard);
                                    cOld-=1;
                                }
                                if(cOld == cNew && !this->IsInCheck(theBoard, this->getColour())) {
                                    flag = true;
                                }
                            }
			
                            if(flag) {
                                if (cdiff<0){
			
                                    theBoard[rOld][7].getInfo().piece->movePiece(rOld, 7, rOld, 5, theBoard);
                                } else if (cdiff>0){
                                    theBoard[rOld][0].getInfo().piece->movePiece(rOld, 0, rOld, 3, theBoard);
                                }
                            } else {
                                theBoard[rOld][cOld].getInfo().piece->movePiece(rOld, cOld, rOld, 4, theBoard);
                                cout << "Invalid Castle Move" << endl;
                            }

                        } else{
			            theBoard[rOld][cOld].getInfo().piece->movePiece(rOld, cOld, rNew, cNew, theBoard);
			
                            if (this->IsInCheck(theBoard, this->getColour()) == false) { // if king not in check
                                // movePiece
                                cout << "successful move by human Player" << endl;
                                ptemp=nullptr;   
                            }
                            else {
                                // if king comes in check then we throw exception
			                    theBoard[rNew][cNew].getInfo().piece->movePiece(rNew, cNew, rOld, cOld, theBoard);
			                    theBoard[rNew][cNew].setPiece(ptemp);
                                theBoard[rNew][cNew].notifyObservers();
                                cout << "You cannot move this piece in this manner as it puts King in check" << endl;
                                throw InvalidMove{};
                            }
                        
			}
			}
                    }
                }
                else
                {
                    cout << "You cannot move the piece in this manner" << endl;
                    throw InvalidMove{};
                }
                
            }
            
        }
        else
        {
            // Invalid Move
            cout << "no Piece exists at the source coordinates" << endl;
            throw InvalidMove{};
        }
    }
}
