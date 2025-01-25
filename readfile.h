//
//  readfile.cpp
//  PA1
//
//  Created by Warren Christian on 1/25/25.
//

#include <iostream>
#include <string>
#include <fstream>

void readCSV() {
    std::fstream fin;
    
    fin.open("commands.csv", std::ios::in);
    std::string line, temp, command, description, points;
    std::vector<std::string> row;
    
    /*
    while(fin >> temp) {
        
        row.clear();
        
        getline(fin, line);
        
        std::stringstream s(line);
        
        while(getline(s, command, ','))
    }
    */
}
