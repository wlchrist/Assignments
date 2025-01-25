//
//  data.h
//  PA1
//
//  Created by Warren Christian on 1/24/25.
//
#ifndef DATA_H
#define DATA_H
#include <string>
#include <iostream>

class Data{

    public:

    std::string command;
    std::string description;
    std::string points;

    // Constructors
    Data() : command(""), description(""), points("") {}

    Data(const std::string& i1, const std::string& i2, const std::string& i3)
        : command(i1), description(i2), points(i3) {}

    // Getters
    std::string getCommand() const { return command; }
    std::string getDescription() const { return description; }
    std::string getPoints() const { return points; }

    // Setters
    void setCommand(const std::string& cmd) { command = cmd; }
    void setDescription(const std::string& desc) { description = desc; }
    void setPoints(const std::string& pts) { points = pts; }
};

inline std::ostream& operator<<(std::ostream& os, const Data& record) {
    os << record.command << " | " << record.description << " | " << record.points;
    return os;
};

#endif
