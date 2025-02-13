#ifndef DESTINATION_H
#define DESTINATION_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

class Destination {
private:
    int position;
    string name;

public:
    // constructors
    Destination();
    Destination(int p, const string& n);
    Destination(const Destination& other);
    
    // copy assignment
    Destination& operator=(const Destination& other);

    // destructor
    ~Destination();

    // getters
    int getPosition() const;
    string getName() const;

    // setters
    void setPosition(int p);
    void setName(const string& n);

    // helper/utility functions
    void printPosition() const;
    void printDestinationName() const;

    // operator overloading
    bool operator==(const Destination& other) const;
    bool operator!=(const Destination& other) const;
    friend ostream& operator<<(ostream& os, const Destination& dest);
};

#endif // DESTINATION_H
