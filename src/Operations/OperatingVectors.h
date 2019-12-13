//
// Created by morin on 30.11.2019.
//

#ifndef PROJET_OPERATINGVECTORS_H
#define PROJET_OPERATINGVECTORS_H

#include <vector>
using namespace std;


//!  An Overloading of vectors class.
/*!
  A more elaborate class description.
*/
class OperatingVectors {

public:


    //! A constructor that take a vector of doubles as an argument.
    explicit OperatingVectors(vector<double> operating_vector);

    //! A  constructor that take a size_t value as an argument.
    explicit OperatingVectors(size_t n);

    //! The  default constructor.
    explicit OperatingVectors();




    //! This method permits to overload the operator = for the Operating Vectors objects.
    /*!
      \param m a constant reference of an Operating Vector as an argument.
      \return an Operating Vector.
    */
    OperatingVectors &operator=(const OperatingVectors &m);



    //!
    /*! This method permits to overload the operator [] for the Operating Vectors objects.
      \param i a constant size_t as an argument.
      \return a double.
    */
    double &operator[](const size_t &i);


    //! This method permits to overload the operator [] for the Operating Vectors objects.
    /*!
      \param i a  size_t as an argument.
      \return a double.
    */
    double &operator[](size_t &i);


    //!  This method permits to overload the operator * for the Operating Vectors objects.
    /*!
      \param d a double as an argument.
      \return a constant Operating Vector.
    */
    OperatingVectors operator*(double d) const;



    //! This method permits to overload the operator + for the Operating Vectors objects.
    /*!
      \param d a double as an argument.
      \return a constant Operating Vector.
    */
    OperatingVectors operator+(double d) const;



    //! This method permits to overload the operator + for the Operating Vectors objects.
    /*!
      \param m a constant Operating vector reference as an argument.
      \return a constant Operating Vector.
    */
    OperatingVectors operator+(const OperatingVectors &m) const;



    //!
    /*! This method permits to overload the operator ^ for the Operating Vectors objects.
      \param d an unsigned integer as an argument.
      \return a constant Operating Vector.
    */
    OperatingVectors operator^(unsigned int d) const;


    //!  This method permits to overload the operator * for the Operating Vectors objects.
    /*!
      \param m a constant Operating reference as an argument.
      \return a constant double.
    */
    double operator*(const OperatingVectors &m) const;



    //! This methods permits to obtain the size of an Operating Vector object.
    /*!
      \return a size_t object
    */
    size_t size() const;

    //! A getter method
    /*!
      \return a vector of doubles.
    */
    vector<double>  get() ;



    private:
    //! A private variable.
    /*!
      vector of doubles of coordinates x.
    */
    vector<double> operating_vector;

};


#endif //PROJET_OPERATINGVECTORS_H
