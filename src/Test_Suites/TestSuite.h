//
// Created by morin on 06.12.2019.
//

#ifndef PROJET_TESTSUITE_H
#define PROJET_TESTSUITE_H

#include <vector>
#include <string>
#include "../Operations/OperatingMatrices.h"

using namespace std;

class TestSuite {
public:
    explicit TestSuite();

    void testInputs();
    void testOperatingVectors();
    void testOperatingMatrices();
    void testDataFitting();
    void testRun();
private:
    void display_matrix(const vector<vector<double>>& mat);
    void display_matrix(OperatingMatrices mat);
    void display_vector(const vector<double> &vec);


    string displayEquation(const vector<double>& coefficients);
};


#endif //PROJET_TEST_SUITE_H
