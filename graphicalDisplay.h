#ifndef GRAPHICALDISPLAY_H
#define GRAPHICALDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "state.h"
#include "info.h"
//#include "window.h"
#include "board.h"

class Cell;

class GraphicalDisplay: public Observer<Info, State> {
  //Xwindow* theDisplay; // pointer to the window created
  const int gridSize; // size of the grid (n x n)
 public:
  GraphicalDisplay(int n);
  void notify(Subject<Info, State> &whoNotified) override; // similar to text display notify function but with GUI
  ~GraphicalDisplay();
};

#endif

