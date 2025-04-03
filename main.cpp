#include <iostream>
#include <vector>
#include <array>
#include "Critter.h"

using namespace std;

int main() {
    std::cout <<"2D Array of vectors of type <Critter*>  i.e. pointers to critters" << std::endl;

    // the "array" container is defined with a size (fixed size) and can not be changed.
    // It is a good choice for our Board, as the board is a fixed size with equal width and height.


    array<array<vector<Critter*>, 10>, 10> board;

    //array<array<list<Critter*>, 10>, 10> boardC;  // uses a doubly-linked list

    board[0][0].push_back(new Critter(101));  // create Critter object and store its address in the vector that occupies
    // cell(0,0)
    board[0][0].push_back(new Critter(102));  // add a second critter to the same cell.  vector will grow to accommodate new ones.
    // count critters that are in a cell
    auto count = board[0][0].size();
    cout << count;

    board[0][1].push_back(new Critter(103));
    board[1][0].push_back(new Critter(104));
    board[1][1].push_back(new Critter(105));

    cout << endl;
    cout << "Display all critters in cell(0,0)" << endl;

    //TODO
    // need nested for loop to access all elements in 2D array
    for ( auto row = 0; row < 10; row++) {
        for ( auto col = 0; col < 10; col++) {
            for ( auto pCritter : board[row][col] ) {
                pCritter->display();
            }

        }
     }



    return 0;
}

