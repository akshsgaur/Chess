#include "textDisplay.h"
#include "subject.h"
#include "piece.h"
#include <vector>
using namespace std;

// Constructor
TextDisplay::TextDisplay(int n) : gridSize(n) {
    
    for (int r = 0; r < n; ++r) 
    {
	    
        std::vector<char> row;
		
        for(int c = 0; c < n; ++c)  
        {
            if((r+c) % 2 == 0)
            {
                row.push_back(' ');
            }
            else 
            {
                row.push_back('-');
            }
		}

		theDisplay.push_back(row);
	}
}

//Notify
void TextDisplay::notify(Subject<Info, State> &whoNotified) {
    
    size_t r = whoNotified.getInfo().row; // row of the notifier
    size_t c = whoNotified.getInfo().col; // column of the notifier
    Colour cellColour = whoNotified.getInfo().colour; // colour of the notifier
    Piece *p = whoNotified.getInfo().piece; // piece
    

    if(p) 
    {
       theDisplay[r][c] = p->getType();
    }
    else 
    {
        if(((r + c) % 2) == 0)
        {
            theDisplay[r][c] = ' ';
        }
        else 
        {
            theDisplay[r][c] = '-';
        }
    }
}

// Output operator
std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
    vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    vector<int> numerics = {8,7,6,5,4,3,2,1};
    
    for(int r = 0; r < td.gridSize; ++r) 
    {
	out << numerics[r] << " ";
        for (int c = 0; c < td.gridSize; ++c)
        {
            out << td.theDisplay[r][c]; // print the cth column at rth row of display
        }
            out << std::endl; // print a new line after every row
    }
    out << endl;
    out << "  ";
    for (int i = 0; i < alphabet.size(); i++){
        out << alphabet[i]; 
    }
    out << endl;
    return out;
}

