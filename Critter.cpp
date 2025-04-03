#include "Critter.h"
#include <iostream>
#include <ostream>

using namespace std;

Critter::Critter(int id){     // constructor to initialize id
  this->id = id;
}
int Critter::getId() const{
  return id;
}

void Critter::display() const {
    cout << "Critter " << id << " here." <<endl;
}

ostream& operator<<(ostream& os, const Critter& critter){
  os << critter.getId();
  return os;
 }
