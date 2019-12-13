//
// Created by morin on 30.11.2019.
//

#ifndef PROJET_OPERATINGMATRICES_H
#define PROJET_OPERATINGMATRICES_H

#include <vector>
#include "OperatingVectors.h"
using namespace std;

//!  An Overloading of Matrices class.
/*!
*/
class OperatingMatrices {
public:

    //! A constructor that take a vector of Operating Vectors  as an argument.
    explicit OperatingMatrices(vector<OperatingVectors> operating_matrix);

    //! A constructor that take a vector of vector of doubles as an argument.
    explicit OperatingMatrices(vector<vector<double>> operating_matrix);


    //! A constructor that takes the size n of a square Operating Matrix as an argument
    explicit OperatingMatrices(size_t n);


    //! A constructor.
    /*!
      *Constructor that take the size m where m is the number of rows and n is the number of columns.
    */
    explicit OperatingMatrices(size_t m ,size_t n );


    //!  The overloading of the operator = for the Operating Matrices objects.
    /*!
      \param m a constant reference of an Operating Matrix as an argument.
      \return an Operating Matrix.
    */
    OperatingMatrices &operator=(const OperatingMatrices &m);

    //!  The overloading of the operator [] for Operating Vectors objects.
    /*!
      \param i a constant size_t as an argument.
      \return an Operating Vector.
    */
    OperatingVectors &operator[](const size_t &i);

    //!  The overloading of the operator * for the Operating Matrices objects.
    /*!
      \param d a double as an argument.
      \return a constant Operating Matrix.
    */
    OperatingMatrices operator*(double d) const;



    //!  The overloading of the operator + for the Operating Matrices objects.
    /*!
      \param d a double as an argument.
      \return a constant Operating Matrix.
    */
    OperatingMatrices operator+(double d) const;


    //! The overloading of the operator + for the Operating Matrices objects.
    /*!
      \param m a constant Operating Matrix reference as an argument.
      \return a constant Operating Matrice.
    */
    OperatingMatrices operator+(const OperatingMatrices &m) const;

    //! The overloading of the operator * for the Operating Matrices objects.
    /*!
      \param m a constant Operating matrix reference as an argument.
      \return an Operating Matrix.
    */
    OperatingMatrices operator*(OperatingMatrices &m);


    //! The overloading of the operator * for the Operating Matrices objects.
    /*!
      \param m a constant Operating vector reference as an argument.
      \return an Operating Matrix.
    */
    OperatingVectors operator*(OperatingVectors &m);



    //! This method calculates the transpose of an Operating Matrix
    /*!
      \return an Operating Matrix.
    */
    OperatingMatrices transpose();



    //!  The method calculates the determinant of an Operating Matrix
    /*!
      \param M an Operating Matrix reference as an argument.
      \param n a size_t  as an argument.
      \return a double.
    */
    double determinant(OperatingMatrices &M, size_t n);


    //! This method calculates the comatrice of an Operating Matrix
    /*!
      \return an Operating Matrix.
    */
    OperatingMatrices adjoint();

    //! This method calculates the inverse of an Operating Matrix
    /*!
      \return an Operating Matrix.
    */
    OperatingMatrices inverse();


    //! getter method
    /*!
      \return a vector of Operating Vectors.
    */
    vector<OperatingVectors>& get();



    //! This method retrieve the size_t of an Operating Matrix object.
    /*!
      \return a size_t object.
    */
    size_t size() const;

    // vector<OperatingMatrices> LUdecomposition(OperatingMatrices A, OperatingMatrices B);

private:

    //! This private method get the coefficents of the comatrix.
    /*!
      \param M an Operating matrix reference as an argument.
      \param t a constant Operating matrix reference as an argument.
      \param p an integer as an argument.
      \param q an integer as an argument.
      \param n a size_t as an argument.
      \return nothing.
    */
    void getCfactor(OperatingMatrices& M, OperatingMatrices& t, int p, int q, size_t n);


    //! A private variable.
    /*!
      Vector of Operating Vectors.
    */
    vector<OperatingVectors> operating_matrix;
};


#endif //PROJET_OPERATINGMATRICES_H
