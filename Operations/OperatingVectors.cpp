//
// Created by morin on 30.11.2019.
//

#include "OperatingVectors.h"

#include <utility>
using namespace std;

OperatingVectors::OperatingVectors(vector<double> operating_vector) {
    this->operating_vector=std::move(operating_vector);
}

OperatingVectors::OperatingVectors(size_t n) {
    *this = OperatingVectors(vector<double> (0, n));
}


OperatingVectors &OperatingVectors::operator=(const OperatingVectors &m) = default;

double &OperatingVectors::operator[](const size_t &i) {
    return this->operating_vector[i];
}

OperatingVectors OperatingVectors::operator*(const double d) const {
    vector<double> new_vector(0,this->operating_vector.size());
    for(size_t i =0; i < this->operating_vector.size(); i++ ){
        new_vector[i] = this->operating_vector[i] * d;
    }
    return OperatingVectors(new_vector);
}

OperatingVectors OperatingVectors::operator+(const double d) const {
    vector<double> new_vector(0,this->operating_vector.size());
    for(size_t i =0; i < this->operating_vector.size(); i++ ){
        new_vector[i] = this->operating_vector[i] + d;
    }
    return OperatingVectors(new_vector);
}

OperatingVectors OperatingVectors::operator+(const OperatingVectors &m) const {
    // Error handling when this->operating_vector.size()!=m.operating_vector.size() ?
    vector<double> new_vector(0,this->operating_vector.size());
    for(size_t i =0; i < this->operating_vector.size(); i++ ){
        new_vector[i] = this->operating_vector[i] + m.operating_vector[i];
    }
    return OperatingVectors(new_vector);
}

double OperatingVectors::operator*(const OperatingVectors &m) const {
    // Error handling when this->operating_vector.size()!=m.operating_vector.size() ?
    double result(0.);
    for(size_t i =0; i < this->operating_vector.size(); i++ ){
        result += this->operating_vector[i] * m.operating_vector[i];
    }
    return result;
}

OperatingVectors OperatingVectors::operator^(int d) const {
    vector<double> new_vector;
    for (auto & element : this->operating_vector){
        new_vector.emplace_back(pow(element, d));
    }
    return OperatingVectors(new_vector);
}

size_t OperatingVectors::size() const {
    return this->operating_vector.size();
}

vector<double> &OperatingVectors::get() {
    return this->operating_vector;
}
