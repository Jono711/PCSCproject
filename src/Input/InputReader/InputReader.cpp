//
// Created by morin on 25.11.2019.
//

#include "InputReader.h"
#include <algorithm>
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
        if (!read_file.is_open()) {
            std::cout << "Error opening file. Continuing program with an empty input file." << std::endl;
            return vector<vector<double>>();
        }
        std::string line;
        while(std::getline(read_file,line))
        {
            string temp;
            std::stringstream lineStream(line);
            lineStream >> temp;
            //format1: "x1","y1"
            //format2: x1,y1
            if(!temp.empty()){
                replace(temp.begin(), temp.end(), ',', '.');
                int pos = 0;
                double double_temp(0.);
                if(temp.substr(0,1)=="\""){
                    pos = pos + 1;
                    while(temp.substr(pos, 1) != "\"") { pos = pos + 1; }
                    double_temp = stod(temp.substr(1,pos-1));
                    pos = pos + 1;
                } else {
                    while(temp.substr(pos, 1) != ".") { pos=pos+1; }
                    double_temp = stod(temp.substr(0,pos));
                }
                x_coords.push_back(double_temp);
                temp = temp.substr(pos+1, temp.size() - (pos+1));
                if(temp.substr(0,1)=="\""){
                    double_temp = stod(temp.substr(1,temp.size()-1));
                } else {
                    double_temp = stod(temp.substr(0,temp.size()));
                }
                y_coords.push_back(double_temp);
            }
        }
        read_file.close();
        return vector<vector<double>> ({x_coords, y_coords});

    } else {

        std::ifstream read_file(filename);
        if (!read_file.is_open()) {
            std::cout << "Error opening file. Continuing program with an empty input file." << std::endl;
            return vector<vector<double>>();
        }

        //format: x1 x2
        while (!read_file.eof() && !read_file.fail()) {
            double x_coord, y_coord;
            read_file >> x_coord >> y_coord;

            x_coords.push_back(x_coord);
            y_coords.push_back(y_coord);
        }
        if (read_file.fail() && !read_file.eof())
        {
            std::cout << "Error reading file. This is probably due to trying to read a non-double. Continuing with an empty input file." << std::endl;
            return vector<vector<double>>();
        }
        read_file.close();
        return vector<vector<double>> ({x_coords, y_coords});
    }
}