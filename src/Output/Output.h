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
    explicit Output(vector<vector<double>> coefficients, vector<vector<double>> x_y_coords, string method, string output_type, bool regular_polynome);
    void display();

    static void displayNaturalSpline(OperatingMatrices natural_spline_matrix, OperatingVectors natural_spline_vector, OperatingMatrices coefficients,
            vector<double> x_coords);
    static void displayMatrix(OperatingMatrices m);
    static void displayVector(OperatingVectors m);
    static void displayClampedSpline(OperatingMatrices natural_spline_matrix, OperatingVectors natural_spline_vector, OperatingMatrices coefficients,
                                     vector<double> x_coords);
    static void displayPolynomeInterpolation(OperatingMatrices VandermondeMatrix, OperatingVectors y_coords,OperatingVectors coefficients);
    void python_display();

private:
    virtual string displayEquation();
    virtual void terminal_display();
    //virtual void python_display();
    virtual void full_display();
    void python_display_polynome(ofstream &outputFile, vector<vector<double>> coefficients, vector<double> x_coords, bool regular_polynome);

    vector<vector<double>> coefficients;
    vector<vector<double>> x_y_coords;
    string method;
    string output_type;
    bool regular_polynome;
};


#endif //PROJET_OUTPUT_H
