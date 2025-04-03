#include <iostream>
#include <vector>
#include <array>
#include "Critter.h"

using namespace std;

int main() {
    std::cout <<"2D Array of vectors of type <Critter*>  i.e. pointers to critters" << std::endl;

    // the "array" container is defined with a size (fixed size) and can not be changed.
    // It is a good choice for our Board, as the board is a fixed size with equal width and height.

    const int BOARD_WIDTH = 5;

    array<array<vector<Critter*>, BOARD_WIDTH>, BOARD_WIDTH> board;

    //array<array<list<Critter*>, 10>, 10> boardC;  // uses a doubly-linked list

    board[0][0].push_back(new Critter(101));  // create Critter object and store its address in the vector that occupies
    // cell(0,0)
    board[0][0].push_back(new Critter(102));  // add a second critter to the same cell.  vector will grow to accommodate new ones.


    board[0][1].push_back(new Critter(103));
    board[1][0].push_back(new Critter(104));
    board[1][1].push_back(new Critter(105));

    cout << endl;
    cout << "Display all critters in cell(0,0)" << endl;

    //TODO
    // need nested for loop to access all elements in 2D array
    for ( auto row = 0; row < BOARD_WIDTH; row++) {
        for ( auto col = 0; col < BOARD_WIDTH; col++) {
            for ( auto pCritter : board[row][col] ) {
                pCritter->display();
            }
        }
     }

    // Geta reference to cell (0,0) where there are two Critters
    vector<Critter*>& critters_vector = board[0][0];

    // find the number of critters in the vector (i.e. on that cell)
    auto count = critters_vector.size();
    cout << "Critter count = " << count << endl;

    // print out the list of critters in the vector
    cout << "Critters in cell (0,0) " << endl;;
    for (const Critter* pCritter : critters_vector) {
        pCritter->display();
        // or, dereference the critter pointer to get the critter object
        // and rely on the overloaded operator<< to output th eCritter data.
         //cout << (*pCritter) << endl;

    }

    // Delete the first critter from board.
    critters_vector.erase(critters_vector.begin());



    return 0;
}

