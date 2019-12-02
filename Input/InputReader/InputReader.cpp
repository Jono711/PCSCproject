//
// Created by morin on 25.11.2019.
//

#include "InputReader.h"
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

InputReader::InputReader(string filename) {
    this->filename = move(filename);
}

vector<vector<double>> InputReader::generate() {
    vector<double> x_coords, y_coords;
    if (filename.substr(filename.size()-3, 3) == "csv"){

        std::ifstream read_file(filename);

        std::string line;
        while(std::getline(read_file,line))
        {
            double x_coord, y_coord;
            char coma;
            std::stringstream lineStream(line);
            lineStream >> x_coord >> coma >> y_coord;
            x_coords.push_back(x_coord);
            y_coords.push_back(y_coord);

        }
        read_file.close();
        return vector<vector<double>>();

    }else{

        std::ifstream read_file(filename);
        if (!read_file.is_open()) {
            std::cout << "Error opening file. Continuing program with an empty input file." << std::endl;
            return vector<vector<double>>();
        }
        while (!read_file.eof()) {
            double x_coord, y_coord;
            read_file >> x_coord >> y_coord;
            x_coords.push_back(x_coord);
            y_coords.push_back(y_coord);
        }
        read_file.close();
        return vector<vector<double>> ({x_coords, y_coords});
    }
}
