#include <iostream>
#include <vector>
#include <array>
#include <list>

#include "Critter.h"

using namespace std;

int main() {
    std::cout <<"2D Array of vectors" << std::endl;



    // the "array" container is defined with a size (fixed size) and can not be changed.
    // It is a good choice for our Board, as the board is a fixed size with equal width and height.

    array<array<vector<Critter*>, 10>, 10> boardB;

    //array<array<list<Critter*>, 10>, 10> boardC;  // uses a doubly-linked list

    boardB[0][0].push_back(new Critter());  // create Critter object and store its address in the vector that occupies
    // cell(0,0)
    boardB[0][0].push_back(new Critter());  // add a second critter to the same cell.  vector will grow to accommodate new ones.
    // count critters that are in a cell
    auto count = boardB[0][0].size();
    cout << count;

    boardB[0][1].push_back(new Critter());
    boardB[1][0].push_back(new Critter());
    boardB[1][1].push_back(new Critter());

    cout << endl;
    cout << "Display all critters in cell(0,0)" << endl;
    for ( auto pCrawler : boardB[0][0] ) {
        pCrawler->display();
    }

    //TODO
    // need nested for loop to access all elements in 2D array
    // for ( auto row = 0; row < BOARD_SIZE; row++) {
    //     for ( auto col = 0; col < BOARD_SIZE; col++) {
    //
    //     }
    // }



    return 0;
}

