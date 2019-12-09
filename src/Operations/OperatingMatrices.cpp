//
// Created by morin on 30.11.2019.
//

#include "OperatingMatrices.h"

#include <utility>
#include <iostream>

OperatingMatrices::OperatingMatrices(vector<OperatingVectors> operating_matrix) {
    size_t i = operating_matrix.size();
    bool is_authorized_matrix = true;
    while(i>1 && is_authorized_matrix)
    {
        i = i-1;
        if (operating_matrix[i].size()!=operating_matrix[0].size())
            is_authorized_matrix = false;
    }
    if(is_authorized_matrix)
    {
        this->operating_matrix = move(operating_matrix);
    } else {
        cout << "Unauthorized matrix dimensions. Creating an empty matrix." << endl;
    }
}

OperatingMatrices::OperatingMatrices(vector<vector<double>> operating_matrix) {
    size_t i = operating_matrix.size();
    bool is_authorized_matrix = true;
    while(i>1 && is_authorized_matrix)
    {
        i = i-1;
        if (operating_matrix[i].size()!=operating_matrix[0].size())
            is_authorized_matrix = false;
    }

    vector<OperatingVectors> res;
    if(is_authorized_matrix)
    {
        for (int j=0; j < operating_matrix.size(); j++) {
            vector<double> a = operating_matrix[j];
            res.push_back(OperatingVectors( a ));
        }
        this->operating_matrix = move(res);
    } else {
        cout << "Unauthorized matrix dimensions. Creating an empty matrix." << endl;
    }

}

OperatingMatrices::OperatingMatrices(size_t n) {
    vector<OperatingVectors> new_matrix;
    for(size_t i=0; i < n; i++){
        new_matrix.emplace_back(OperatingVectors(n));
    }
    *this = OperatingMatrices(new_matrix);
}


OperatingMatrices::OperatingMatrices(size_t m,size_t n) {
    vector<OperatingVectors> new_matrix;
    for(size_t i=0; i < m; i++){
            new_matrix.emplace_back(OperatingVectors(n));

    }
    *this = OperatingMatrices(new_matrix);
}



OperatingMatrices &OperatingMatrices::operator=(const OperatingMatrices &m) = default;

OperatingVectors &OperatingMatrices::operator[](const size_t &i) {
    return this->operating_matrix[i];
}

OperatingMatrices OperatingMatrices::operator*(const double d) const {
    vector<OperatingVectors> new_matrix(this->operating_matrix.size());
    for(size_t i =0; i < this->operating_matrix.size(); i++ ){
        new_matrix[i] = this->operating_matrix[i] * d;
    }
    return OperatingMatrices(new_matrix);
}

OperatingMatrices OperatingMatrices::operator+(const double d) const {
    vector<OperatingVectors> new_matrix(this->operating_matrix.size());
    for(size_t i =0; i < this->operating_matrix.size(); i++ ){
        new_matrix[i] = this->operating_matrix[i] + d;
    }
    return OperatingMatrices(new_matrix);
}

OperatingMatrices OperatingMatrices::operator+(const OperatingMatrices &m) const {
    if(this->operating_matrix.size()!=m.operating_matrix.size() || this->operating_matrix[0].size()!=m.operating_matrix[0].size()){
        cout << "Trying to add matrices of different sizes. The right matrices will be truncated or filled with 0." << endl;
    }
    vector<OperatingVectors> new_matrix;
    for(size_t i =0; i < this->operating_matrix.size(); i++ ){
        if(i>=m.operating_matrix.size()){
            new_matrix.push_back(this->operating_matrix[i]);
        } else {
            new_matrix.push_back(this->operating_matrix[i] + m.operating_matrix[i]);
        }
    }
    return OperatingMatrices(new_matrix);
}

OperatingMatrices OperatingMatrices::operator*(OperatingMatrices &m) {
    if(this->operating_matrix[0].size()!=m.operating_matrix.size()){
        cout << "Size of matrices doesn't match for matrix multiplication. Outputing square matrix of size equal to RHS's row filled with 0." << endl;
        return OperatingMatrices(m.operating_matrix.size());
    }
    vector<OperatingVectors> new_matrix;
    for (auto &row : this->operating_matrix) {
        vector<double> new_vector;
        for (size_t j = 0; j < m[0].size(); j++) {
            double new_double(0.);
            for (size_t k = 0; k < m.operating_matrix.size(); k++) {
                new_double += row[k] * m[k][j];
            }
            new_vector.push_back(new_double);
        }
        new_matrix.emplace_back(new_vector);
    }
    return OperatingMatrices(new_matrix);
}

OperatingVectors OperatingMatrices::operator*(OperatingVectors &m){
    if(this->operating_matrix[0].size()!=m.size()){
        cout << "Size of matrices doesn't match for matrix multiplication. Outputing vector of size equal to RHS filled with 0." << endl;
        return OperatingVectors(m.size());
    }
    vector<double> new_vector;
    for(auto & row : this->operating_matrix){
        double new_double = row * m;
        new_vector.emplace_back(new_double);
    }
    return OperatingVectors(new_vector);
}

OperatingMatrices OperatingMatrices::transpose() {
    vector<OperatingVectors> new_matrix;
    for(size_t i = 0; i < this->operating_matrix[0].size(); i++){
        vector<double> new_vector;
        for (auto & row : this->operating_matrix){
            new_vector.push_back(row[i]);
        }
        new_matrix.emplace_back(OperatingVectors(new_vector));
    }
    return OperatingMatrices(new_matrix);
}

void OperatingMatrices::getCfactor(OperatingMatrices &M, OperatingMatrices &t, int p, int q, size_t n) {
    // only works with square matrix
    int i = 0, j = 0;
    for (size_t r= 0; r< n; r++) {
        for (size_t c = 0; c< n; c++){ //Copy only those elements which are not in given row r and column c:
            if (r != p && c != q) {
                t[i][j++] = M[r][c]; //If row is filled increase r index and reset c index
                if (j == n - 1) {
                    j = 0; i++;
                }
            }
        }
    }
}

double OperatingMatrices::determinant(OperatingMatrices &M, size_t n){ //to find determinant only works on square matrix
    double determ = 0.;
    if(M.operating_matrix.size()!=M.operating_matrix[0].size()){
        cout << "Trying to compute the determinant of a non-quare matrix. Returning 0." << endl;
    } else {
        if (n == 1)
            return M[0][0];
        OperatingMatrices t(M.operating_matrix.size()); //store cofactors
        int s = 1; //store sign multiplier
        // To Iterate each element of first row
        for (size_t f = 0; f < n; f++) {
            //For Getting Cofactor of M[0][f] do
            getCfactor(M, t, 0, f, n);
            determ += s * M[0][f] * determinant(t, n - 1);
            s = -s;
        }
    }
    return determ;
}




OperatingMatrices OperatingMatrices::adjoint(){
//to find adjoint matrix, only works on square matrix
    if (this->operating_matrix.size() == 1){
        OperatingMatrices new_matrix(1);
        return new_matrix + 1.;
    }
    int s;
    OperatingMatrices t(this->operating_matrix.size());
    OperatingMatrices adj(this->operating_matrix.size());
    for (size_t i = 0; i < this->operating_matrix.size(); i++) {
        for (size_t j = 0; j < this->operating_matrix.size(); j++) {
            //To get cofactor of M[i][j]
            getCfactor(*this, t, i, j, this->operating_matrix.size());
            s = ((i+j)%2==0)? 1: -1; //sign of adj[j][i] positive if sum of row and column indexes is even.
            adj[j][i] = (s)*(determinant(t, this->operating_matrix.size()-1)); //Interchange rows and columns to get the transpose of the cofactor matrix
        }
    }
    return adj;
}

OperatingMatrices OperatingMatrices::inverse()
{
    // Find determinant of A[][]
    double det = determinant(*this, this->operating_matrix.size());
    if (det == 0.)
    {
        cout << "Singular matrix, can't find its inverse, returning N*N zeros matrix";
        return OperatingMatrices(this->operating_matrix.size());
    }

    // Find adjoint
    OperatingMatrices inv = this->adjoint()*(1./det);

    return inv;
}

vector <OperatingVectors>& OperatingMatrices::get() {
    return this->operating_matrix;
}

size_t OperatingMatrices::size() const {
    return this->operating_matrix.size();
}




