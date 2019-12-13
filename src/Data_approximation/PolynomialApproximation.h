//
// Created by KITANE YOUSSEF on 09.12.19.
//

#ifndef PROJET_POLYNOMIALAPPROXIMATION_H
#define PROJET_POLYNOMIALAPPROXIMATION_H

#include <vector>
#include <string>
#include "Operations/OperatingVectors.h"
#include "Operations/OperatingMatrices.h"

using namespace std;

//!  A Data Approximation class.
/*!
*/
class PolynomialApproximation {
public:
    //! A  default constructor.
     explicit PolynomialApproximation();


    //! Calculates the difference between the i-th element and the i-1-th element.
    /*!
      \param x_coords An OperatingVector that represents a list of coordinates.
      \return An OperatingVector that contains the difference between two consecutive coordinates of x_coords.
    */
     OperatingVectors difference_data(OperatingVectors x_coords);

    //!  Calculates the Natural Spline matrix based on the coordinates
    /*!   The natural spline matrix is going to allow you to calculate the X
    // Using the equation AX=B where X is the natural spline result and A is the natural Spline matrix
    // And B is the natural spline vector
      \param x_coords An OperatingVector that represents a list of coordinates.
      \return An N-1xN-1 Operating Matrix where N is the size of the coordinates.
    */
    OperatingMatrices natural_spline_data_matrix(OperatingVectors x_coords);


    //! Calculates the Natural Spline vector based on the coordinates
    //!The natural spline vector is going to allow you to calculate the X
    // Using the equation AX=B where X is the natural spline result and A is the natural Spline matrix
    //    And B is the natural spline vector
    /*!
      \param x_coords An OperatingVector that represents a list of the x coordinates.
      \param y_coords An OperatingVector that represents a list of the y coordinates.
      \return An N-1x1 Operating Vector where N is the size of the coordinates
    */
    OperatingVectors natural_spline_vector(OperatingVectors x_coords,OperatingVectors y_coords);



    //! Calculates the Natural Spline coefficients.
    /*!
    //Based on the X obtained from the linear system AX = b , this methods
    // calculates the coefficients of the natural spline for the piece-wise natural polynomes.
      \param derivatives An OperatingVector that represents the solution of the system AX = b
      \param x_coordinate An OperatingVector that represents a list of the x coordinates.
      \param y_coordinate An OperatingVector that represents a list of the y coordinates.
      \return An N-1*N-1 Operating Matrix containing the coefficients of the piecewise polynomes for the natural spline coefficients
    */
    OperatingMatrices natural_spline_coefficients(OperatingVectors derivatives,OperatingVectors x_coordinate,OperatingVectors y_coordinate);



    //!  Calculates the clamped Spline matrix based on the coordinates
    /*!   The clamped spline matrix is going to allow you to calculate the X
    // Using the equation AX=B where X is the clamped spline result and A is the clamped Spline matrix
    // And B is the clamped spline vector
      \param x_coords An OperatingVector that represents a list of coordinates.
      \return An N-1xN-1 Operating Matrix where N is the size of the coordinates.
    */
    OperatingMatrices clamped_spline_data_matrix(OperatingVectors x_coordinate) ;

    //! Calculates the Clamped Spline vector based on the coordinates
    //!The Clamped spline vector is going to allow you to calculate the X
    // Using the equation AX=B where X is the Clamped spline result and A is the Clamped Spline matrix
    //  And B is the natural spline vector
    /*!
      \param x_coords An OperatingVector that represents a list of the x coordinates.
      \param y_coords An OperatingVector that represents a list of the y coordinates.
      \param A A double that represents the first derivative evaluated at x0
      \param B A double that represents the first derivative evaluated at xN
      \return An N+1x1 Operating Vector where N is the size of the coordinates
    */
    OperatingVectors clamped_spline_vector(OperatingVectors x_coordinate,OperatingVectors y_coordinate,double A, double B) ;


    //! Calculates the Clamped Spline coefficients.
    /*!
    //Based on the X obtained from the linear system AX = b , this methods
    // calculates the coefficients of the natural spline for the piece-wise natural polynomes.
      \param derivatives An OperatingVector that represents the solution of the system AX = b
      \param x_coordinate An OperatingVector that represents a list of the x coordinates.
      \param y_coordinate An OperatingVector that represents a list of the y coordinates.
      \return An N-1*N-1 Operating Matrix containing the coefficients of the piecewise polynomes for the clamped spline coefficients
    */
    OperatingMatrices clamped_spline_coefficients(OperatingVectors derivatives,OperatingVectors x_coordinate,OperatingVectors y_coordinate);


    //! Calculates the coefficients of the Vandermonde Matrix.
    // The degree of the polynome is automatically calculated as the size of the x_coordinate param - 1.
    /*!
      \param x_coordinate An OperatingVector that represents a list of the x coordinates.
      \return The Vandermonde Matrix.
    */
    OperatingMatrices polynomial_interpolation_data_matrix(OperatingVectors x_coordinate );







//! Calculates the coefficients of the Polynomial Interpolation
    /*!
      \param data_matrix The Vandermonde Matrix
      \param data_vector The y_coordinates
      \return The coefficients for the Polynomial Interpolation
    */
   OperatingVectors  Polynomial_interpolation_coefficients(OperatingMatrices data_matrix,OperatingVectors data_vector);


private:
    //! A private variable.
    /*!
      vector of doubles of coordinates x.
    */
    vector<double> x_coords;

    //! A private variable.
    /*!
      vector of doubles of coordinates y.
    */
    vector<double> y_coords;
};

#endif //PROJET_POLYNOMIALAPPROXIMATION_H
