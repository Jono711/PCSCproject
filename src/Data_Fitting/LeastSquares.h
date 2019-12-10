//
// Created by morin on 30.11.2019.
//

#ifndef PROJET_LEASTSQUARES_H
#define PROJET_LEASTSQUARES_H

#include <vector>
#include <string>

using namespace std;

class LeastSquares {
public:
    explicit LeastSquares(const vector<vector<double>>& xy_coords);
    vector<double> dataFitting(int degree);
    double leastSquareLoss(const vector<double>& coefficients);
private:
    vector<double> x_coords;
    vector<double> y_coords;
};


#endif //PROJET_LEASTSQUARES_H
