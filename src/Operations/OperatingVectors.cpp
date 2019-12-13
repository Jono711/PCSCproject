//
// Created by morin on 30.11.2019.
//

#include "OperatingVectors.h"

#include <utility>
#include <iostream>
#include <math.h>

using namespace std;

OperatingVectors::OperatingVectors(vector<double> operating_vector) {
    this->operating_vector=std::move(operating_vector);
}


OperatingVectors::OperatingVectors(size_t n) {
    *this = OperatingVectors(vector<double> (n, 0.));
}

OperatingVectors::OperatingVectors() = default;

OperatingVectors &OperatingVectors::operator=(const OperatingVectors &m) = default;

double &OperatingVectors::operator[](const size_t &i) {
    return this->operating_vector[i];
}

double &OperatingVectors::operator[](size_t &i) {
    return this->operating_vector[i];
}

OperatingVectors OperatingVectors::operator*(const double d) const {
    vector<double> new_vector(this->operating_vector.size(), 0.);
    for(size_t i = 0; i < this->operating_vector.size(); i++ ){
        new_vector[i] = this->operating_vector[i] * d;
    }
    return OperatingVectors(new_vector);
}

OperatingVectors OperatingVectors::operator+(const double d) const {
    vector<double> new_vector(this->operating_vector.size(), 0.);
    for(size_t i =0; i < this->operating_vector.size(); i++ ){
        new_vector[i] = this->operating_vector[i] + d;
    }
    return OperatingVectors(new_vector);
}


OperatingVectors OperatingVectors::operator+(const OperatingVectors &m) const {
    if(this->operating_vector.size()!=m.operating_vector.size()){
        cout << "Trying to add vector of different sizes. The right vector will be truncated or filled with 0." << endl;
    }
    vector<double> new_vector(this->operating_vector.size(), 0.);
    for(size_t i = 0; i < this->operating_vector.size(); i++ ){
        if(i>=m.operating_vector.size()){
            new_vector[i] = this->operating_vector[i];
        } else {
            new_vector[i] = this->operating_vector[i] + m.operating_vector[i];
        }
    }
    return OperatingVectors(new_vector);
}




double OperatingVectors::operator*(const OperatingVectors &m) const {
    if(this->operating_vector.size()!=m.operating_vector.size()){
        cout << "Trying to multiply vector of different sizes. The right vector will be truncated or filled with 0." << endl;
    }
    double result(0.);
    for(size_t i =0; i < this->operating_vector.size() && i < m.operating_vector.size(); i++ ){
        result += this->operating_vector[i] * m.operating_vector[i];
    }
    return result;
}



OperatingVectors OperatingVectors::operator^(unsigned int d) const {
    vector<double> new_vector;

    for (auto & element : this->operating_vector){
        new_vector.emplace_back(pow(element, d));
    }
    return OperatingVectors(new_vector);
}





size_t OperatingVectors::size() const {
    return this->operating_vector.size();
}


vector<double> OperatingVectors::get() {
    return this->operating_vector;
}




