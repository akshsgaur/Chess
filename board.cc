#include "board.h"
#include "textDisplay.h"
#include "graphicalDisplay.h"
#include <iostream>
//#include "graphicaldisplay.h"

// might need to clear the board
Board::~Board()
{
    delete td; // delete the textDisplay
    delete ob; // delete the graphics observer
}

void Board::clearBoard()
{
 theBoard.clear(); // clear the board
}

std::vector<std::vector<Cell>> &Board::getBoard() {

    return theBoard;

};

void Board::setObserver(Observer<Info, State> *ob)
{
    ob = ob;
}

// TODO: implementation required
Colour Board::whoWon() const
{
}

// Sets up an n x n board.  Clears old board, if necessary.
void Board::init(int n)
{
    if(((n % 2) == 0) && (n >= 4)) // if n is a valid board number
    {
        // cleaing the board if initiallized before
        if(size)
        {
            clearBoard();
            delete td;
            delete ob;
        }
        size = static_cast<int>(n);

        td = new TextDisplay(n);
        GraphicalDisplay*ob = new GraphicalDisplay(n);
	    this->setObserver(ob);
        
        // setting up the board of size n
        for(int r = 0; r < n; ++r)
        {
            std::vector<Cell> rowOfCells;
            for(int c = 0; c < n; ++c)
            {
                Cell cell(r, c);
                rowOfCells.push_back(cell);
            }
            theBoard.push_back(rowOfCells);
        }
        // adding neighbours to the board
        for(int row = 0; row < n; ++row)
        {
            for(int column = 0; column < n; ++column)
            {
                if (row-1 >= 0 && column-1 >= 0)
                {
                    theBoard[row][column].attach(&theBoard[row - 1][column - 1]);
                }
                if (row >= 0 && column-1 >= 0)
                {
                    theBoard[row][column].attach(&theBoard[row][column - 1]);
                }
                if (row + 1 <= n-1 && column - 1 >= 0)
                {
                    theBoard[row][column].attach(&theBoard[row + 1][column - 1]);
                }
                if (row - 1 >= 0 && column >= 0 )
                {
                    theBoard[row][column].attach(&theBoard[row - 1][column]);
                }
                if (((row+1) <= (n-1)) && (column >= 0))
                {
                    theBoard[row][column].attach(&theBoard[row + 1][column]);
                }
                if (row - 1 >= 0 && column+1 <= n-1)
                {
                    theBoard[row][column].attach(&theBoard[row - 1][column + 1]);
                }
                if (row >= 0 && column+1 <= n-1)
                {
                    theBoard[row][column].attach(&theBoard[row][column + 1]);
                }
                if (row+1 <= n-1 && column+1 <= n-1)
                {
                    theBoard[row][column].attach(&theBoard[row + 1][column + 1]);
                }

            }

        }

        // adding the displays to the board
        for (int r = 0; r < n; ++r)
        {
            for(int c = 0; c < n; ++c)
            {
                theBoard[r][c].attach(td);
                theBoard[r][c].attach(ob);
            }
        }
    }
}

// Plays piece at row r, col c.
// need to account for invalid moves

void Board::setPiece(int r, int c, Piece *piece)
{
    if((r >= 0) && (r <= (size - 1)) && (c >= 0) && (c <= (size - 1)))
    {
        
        theBoard[r][c].setPiece(piece); // set the piece with the colour
        theBoard[r][c].notifyObservers(); // notify its neighbours
    }
    else
    {
        throw InvalidMove{};
    }
}

void Board::unsetPiece(int r, int c)
{
    if((r >= 0) && (r <= (size - 1)) && (c >= 0) && (c <= (size - 1)))
    {
        theBoard[r][c].unsetPiece();
        theBoard[r][c].notifyObservers(); // notify its neighbours
    }
    else
    {
        throw InvalidMove{};
    }
}

std::ostream & operator<<(std::ostream &out, const Board &b)
{
    return out << *(b.td); // calls the output operator of text display
}
