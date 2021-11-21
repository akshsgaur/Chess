#include "chess.h"
#include <iostream>
#include <string>
#include "level.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "levelThree.h"
#include "levelFour.h"

using namespace std;

Chess::~Chess()
{

    delete whitePlayer;
    delete blackPlayer;

}

void displayScore(int whiteScore, int blackScore)
{
    cout << "Final Score: " << endl;
    cout << "White: " << whiteScore << endl;
    cout << "Black: " << blackScore << endl;
}

void Chess::gameSetup(string set="")
{
    // generate pieces:

    //Pieces for white

    Piece *rookLeftW = new Rook('R', 'w');
    Piece *knightLeftW = new Knight('N', 'w');
    Piece *bishopLeftW = new Bishop('B', 'w');
    Piece *kingW = new King('K', 'w');
    Piece *queenW = new Queen('Q', 'w');
    Piece *bishopRightW = new Bishop('B', 'w');
    Piece *knightRightW = new Knight('N', 'w');
    Piece *rookRightW = new Rook('R', 'w');

    whitePieces.push_back(rookLeftW);
    whitePieces.push_back(knightLeftW);
    whitePieces.push_back(bishopLeftW);
    whitePieces.push_back(queenW);
    whitePieces.push_back(kingW);
    whitePieces.push_back(bishopRightW);
    whitePieces.push_back(knightRightW);
    whitePieces.push_back(rookRightW);

    for(int i = 0; i < size; ++i)
    {
        Piece *pawn = new Pawn('P', 'w');
        whitePieces.push_back(pawn);
    }

    // Pieces for black:

    Piece *rookLeftB = new Rook('r', 'b');
    Piece *knightLeftB = new Knight('n', 'b');
    Piece *bishopLeftB = new Bishop('b', 'b');
    Piece *kingB = new King('k', 'b');
    Piece *queenB = new Queen('q', 'b');
    Piece *bishopRightB = new Bishop('b', 'b');
    Piece *knightRightB = new Knight('n', 'b');
    Piece *rookRightB = new Rook('r', 'b');
    
    blackPieces.push_back(rookLeftB);
    blackPieces.push_back(knightLeftB);
    blackPieces.push_back(bishopLeftB);
    blackPieces.push_back(queenB);
    blackPieces.push_back(kingB);
    blackPieces.push_back(bishopRightB);
    blackPieces.push_back(knightRightB);
    blackPieces.push_back(rookRightB);

    for(int i = 0; i < size; ++i)
    {
        Piece *pawn = new Pawn('p', 'b');
        blackPieces.push_back(pawn);
    }

    // set up a new grid:
    b.init(size);
  
    // set pieces for black and white players:
    for(int i = 0; i < size*2; ++i)
    {
        if(i < size)
        {
            b.setPiece(0, i, blackPieces[i]);
            b.setPiece(7, i, whitePieces[i]);
        }
        else
        {
            b.setPiece(1, i - size, blackPieces[i]);
            b.setPiece(6, i - size, whitePieces[i]);
        }
    }

    if(set == "setup")
    {
      
        string sign;
        bool completed = false;
        while(!completed)
        {
            try
            {
                cin >> sign;
                if(sign == "+")
                {
                    char pieceName;
                    char c = 'a';
                    int r = '1';
                    cin >> pieceName >> c >> r;
                    int col = c - 'a';
                    int row = 8 - r;
                    Piece *np = nullptr;
                    switch(pieceName)
                        {
                            case 'K': np = new King('K', 'w'); break;
                            case 'Q': np = new Queen('Q', 'w'); break;
                            case 'B': np = new Bishop('B', 'w'); break;
                            case 'N': np = new Knight('N', 'w'); break;
                            case 'R': np = new Rook('R', 'w'); break;
                            case 'P': np = new Pawn('P', 'w'); break;
                            case 'k': np = new King('k', 'b'); break;
                            case 'q': np = new Queen('q', 'b'); break;
                            case 'b': np = new Bishop('b', 'b'); break;
                            case 'n': np = new Knight('n', 'b'); break;
                            case 'r': np = new Rook('r', 'b'); break;
                            case 'p': np = new Pawn('p', 'b'); break;
                        
                        }
                    
                    // check for valid coordinates:
                    b.setPiece(row, col, np);
                    
                    //add the piece to the array:
                    if(np->getColour() == 'w')
                    {
                        whitePieces.push_back(np);
                    }
                    else
                    {
                        blackPieces.push_back(np);
                    }
                    
                    
                    cout << b;

                }
                else if(sign == "-")
                {

                    char c = 'a';
                    int r = '1';
                    cin >> c >> r;
                    int col = c - 'a';
                    int row = 8 - r;

                    // remove the piece from the player's hand:
                    if(b.getBoard()[row][col].getInfo().piece)
                    {
                        if(b.getBoard()[row][col].getInfo().piece->getColour() == 'w')
                        {
                            for(int i = 0; i < whitePieces.size(); ++i)
                            {
                                if(whitePieces[i] == b.getBoard()[row][col].getInfo().piece)
                                {
                                    Piece *ptemp = whitePieces[i];
                                    whitePieces[i] = whitePieces[whitePieces.size() - 1];
                                    delete ptemp;
                                    whitePieces.pop_back();
                                }
                            }
                        }
                        else
                        {
                            for(int i = 0; i < blackPieces.size(); ++i)
                            {
                                if(blackPieces[i] == b.getBoard()[row][col].getInfo().piece)
                                {
                                    Piece *ptemp = blackPieces[i];
                                    blackPieces[i] = blackPieces[blackPieces.size() - 1];
                                    delete ptemp;
                                    blackPieces.pop_back();
                                }
                            }
                        }
                    }
                    
                    // check for valid coordinates:
                    b.unsetPiece(row, col);
                    cout << b;  
                }

                else if(sign == "=")
                {
                    // check for valid color
                    char colour;
                    cin >> colour;
                    if(colour == 'w')
                    {
                        whitePlayerTurn = true;
                    }
                    else if(colour == 'b')
                    {
                        whitePlayerTurn = false;
                    }
                }
                else if(sign == "done")
                {
                    // board contains exactly one white King and one black King
                    // no pawns on the first or last row of the board
                    // neither king is in check
                    int blackKings = 0, whiteKings = 0, invalidWhitePawns = 0, invalidBlackPawns = 0;

                    for(int i = 0; i < size; ++i)
                    {
                        for(int j = 0; j < size; ++j)
                        {
                            if(((b.getBoard())[i][j]).getInfo().piece)
                            {
                                if(((b.getBoard())[i][j]).getInfo().piece->getType() == 'K')
                                {
                                    ++whiteKings;
                                }
                                if(((b.getBoard())[i][j]).getInfo().piece->getType() == 'k')
                                {
                                    ++blackKings;
                                }
                                if(((b.getBoard())[i][j]).getInfo().piece->getType() == 'P' && i != 6)
                                {
                                    ++invalidWhitePawns;
                                }

                                if(((b.getBoard())[i][j]).getInfo().piece->getType() == 'p' && i != 1)
                                {
                                    ++invalidBlackPawns;
                                }
                            }
                        }
                    }

                    if(blackKings > 1){
                        cout << "Cannot escape setup mode! You have more than one black Kings on the board" << endl;
                    }
                    else if(whiteKings > 1){
                        cout << "Cannot escape setup mode! You have more than one white Kings on the board" << endl;
                    }
                    else if(invalidWhitePawns)
                    {
                        cout << "Cannot escape setup mode! You have white pawn(s) at invalid position on the board" << endl;
                    }
                    else if(invalidBlackPawns)
                    {
                        cout << "Cannot escape setup mode! You have black pawn(s) at invalid position on the board" << endl;
                    }
                    //else if(whitePlayer->IsInCheck(b.getBoard(), 'w'))
                    //{
                        //cout << "Cannot escape setup mode! white king is in check" << endl;
                    //}
                    //else if(blackPlayer->IsInCheck(b.getBoard(), 'b'))
                    //{
                        //cout << "Cannot escape setup mode! black king is in check" << endl;
                    //}
                    else
                    {
                        completed = true;
                        cout << "Exiting setup mode" << endl;
                    }
                }
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
} 

void Chess::runGame() 
{
    string cmd;
    bool boardInitialized = false;
    bool gameStarted = false;

    int whiteScore = 0;
    int blackScore = 0;

    try {
        while (true) 
        {
            cin >> cmd;
            if (cmd == "game") 
            {

                string wP = "-h", bP = "-h";
                cin >> wP;
                cin >> bP;

                // set my players
                if(wP =="-h") 
                {
                    cout << "white Player is Human" << endl;
                    whitePlayer = new HumanPlayer('w', whitePieces);
                }
                else if(wP == "-c1")
                {
                    cout << "white Player is Computer Level One" << endl;
                    whitePlayer = new ComputerPlayer('w', whitePieces, new LevelOne);
                }
                else if(wP == "-c2")
                {
                    cout << "white Player is Computer Level Two" << endl;
                    whitePlayer = new ComputerPlayer('w', whitePieces, new LevelTwo);
                }

                else if(wP == "-c3")
                {
                    cout << "white Player is Computer Level Three" << endl;
                    whitePlayer = new ComputerPlayer('w', whitePieces, new LevelThree);
                }
                    else if(wP == "-c4")
                {
                    cout << "white Player is Computer Level Four" << endl;
                    whitePlayer = new ComputerPlayer('w', whitePieces, new LevelFour);
                }

                if(bP =="-h") 
                {
                    cout << "Black player is Human" << endl;
                    blackPlayer = new HumanPlayer('b', blackPieces);
                }
                else if(bP == "-c1")
                {
                    cout << "Black player is Computer Level One" << endl;
                    blackPlayer = new ComputerPlayer('b', blackPieces, new LevelOne);
                }

                else if(bP == "-c2")
                {
                    cout << "Black player is Computer Level Two" << endl;
                    blackPlayer = new ComputerPlayer('b', blackPieces, new LevelTwo);
                }

                else if(bP == "-c3")
                {
                    cout << "Black player is Computer Level Three" << endl;
                    blackPlayer = new ComputerPlayer('b', blackPieces, new LevelThree);
                }
                    else if(bP == "-c4")
                {
                    cout << "Black player is Computer Level Four" << endl;
                    blackPlayer = new ComputerPlayer('b', blackPieces, new LevelFour);
                }
                

                gameSetup();

                boardInitialized = true;
                gameStarted = true;
                cout << b;


            }
            else if (cmd == "move") 
            {

                if(boardInitialized) {
                    if(whitePlayerTurn)
                    { if (whitePlayer->CanMove(b.getBoard(), 'w')){
									  cout<<"white player makes the move"<<endl;
									  try{whitePlayer->makeMove(b.getBoard());}
									  catch(InvalidMove){continue;}
								  }
		    else {
			    if(whitePlayer->IsInCheck(b.getBoard(), 'w')){
				    cout<< "Checkmate, Black wins the game!"<< endl;
				    cout<< "Type game to start new game"<<endl;
			    }
			    else{
				    cout<<"Stalemate"<<endl;
			    }
		    }
		    }
		    else {
			   if (blackPlayer->CanMove(b.getBoard(), 'b')){
				  cout<<"black player makes the move"<<endl;
				  try{blackPlayer->makeMove(b.getBoard());}
				  catch(InvalidMove){continue;}
			   }
			   else {
				   if (blackPlayer->IsInCheck(b.getBoard(), 'b')){
					   cout<<"Checkmate, white wins the game"<<endl;
					   cout<<"Type game to start new game"<<endl;
				   }
				   else {
					   cout<<"Stalemate"<<endl;
				   }
			   }
		    }


                    // switch turns:
                    whitePlayerTurn = !whitePlayerTurn;
                    
                    cout << b; // print the board after a turn

                }
            }
            else if (gameStarted && cmd == "resign") 
            {
                if(whitePlayerTurn)
                {
                    ++blackScore;
                    cout << "black player wins!" << endl;
                }
                else
                {
                    ++whiteScore;
                    cout << "white player wins!" << endl;
                }
                
                // reset the variables
                whitePlayerTurn = true;
                boardInitialized = false;
                gameStarted = false;

            }
            else if (cmd == "setup")
            {
              if(!gameStarted)
              {
                  gameSetup("setup");
              }
                else
                {
                    cout << "You cannot enter the setup mode once the game has started!" << endl;
                    cout << "Please continue the game or start a new game to enter the setup mode" << endl;
                }
            }
        }
    }

    catch (ios::failure &) 
    {
        if(cin.eof())
        {
            displayScore(whiteScore, blackScore);
        }
    }  // Any I/O failure quits

    
}

