#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include <cstddef>
#include "cell.h"
#include "state.h"
#include "info.h"
#include "graphicalDisplay.h"
#include "piece.h"

class TextDisplay;
class GraphicalDisplay;

template <typename InfoType, typename StateType> class Observer;
class InvalidMove{};

class Board {
  std::vector<std::vector<Cell>> theBoard;  // The actual board.
  TextDisplay *td = nullptr; // The text display.
  Observer<Info, State> *ob = nullptr;  // Another observer (intent:  graphics)
  // Add private members, if necessary.

  int size = 8;
  void clearBoard();   // Frees the board.


 public:
  ~Board();
  
  void setObserver(Observer<Info, State> *ob);

  Colour whoWon() const; // Implementation required
  void init(int n); // Sets up an n x n board.  Clears old board, if necessary.
  
  void setPiece(int r,int c, Piece *piece);  // Plays piece at row r, col c.
  void unsetPiece(int r, int c); // removes the piece at row r, col c.
  std::vector<std::vector<Cell>>& getBoard();

  friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif

