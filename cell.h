#ifndef CELL_H
#define CELL_H
#include <cstddef>
#include "state.h"
#include "subject.h"
#include "observer.h"
#include "info.h"

class Cell : public Subject<Info, State>, public Observer<Info, State> {
  const size_t r, c;
  Piece *piece = nullptr;
  Colour colour = Colour::NoColour;
  // Add other private members if necessary

 public:
  Cell(size_t r, size_t c);

  void setPiece(Piece *piece);    // Place a piece of given colour here.
  void setColour(Colour);
  void notify(Subject<Info, State> &whoFrom) override; // ***Implementation required***
  void unsetPiece();
  Info getInfo() const override;
};

#endif