//
//  readfile.cpp
//  PA1
//
//  Created by Warren Christian on 1/25/25.
//

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <sstream>
#include "linkedlist.h"
#include "data.h"

std::optional<LinkedList<Data>> readAndStore() {
    
    std::string filePath = "commands.csv";
    std::ifstream commandsfile;
    commandsfile.open(filePath);
    LinkedList<Data> list;
    if (commandsfile.fail()) {
        std::cout << "Error opening file" << std::endl;
        return std::nullopt;
    }

    else {
        while(commandsfile.peek() != EOF) {
            std::string records;
            std::getline(commandsfile, records, '\n');
            std::istringstream stream(records);
            Data data;
            
            if(!std::getline(stream, data.command, ',') || !std::getline(stream, data.description, ',') || !std::getline(stream, data.points)) {
                std::cout << "Line is invalid" << std::endl;
                stream.clear();
                continue;
            }
            
            std::getline(stream, data.command, ',');
            std::getline(stream, data.description, ',');
            std::getline(stream, data.points);
            list.insertAtFront(data);         
        }
    }
    commandsfile.close();
    return list;
}

