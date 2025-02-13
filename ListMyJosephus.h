#ifndef VECTORMYJOSEPHUS_H
#define VECTORMYJOSEPHUS_H

#include <iostream>
#include <string>
#include <list>
#include "Destination.h"
using std::string;
using std::cout;
using std::endl;
using std::ostream;

class ListMyJosephus {
private:
    int m;
    int n;
    std::list<Destination> destinations;
public:
    // constructors
    ListMyJosephus();
    ListMyJosephus(int m, int n);
    ListMyJosephus(const ListMyJosephus& other);
    
    // copy assignment
    ListMyJosephus& operator=(const ListMyJosephus& other);

    // destructor
    ~ListMyJosephus();

    // getters
    int getPosition() const;
    string getName() const;

    // setters
    void setPosition(int p);
    void setName(const string& n);

    // helper/utility functions
    void printPosition() const;
    void printListMyJosephusName() const;

    // operator overloading
    bool operator==(const ListMyJosephus& other) const;
    bool operator!=(const ListMyJosephus& other) const;
    friend ostream& operator<<(ostream& os, const ListMyJosephus& dest);

    // other
    // empty container
    void clear();
    // return current size
    int currentSize();
    // bool is empty
    bool isEmpty();
    // eliminate destination
    void eliminateDestination();
    // store destinations from .csv
    void storeDestinations(const string& filename = "Destinations.csv");
    // print all destinations
    void printDestinations();
};

#endif
