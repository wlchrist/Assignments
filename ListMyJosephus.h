#ifndef VECTORMYJOSEPHUS_H
#define VECTORMYJOSEPHUS_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

class ListMyJosephus {
private:
    int m;
    int n;

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
};

#endif
