//
// Created by morin on 09.12.2019.
//

#ifndef PROJET_RUN_H
#define PROJET_RUN_H

#include "Input/Input.h"
#include "Output/Output.h"
#include <string>
using namespace std;

class Run {
public:
    explicit Run();
    ~Run();

    void launch();

private:
    Input* input;
    string operation;
    string output_type;
    int degree;
    double A;
    double B;

    void launchDataFitting(vector<vector<double>> x_y_coords, int degree);
    void launchDataFittingFind(vector<vector<double>> x_y_coords, int degree);
    void launchInterpolationClamped(vector<vector<double>> x_y_coords, double A, double B);
    void launchInterpolationNatural(vector<vector<double>> x_y_coords);
    void launchPolyInterpolation(vector<vector<double>> x_y_coords, int degree);
};


#endif //PROJET_RUN_H
