//
// Created by morin on 30.11.2019.
//

#ifndef PROJET_LEASTSQUARES_H
#define PROJET_LEASTSQUARES_H

#include <vector>
#include <string>

using namespace std;

//!  Least Square class.
/*!
*/
class LeastSquares {

public:
    //! A  constructor that takes the x and y coordinates.
    /*!
    */
    explicit LeastSquares(const vector<vector<double>>& xy_coords);

    //! This method calculates the coefficients of the estimated polynome.
    /*!
      \param degree The degree of the estimated polynome.
      \return The coefficients of the data Fitting method.
    */
    vector<double> dataFitting(int degree);



    //! The LeastSquareLoss method calculate the difference
    //      between the real function and the estimated function based on coefficients.
    /*!
      \param coefficients an Operating Vector argument.
      \return The leastSquare Loss.
    */
    double leastSquareLoss(const vector<double>& coefficients);


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


#endif //PROJET_LEASTSQUARES_H
