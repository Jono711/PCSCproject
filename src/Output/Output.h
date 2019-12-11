//
// Created by morin on 09.12.2019.
//

#ifndef PROJET_OUTPUT_H
#define PROJET_OUTPUT_H

#include <vector>
#include <string>
#include "Operations/OperatingMatrices.h"
#include "Operations/OperatingVectors.h"
using namespace std;

class Output {
public:
    explicit Output(vector<vector<double>> coefficients, vector<vector<double>> x_y_coords, string operation, string python_file_name, string output_type, bool regular_polynome);

    virtual void terminal_display();
    virtual void python_display();
    void displayNaturalSpline(OperatingMatrices natural_spline_matrix, OperatingVectors natural_spline_vector, OperatingMatrices coefficients,
            vector<double> x_coords);
    void displayMatrix(OperatingMatrices m);
    void displayVector(OperatingVectors m);
    void displayClampedSpline(OperatingMatrices natural_spline_matrix, OperatingVectors natural_spline_vector, OperatingMatrices coefficients,
                                     vector<double> x_coords);
    void displayPolynomeInterpolation(OperatingMatrices VandermondeMatrix, OperatingVectors y_coords,OperatingVectors coefficients);
private:
    virtual string displayEquation();
    void python_display_polynome(ofstream &outputFile, vector<vector<double>> coefficients, vector<double> x_coords, bool regular_polynome);

    vector<vector<double>> coefficients;
    vector<vector<double>> x_y_coords;
    string operation;
    string output_type;
    string python_file_name;
    bool regular_polynome;
};


#endif //PROJET_OUTPUT_H
