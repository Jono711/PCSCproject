//
// Created by morin on 09.12.2019.
//

#ifndef PROJET_OUTPUT_H
#define PROJET_OUTPUT_H

#include <vector>
#include <string>
using namespace std;

class Output {
public:
    explicit Output(vector<double> coefficient, vector<vector<double>> x_y_coords, string method, string output_type);
    void display();
private:
    virtual string displayEquation();
    virtual void terminal_display();
    virtual void python_display();
    virtual void full_display();

    vector<vector<double>> coefficients;
    vector<vector<double>> x_y_coords;
    string method;
    string output_type;

};


#endif //PROJET_OUTPUT_H
