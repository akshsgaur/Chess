#include "player.h"

Player::Player(char colour, std::vector<Piece *> pieces) : colour{colour}, pieces{pieces} {}

char Player::getColour() { return colour; }

// Helper to check if player's king is under check or not
bool Player::IsInCheck(std::vector<std::vector<Cell>> &theBoard, char colour) {
    // Find player's own king 
	int KingRow;
	int KingCol;
	for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if (theBoard[r][c].getInfo().piece) {
                if (theBoard[r][c].getInfo().piece->getColour() == this->getColour()) {
                    if ((theBoard[r][c].getInfo().piece->getType() == 'K') || (theBoard[r][c].getInfo().piece->getType() == 'k')) {
			    KingRow = r;
			    KingCol = c;
		    }
		}
	    }
	}
	}
	// Run through the opponent's pieces and see if any of them can take the king (puts our king under check)
	for (int r = 0; r < 8; ++r) {
		for (int c = 0; c < 8; ++c) {
			if (theBoard[r][c].getInfo().piece) {
				if (theBoard[r][c].getInfo().piece->getColour() != this->getColour()) {
					if (theBoard[r][c].getInfo().piece->validMove(r, c, KingRow, KingCol, theBoard)) {
						return true;
					}
				}
			}
		}
	}
    
    return false;
}
std::vector<Piece *> Player::getPieces() { return pieces; }

bool Player::CanMove(std::vector<std::vector<Cell>> &theBoard , char Colour) {
	// Run through all pieces
	for (int r = 0; r < 8; ++r) {
		for (int c = 0; c < 8; ++c) {
			if (theBoard[r][c].getInfo().piece != nullptr) {
				//cout<<"if                    1"<<endl;
		 		// If it is a piece of the current player, see if it has a legal move
				if (theBoard[r][c].getInfo().piece->getColour() == Colour) {
					//cout<<"if                 2"<<endl;
					for (int rMove = 0; rMove < 8; rMove++) {
						for (int cMove = 0; cMove < 8; cMove++) {
								//cout<<"if3"<<endl;
							if (theBoard[r][c].getInfo().piece->validMove(r, c, rMove, cMove, theBoard)){
								// Make move and check whether king is in check
                                				//cout << "hi1"<<endl;
								if (theBoard[rMove][cMove].getInfo().piece != nullptr && theBoard[rMove][cMove].getInfo().piece->getColour() != Colour) {
									Piece* pTemp	= theBoard[rMove][cMove].getInfo().piece;
									//cout<<"hi2"<<endl;
									bool temp = false;
									//cout << theBoard[r][c].getInfo().piece->getType() << endl;
									if (theBoard[r][c].getInfo().piece->getType() == 'p' || theBoard[r][c].getInfo().piece->getType() == 'P') {
										//cout << " in the if block" << endl;

									temp = theBoard[r][c].getInfo().piece->firstMove();
									}
									theBoard[r][c].getInfo().piece->movePiece(r, c, rMove, cMove, theBoard);
									//cout << "hi3"<<endl;
									//cout<< "yo  " << r<<  "  " << c << endl;
                                					//theBoard[r][c].getInfo().piece = nullptr;
									bool pCanMove = !IsInCheck(theBoard, Colour);
									//cout<<"hi4"<< "  " << rMove << "  " << cMove << endl;
									// Undo the move
									//if(theBoard[rMove][cMove].getInfo().piece != nullptr){
									theBoard[rMove][cMove].getInfo().piece->movePiece(rMove, cMove, r, c, theBoard);
									//cout<<"hi5"<<endl;
									if (theBoard[r][c].getInfo().piece->getType() == 'p' || theBoard[r][c].getInfo().piece->getType() == 'P') {
									theBoard[r][c].getInfo().piece->setfirstMove(!temp);
									}
									theBoard[rMove][cMove].setPiece(pTemp);
									//cout<<"hi6"<<endl;
									theBoard[rMove][cMove].notifyObservers();
									//cout<<"hi7"<<endl;
									//}
									if (pCanMove){
										return true;
									}
								} else if (theBoard[rMove][cMove].getInfo().piece == nullptr){
									bool temp = false;
									//cout << "======" << theBoard[r][c].getInfo().piece->getType() << endl;
									if (theBoard[r][c].getInfo().piece->getType() == 'p' || theBoard[r][c].getInfo().piece->getType() == 'P') {
									temp = theBoard[r][c].getInfo().piece->firstMove();
									}
									theBoard[r][c].getInfo().piece->movePiece(r, c, rMove, cMove, theBoard);
									//cout << "hi3"<<endl;
									//cout<< "yo  " << r<<  "  " << c << endl;
									//theBoard[r][c].getInfo().piece = nullptr;
									bool pCanMove = !IsInCheck(theBoard, Colour);
									//cout<<"hi4"<< "  " << rMove << "  " << cMove << endl;                                                                                                                       // Undo the move
								        theBoard[rMove][cMove].getInfo().piece->movePiece(rMove, cMove, r, c, theBoard);
									if (theBoard[r][c].getInfo().piece->getType() == 'p' || theBoard[r][c].getInfo().piece->getType() == 'P') {
									theBoard[r][c].getInfo().piece->setfirstMove(!temp);
									}
									//cout<<"hi5"<<endl;
								
									if (pCanMove) {
										return true;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	//}
	return false;
}
