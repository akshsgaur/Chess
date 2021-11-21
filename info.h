#ifndef __INFO_H__
#define __INFO_H__
#include <cstddef>
#include "state.h"
#include "piece.h"

struct Info {
  size_t row, col;
  Colour colour;
  Piece *piece;
};

#endif
