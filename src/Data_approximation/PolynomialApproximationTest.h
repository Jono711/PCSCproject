//
// Created by KITANE YOUSSEF on 09.12.19.
//

#ifndef PROJET_POLYNOMIALAPPROXIMATIONTEST_H
#define PROJET_POLYNOMIALAPPROXIMATIONTEST_H

#include <vector>
#include <string>
#include "Operations/OperatingVectors.h"
#include "Operations/OperatingMatrices.h"

using namespace std;


class PolynomialApproximationTest {
public:
     explicit PolynomialApproximationTest();


    OperatingVectors difference_data(OperatingVectors x_coords);

    OperatingMatrices natural_spline_data_matrix(OperatingVectors x_coords);
    OperatingVectors natural_spline_vector(OperatingVectors x_coords,OperatingVectors y_coords);
    OperatingMatrices natural_spline_coefficients(OperatingVectors derivatives,OperatingVectors x_coordinate,OperatingVectors y_coordinate);

    OperatingMatrices clamped_spline_data_matrix(OperatingVectors x_coordinate) ;
    OperatingVectors clamped_spline_vector(OperatingVectors x_coordinate,OperatingVectors y_coordinate,double A, double B) ;
    OperatingMatrices clamped_spline_coefficients(OperatingVectors derivatives,OperatingVectors x_coordinate,OperatingVectors y_coordinate);

    OperatingMatrices polynomial_interpolation_data_matrix(OperatingVectors x_coordinate, int degree );

    OperatingMatrices poly_cubic_hermite_interpolation_data_coefficients(OperatingVectors x_coordinate, float x  );

  //  OperatingVectors  Polynomial_interpolation_coefficients(OperatingMatrices data_matrix,OperatingVectors data_vector);



private:
    vector<double> x_coords;
    vector<double> y_coords;
};

#endif //PROJET_POLYNOMIALAPPROXIMATIONTEST_H
