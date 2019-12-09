//
// Created by morin on 30.11.2019.
//

#ifndef PROJET_OPERATINGVECTORS_H
#define PROJET_OPERATINGVECTORS_H

#include <vector>
using namespace std;

class OperatingVectors {
public:
    explicit OperatingVectors(vector<double> operating_vector);
    explicit OperatingVectors(size_t n);
    explicit OperatingVectors();

    OperatingVectors &operator=(const OperatingVectors &m);
    double &operator[](const size_t &i);
    double &operator[](size_t &i);
    OperatingVectors operator*(double d) const;
    OperatingVectors operator+(double d) const;
    OperatingVectors operator+(const OperatingVectors &m) const;
    OperatingVectors operator^(unsigned int d) const;
    double operator*(const OperatingVectors &m) const;


    void afficher_Operating_vector();

    size_t size() const;


    vector<double>  get() ;



        private:
    vector<double> operating_vector;

};


#endif //PROJET_OPERATINGVECTORS_H
