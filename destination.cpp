#include "destination.h"

Destination::Destination() : position(0), name("defaultname") {}

Destination::Destination(int p, const string& n) : position(p), name(n) {}

Destination::Destination(const Destination& other) : position(other.position), name(other.name) {}

Destination& Destination::operator=(const Destination& other) {
    if (this != &other) {
        position = other.position;
        name = other.name;
    }
    return *this;
}

Destination::~Destination() {}

int Destination::getPosition() const {
    return position;
}

string Destination::getName() const {
    return name;
}

void Destination::setPosition(int p) {
    position = p;
}

void Destination::setName(const string& n) {
    name = n;
}

void Destination::printPosition() const {
    cout << "Position: " << position << endl;
}

void Destination::printDestinationName() const {
    cout << "Destination Name: " << name << endl;
}

bool Destination::operator==(const Destination& other) const {
    return position == other.position && name == other.name;
}

bool Destination::operator!=(const Destination& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const Destination& dest) {
    os << "Destination(Position: " << dest.position << ", Name: " << dest.name << ")";
    return os;
}
