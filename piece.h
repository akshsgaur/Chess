#ifndef __PIECE_H__
#define __PIECE_H__
#include <string>
#include <vector>

class Cell;

using namespace std;

// Card class to store a single instance of a card
class Piece {
  
  // Add private variables and methods here:
    char type;
    char colour;
    int value;

  public:
    Piece(char, char);
    // Add public methods here:
    virtual void setfirstMove(bool );
    virtual bool validMove(int, int, int, int, std::vector<std::vector<Cell>> &) = 0;
    virtual void movePiece(int, int, int, int, std::vector<std::vector<Cell>> &);
    virtual bool firstMove() = 0;
    char getColour();
    char getType();
    int getValue();
    Cell &getCell(std::vector<std::vector<Cell>> &);

};

#endif
