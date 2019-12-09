//
// Created by morin on 30.11.2019.
//

#include <iostream>
#include "LeastSquares.h"
#include "Operations/OperatingMatrices.h"
using namespace std;

LeastSquares::LeastSquares(const vector<vector<double>> &xy_coords) {
    if(xy_coords.size()!=2){
        cout << "There shouldn't be more or less than two coordinates. Creating method with no coordinates." << endl;
        x_coords = vector<double>();
        y_coords = vector<double>();
    } else if(xy_coords[0].size()!=xy_coords[1].size()){
        cout << "The two coordinates don't have the same size. Creating method with no coordinates." << endl;
        x_coords = vector<double>();
        y_coords = vector<double>();
    } else {
        x_coords = xy_coords[0];
        y_coords = xy_coords[1];
    }
}

vector<double> LeastSquares::dataFitting(int degree) {
    // Augment X dimension
    vector<OperatingVectors> augmented_x;
    augmented_x.reserve(degree + 1);
    for(int i = 0; i < degree + 1; i++){
        augmented_x.push_back(OperatingVectors(x_coords)^i);
    }


    // Linearly solve (XtX)w=(Xty)
    OperatingMatrices transposed_x(augmented_x);
    OperatingMatrices normal_x(transposed_x.transpose());
    OperatingMatrices LHS = transposed_x*normal_x;

    OperatingVectors normal_y(y_coords);
    OperatingVectors RHS = transposed_x * normal_y;

    OperatingVectors coefficients = LHS.inverse()*RHS;

    // Output weights
    return coefficients.get();
}

string LeastSquares::displayEquation(const vector<double>& coefficients) {
    string to_return("y=");
    for(unsigned int i = coefficients.size()-1; i > 0; --i){
        if (coefficients[i] > 0 && to_return.size() > 2)
            to_return += "+";
        to_return += to_string(coefficients[i]);
        if (i==1) {
            to_return += "x";
        }else{
            to_return += "x^(" + to_string(i) + ")";
        }
    }

    if (coefficients[0] > 0 && to_return.size() > 2)
        to_return += "+";
    to_return += to_string(coefficients[0]);

    return to_return;
}
