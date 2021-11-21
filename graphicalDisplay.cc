#include "graphicalDisplay.h"
#include "subject.h"
#include "piece.h"
//#include "window.cc"
#include <string>
#include <sstream>
using namespace std;
// Constructor
GraphicalDisplay::GraphicalDisplay(int n) : gridSize(n){/*
    theDisplay = new Xwindow{500,500};
    theDisplay->fillRectangle(0, 0, 500, 500, 4);
    int h = 500/gridSize;
    int w = 500/gridSize;
    for (int i = 0; i < gridSize; i++){
      if(i%2 ==0){
        for(int j = 0; j < gridSize; j++ ){
          if(j % 2 ==0){
            theDisplay->fillRectangle(i*h, j*h,h,w,0);
          }
          else {
            theDisplay->fillRectangle(i*h, j*h, h, w,1);
          }
        }
      }
      else {
        for(int j = 0; j < gridSize; j++){
          if(j%2 == 0){
            theDisplay->fillRectangle(i*h, j*h, h, w,1);
          }
          else {
            theDisplay->fillRectangle(i*h, j*h,h,w,0);
          }
        }
      }
    }
*/}

// Destructor
GraphicalDisplay::~GraphicalDisplay(){
    //delete theDisplay;
}


//Notify
void GraphicalDisplay::notify(Subject<Info, State> &whoNotified) {
/*
    int r =( ((((whoNotified.getInfo().row)+1) * (500 / gridSize)) + (((whoNotified.getInfo().row)) * (500 / gridSize)))/2);
    //cout << "This is r: " << r << endl;
    int c =( ((((whoNotified.getInfo().col)) * (500 / gridSize)) + (((whoNotified.getInfo().col+1)) * (500 / gridSize)))/2) ; // column of the notifier
    //cout << "This is c: " << c << endl;
    Piece* p = whoNotified.getInfo().piece;
    Colour clr = whoNotified.getInfo().colour; // colour of the notifier
    char ptype = p->getType();
    //cout << "This is piece: " << ptype << endl;
    string s;
    stringstream ss;
    ss << ptype;
    ss >> s;
        theDisplay->fillRectangle(c, r, 500/gridSize, 500/gridSize, 0); // display is set to White color for White
        theDisplay->drawString(c,r,s);*/
}
