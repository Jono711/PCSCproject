//
// Created by morin on 09.12.2019.
//

#ifndef PROJET_RUN_H
#define PROJET_RUN_H

#include "Input/Input.h"
#include "Output/Output.h"
#include <string>
using namespace std;

//! The main class of the program.
/*!
    This class is the entrypoint and allows the user to select the correct parameters to launch one of the possible data analysis.
 */
class Run {
public:
    //! Constructor
    //! The constructor takes care of asking the user for the different parameters needed.
    /*!
        ##### X and Y Coordinate generator selection: Via input "reader" or "creator"

        ##### For reader: Selection of the filename

        ##### For creator:
           - Selection of the function used to generate y coordinates
           - Selection of a list of X coordinates
           - Selection of a Boolean to indicate if we want to add fluctuation to our y coordinates

        ##### Selection of the type of data analysis:
        It can be either PolyInterpolation, DataFitting, DataFittingFind, InterpolationClamped, InterpolationNatural

        ##### For DataFitting, DataFittingFind
           - Selection of the degree for the polynome
        ##### For InterpolationClamped
           - Selection of the first derivative at the first point
           - Selection of the first derivative at the end point
        ##### Selection of the type of output
        It can be either "terminal", "python“ or "both"
     */
    explicit Run();

    //! Class destructor
    ~Run();

    //! Main method to launch the analysis.
    void launch();

private:

    //* A pointer to an Input class.
    Input* input;

    //! String indicating the chosen operation,
    //! It can be either PolyInterpolation, DataFitting, DataFittingFind, InterpolationClamped, InterpolationNatural
    string operation;

    //! String to determine if we will print to the terminal, a python file or both.
    string output_type;

    //! Degree of the polynome
    int degree;

    //! A   It is a double that represents the first derivative evaluated at x0
    double A;

    //! B It is a double that represents the first derivative evaluated at xN
    double B;

    //! Launch the data Fitting analysis
    /*!
      \param x_y_coords  it represents a list of the x coordinates and y coordinates.
      \param degree  Degree of the polynome.
      \return.
    */
    void launchDataFitting(vector<vector<double>> x_y_coords, int degree);

    //! Launch the data Fitting Find analysis
    /*!
      \param x_y_coords  it represents a list of the x coordinates and y coordinates.
      \param degree  Degree of the polynome.
      \return.
    */
    void launchDataFittingFind(vector<vector<double>> x_y_coords, int degree);

    //! Launch the Clamped Interpolation data analysis
    /*!
      \param x_y_coords  it represents a list of the x coordinates and y coordinates.
      \param A  It is a double that represents the first derivative evaluated at x0
      \param B It is a double that represents the first derivative evaluated at xN
      \return.
    */
    void launchInterpolationClamped(vector<vector<double>> x_y_coords, double A, double B);

    //! Launch the Natural Interpolation data analysis
    /*!
      \param x_y_coords  it represents a list of the x coordinates and y coordinates.
      \return.
    */
    void launchInterpolationNatural(vector<vector<double>> x_y_coords);


    //! Launch the Polynomial Interpolation data analysis
    /*!
      \param x_y_coords  it represents a list of the x coordinates and y coordinates.
      \return.
    */
    void launchPolyInterpolation(vector<vector<double>> x_y_coords);
};


#endif //PROJET_RUN_H
