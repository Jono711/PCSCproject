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


//!  Helper class used to display our result and matrices in a more readable format.
/*!
*/
class Output {
public:

    //! Output constructor
    /*!
      \param coefficients The coefficients of our polynome
      \param x_y_coords a list of x and y coordinates
      \param operation It can be either PolyInterpolation, DataFitting, DataFittingFind, InterpolationClamped, InterpolationNatural
      \param python_file_name If the output_type is python or both, this variable indicates the filename of the generated python file
      \param output_type String to determine if we will print to the terminal, a python file or both.
      \param regular_polynome The type of polynome we want to display. Please see the regular_polynome attribute documentation for more details
    */

    //! A constructor that takes a list of x and y coordinates, the method we used to calculate our matrixes ,
    //! the python filename, if applicable, to create a python file containing our plot and the type of polynome to be displayed.
    /*!
    */
    explicit Output(vector<vector<double>> coefficients, vector<vector<double>> x_y_coords, string operation, string python_file_name, string output_type, bool regular_polynome);


    //! Display the output in the commandline
    virtual void terminal_display();

    //! Saves the output in a python file that you can run.
    //! The file is saved in the working directory under the name specified via the variable python_file_name + ".py"
    //! The program will display a plot of the function and its approximation
    virtual void python_display();



    //! This method display the natural spline matrix , the natural spline vector
    //!   the matrix of coefficients and the equations related to the natural spline case.
    /*!
      \param natural_spline_matrix
      \param natural_spline_vector
      \param coefficients An Operating matrix that contains the coefficients of the piecewises natural polynomes
      \param x_coords An OperatingVector that represents a list of the x coordinates.
      \return .
    */
    void displayNaturalSpline(OperatingMatrices natural_spline_matrix, OperatingVectors natural_spline_vector, OperatingMatrices coefficients,
            vector<double> x_coords);


    //! This method display the Operating Matrix given as an argument.
    /*!
      \param m an Operating Matrix as an argument.
      \return .
    */
    void displayMatrix(OperatingMatrices m);



    //! This method display the Operating Vector given as an argument.
    /*!
      \param m an Operating Vector as an argument.
      \return .
    */
    void displayVector(OperatingVectors m);


    //! This method display the clamped spline matrix , the clamped spline vector
    //  the matrix of coefficients and the equations related to the clamped spline case.
    /*!
      \param clamped_spline_matrix
      \param clamped_spline_vector
      \param coefficients An Operating matrix that contains the coefficients of the piecewises clamped polynomes.
      \param x_coords A vector of double that represents a list of the x coordinates.
      \return .
    */
    void displayClampedSpline(OperatingMatrices natural_spline_matrix, OperatingVectors natural_spline_vector, OperatingMatrices coefficients,
                                     vector<double> x_coords);


    //! This method display the Vandermonde matrix , the y_coords ,
    //  the vector of coefficients and the equation related to the Polynomial Interpolation.
    /*!
      \param VandermondeMatrix
      \param y_coords An OperatingVector that represents a list of the y coordinates.
      \param coefficients An Operating matrix that contains the coefficients of the interpolating polynome.
      \return .
    */
    void displayPolynomeInterpolation(OperatingMatrices VandermondeMatrix, OperatingVectors y_coords,OperatingVectors coefficients);


private:
    virtual string displayEquation();
    void python_display_polynome(ofstream &outputFile, vector<vector<double>> coefficients, vector<double> x_coords, bool regular_polynome);

    //! The coefficients of our polynome
    vector<vector<double>> coefficients;
    //! X and Y coordinates
    vector<vector<double>> x_y_coords;

    //! String indicating the chosen operation,
    //! It can be either PolyInterpolation, DataFitting, DataFittingFind, InterpolationClamped, InterpolationNatural
    string operation;

    //! String to determine if we will print to the terminal, a python file or both.
    string output_type;

    //! If the output_type is python or both, this variable indicates the filename of the generated python file
    string python_file_name;

    //! Indicates whether the polynome we want to display is of the type
    //! P(X) = AX + BX^2 + C
    //! Or
    //! P(X) = A(X+a) + B(X+b)^2 + C
    bool regular_polynome;
};


#endif //PROJET_OUTPUT_H
