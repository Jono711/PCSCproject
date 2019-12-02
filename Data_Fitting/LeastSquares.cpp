//
// Created by morin on 30.11.2019.
//

#include "LeastSquares.h"
#include "../Operations/OperatingMatrices.h"

LeastSquares::LeastSquares(const vector<vector<double>>& xy_coords) {
    x_coords = xy_coords[0];
    y_coords = xy_coords[1];
}

vector<double> LeastSquares::dataFitting(int degree) {
    // Augment X dimension
    vector<OperatingVectors> augmented_x;
    augmented_x.reserve(degree + 1);
    for(int i = 0; i < degree; i++){
        augmented_x.push_back(OperatingVectors(x_coords)^i);
    }
    // Linarly solve (XtX)w=(Xty)
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
        if (coefficients[i] > 0 and to_return.size() > 2)
            to_return += "+";
        to_return += to_string(coefficients[i]);
        if (i==1) {
            to_return += "x";
        }else{
            to_return += "x^(" + to_string(i) + ")";
        }
    }

    if (coefficients[0] > 0 and to_return.size() > 2)
        to_return += "+";
    to_return += to_string(coefficients[0]);

    return to_return;
}
