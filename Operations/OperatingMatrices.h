//
// Created by morin on 30.11.2019.
//

#ifndef PROJET_OPERATINGMATRICES_H
#define PROJET_OPERATINGMATRICES_H

#include <vector>
#include "OperatingVectors.h"
using namespace std;

class OperatingMatrices {
public:
    explicit OperatingMatrices(vector<OperatingVectors> operating_matrix);
    explicit OperatingMatrices(size_t n);

    OperatingMatrices &operator=(const OperatingMatrices &m);

    OperatingMatrices operator*(double d) const;
    OperatingVectors &operator[](const size_t &i);
    OperatingMatrices operator+(double d) const;
    OperatingMatrices operator+(const OperatingMatrices &m) const;
    OperatingMatrices operator*(OperatingMatrices &m);
    OperatingVectors operator*(OperatingVectors &m);

    OperatingMatrices transpose();
    void getCfactor(OperatingMatrices& M, OperatingMatrices& t, int p, int q, size_t n);
    double determinant(OperatingMatrices &M, size_t n);
    OperatingMatrices adjoint();
    OperatingMatrices inverse();

    // vector<OperatingMatrices> LUdecomposition(OperatingMatrices A, OperatingMatrices B);

private:
    vector<OperatingVectors> operating_matrix;
};


#endif //PROJET_OPERATINGMATRICES_H
