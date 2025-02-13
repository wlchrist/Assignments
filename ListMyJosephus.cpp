#include "ListMyJosephus.h"
#include "Destination.h"
#include <fstream>
#include <sstream>
#include <list>

ListMyJosephus::ListMyJosephus() : m(0), n(0) {}

ListMyJosephus::ListMyJosephus(int m, int n) : m(m), n(n) {}

ListMyJosephus::ListMyJosephus(const ListMyJosephus& other) : m(other.m), n(other.n) {}

ListMyJosephus& ListMyJosephus::operator=(const ListMyJosephus& other) {
    if (this != &other) {
        m = other.m;
        n = other.n;
    }
    return *this;
}

ListMyJosephus::~ListMyJosephus() {}

int ListMyJosephus::getPosition() const {
    return m;
}

string ListMyJosephus::getName() const {
    return std::to_string(n);
}

void ListMyJosephus::setPosition(int p) {
    m = p;
}

void ListMyJosephus::setName(const string& name) {
    n = std::stoi(name);
}

void ListMyJosephus::printPosition() const {
    cout << m << endl;
}

void ListMyJosephus::printListMyJosephusName() const {
    cout << n << endl;
}

bool ListMyJosephus::operator==(const ListMyJosephus& other) const {
    return m == other.m && n == other.n;
}

bool ListMyJosephus::operator!=(const ListMyJosephus& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const ListMyJosephus& dest) {
    os << "Position: " << dest.m << ", Name: " << dest.n;
    return os;
}

void ListMyJosephus::storeDestinations(const string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return;
    }
    destinations.clear();
    std::string line;
    int position = 0;
    while (std::getline(file, line)) {
        std::istringstream lineStream(line);
        std::string name;
        while (std::getline(lineStream, name, ';')) {
            destinations.push_back(Destination(position++, name));
        }
    }
}

void ListMyJosephus::printDestinations() {
    for (const auto& dest : destinations) {
        cout << "Index: " << dest.getPosition() << " | Name: " << dest.getName() << endl;
    }
}
