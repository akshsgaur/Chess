#include <iostream>
#include <string>
// You may include other allowed headers, as needed
#include "chess.h"

//#include "window.h"

using namespace std;

// Do not remove any code; do not add code other than where indicated.

int main(int argc, char *argv[]) {
  
  cin.exceptions(ios::eofbit|ios::failbit);
  
  // Add code here


  Chess chess;
  


  //Note: input format is:
  // -h -> human player
  // -c1 -> computer level 1
  // -c2 -> computer level 2
  // -c3 -> computer level 2
  // -c4 -> computer level 2
  

  chess.runGame();
  
}
