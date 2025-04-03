#ifndef CRITTER_H
#define CRITTER_H
#include<iostream>

class Critter {
private:
    int id;
public:
    Critter(int id);    // no-arg constructor
    int getId() const;  // designates that the function will not change any member fields
    void display() const;
    friend std::ostream& operator<<(std::ostream& os, const Critter& critter);
};

#endif //CRITTER_H
