//
// Created by KITANE YOUSSEF on 09.12.19.
//

#include <iostream>
#include "PolynomialApproximation.h"
#include "Operations/OperatingVectors.h"
#include "Operations/OperatingMatrices.h"
#include "math.h"
using namespace std;

PolynomialApproximation::PolynomialApproximation() = default;


OperatingVectors PolynomialApproximation::difference_data(OperatingVectors coords){
    size_t coords_size = coords.size() ;
    OperatingVectors difference_x(coords_size-1);

    for(int i = 0 ; i < coords_size-1 ; i++){
        difference_x[i]=(coords[i+1] - coords[i]);
    }
    return difference_x;
}



OperatingMatrices PolynomialApproximation::natural_spline_data_matrix(OperatingVectors x_coordinate){
    size_t size = x_coordinate.size();

    // Using the fill constructor to initialize a two-dimensional vector
    // with given default value
    OperatingMatrices result(size-2);
    OperatingVectors difference_x = difference_data(x_coordinate);

    for(int i = 0 ; i < size-2 ; i++){
        for(int j = 0 ; j < size-2 ; j++) {
            if (i == j) {
                result[i][j]= 2*(difference_x[i] + difference_x[i+1]);
            } else if (j == i-1 && i > 0) {
                result[i][j]= difference_x[i];
            } else if(j == i+1 && i < size) {
                result[i][j]= difference_x[j];
            } else {
                result[i][j]=0;
            }
        }
    }
    return result;
}





OperatingVectors PolynomialApproximation:: natural_spline_vector(OperatingVectors x_coordinate , OperatingVectors y_coordinate){
    size_t size = x_coordinate.size();
    // Using the fill constructor to initialize a two-dimensional vector
    // with given default value
    OperatingVectors result(size-2);
    OperatingVectors difference_x = difference_data(x_coordinate);
    OperatingVectors difference_y = difference_data(y_coordinate);

    for(int i = 0 ; i < size-2 ; i++){
        result[i]= 6* ((difference_y[i+1])/(difference_x[i+1])-(difference_y[i])/(difference_x[i]));
    }
    return result;
}

OperatingMatrices PolynomialApproximation:: clamped_spline_data_matrix(OperatingVectors x_coordinate){
    size_t size = x_coordinate.size();

    // Using the fill constructor to initialize a two-dimensional vector
    // with given default value

    OperatingMatrices result(size);
    OperatingVectors difference_x = difference_data(x_coordinate);
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size; j++) {
            if (i == j) {
                if(i == 0) {
                    result[i][j] = 2 * (difference_x[i]);
                }else if(i==5){
                    result[i][j] = 2 * (difference_x[i-1]);
                }else{
                    result[i][j]= 2*(difference_x[i-1]+difference_x[i]);
                }
            } else if (j == i-1 && i > 0) {
                result[i][j]= difference_x[i-1];
            } else if(j == i+1 && i < size) {
                result[i][j]= difference_x[i];
            } else {
                result[i][j]=0;
            }
        }
    }
    return result;

}

OperatingVectors PolynomialApproximation:: clamped_spline_vector(OperatingVectors x_coordinate, OperatingVectors y_coordinate, double A, double B){
    size_t size = x_coordinate.size();

    // Using the fill constructor to initialize a two-dimensional vector
    // with given default value
    OperatingVectors result(size);
    OperatingVectors difference_x = difference_data(x_coordinate);
    OperatingVectors difference_y = difference_data(y_coordinate);

    for(int i = 0 ; i < size ; i++){
        if( i == 0 ){
            result[0]=6*((difference_y[0]/difference_x[0])-A) ;
        }
        else if( i == size-1 ){
            result[size-1]= 6*(B-(difference_y[size-2]/difference_x[size-2]));
        }
        else{
            result[i]= 6* ((difference_y[i])/(difference_x[i])-(difference_y[i-1])/(difference_x[i-1]));
        }
    }
    return result;
}

OperatingMatrices PolynomialApproximation:: polynomial_interpolation_data_matrix(OperatingVectors x_coordinate ){
    size_t size = x_coordinate.size();
    int degree = size - 1;

    OperatingMatrices result(size,degree+1);
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ;  j <= degree ;  j++){
            result[i][j] = pow(x_coordinate[i],degree-j) ;
        }
    }
    return result;

}





OperatingMatrices PolynomialApproximation:: natural_spline_coefficients(OperatingVectors derivatives, OperatingVectors x_coordinate, OperatingVectors y_coordinate){
    size_t size = derivatives.size();
    OperatingMatrices result(size+1,size);
    OperatingVectors difference_x = difference_data(x_coordinate);
    OperatingVectors difference_y = difference_data(y_coordinate);

    for (int i = 0 ; i < size+1 ; i++){
        if(i==0) {
            result[i][0] = (derivatives[i]) / (6 * difference_x[i]);
            result[i][1] = derivatives[i] / 2;
            result[i][2] = (difference_y[i] / difference_x[i]) - (difference_x[i] * (derivatives[i])) / 6;
            result[i][3] = y_coordinate[i];
        }else if(i==size){
            result[i][0] = (0-derivatives[i-1])/(6*difference_x[i]);
            result[i][1] = 0 ;
            result[i][2] = (difference_y[i]/difference_x[i])-(difference_x[i]*(0+ 2*derivatives[i-1]))/6 ;
            result[i][3] = y_coordinate[i];
        }else{
            result[i][0] = (derivatives[i]-derivatives[i-1])/(6*difference_x[i]);
            result[i][1] = derivatives[i]/2 ;
            result[i][2] = (difference_y[i]/difference_x[i])-(difference_x[i]*(derivatives[i]+ 2*derivatives[i-1]))/6 ;
            result[i][3] = y_coordinate[i];
        }
    }

    return result ;
}


OperatingMatrices PolynomialApproximation:: clamped_spline_coefficients(OperatingVectors derivatives, OperatingVectors x_coordinate, OperatingVectors y_coordinate){
    size_t  size = derivatives.size();

    OperatingMatrices result(size-1,size-2);
    OperatingVectors difference_x = difference_data(x_coordinate);
    OperatingVectors difference_y = difference_data(y_coordinate);

    for (int i = 0 ; i < size-1 ; i++){
        result[i][0] = (derivatives[i+1]-derivatives[i])/(6*difference_x[i]);
        result[i][1] = derivatives[i]/2 ;
        result[i][2] = (difference_y[i]/difference_x[i])-(difference_x[i]*(derivatives[i+1]+ 2*derivatives[i]))/6 ;
        result[i][3] = y_coordinate[i];
    }
    return result ;
}

// Only works if Vandermonde Matrix is a square matrix in the sense that the degree+1 of the polynome
// is equal to the number of data points
OperatingVectors PolynomialApproximation:: Polynomial_interpolation_coefficients(OperatingMatrices Vandermonde_matrix,
                                                                                 OperatingVectors y_coordinate){

    size_t m = Vandermonde_matrix.size();
    size_t n = y_coordinate.size() ;
    OperatingVectors result(n);

    //OperatingMatrices inverse_data_matrix(m,n);
    OperatingMatrices inverse_data_matrix = Vandermonde_matrix.inverse() ;

    result = inverse_data_matrix*y_coordinate ;

    return result ;

}

