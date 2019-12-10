//
// Created by morin on 30.11.2019.
//

#include <iostream>
#include "math.h"
#include "LeastSquares.h"
#include "../Operations/OperatingMatrices.h"
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

double LeastSquares::leastSquareLoss(const vector<double> &coefficients) {
    double loss(0.);
    for(size_t i (0); i < this->y_coords.size(); i++){
        double f_y(0.);
        for(size_t j(0); j<coefficients.size(); j++){
            f_y+=coefficients[j]*pow(x_coords[i],j);
        }
        loss+=pow(y_coords[i]-f_y,2);
    }
    return loss;
}
