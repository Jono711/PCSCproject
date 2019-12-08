//
// Created by morin on 06.12.2019.
//

#ifndef PROJET_TESTSUITE_H
#define PROJET_TESTSUITE_H

#include <vector>
#include "../Operations/OperatingMatrices.h"

using namespace std;

class TestSuite {
public:
    explicit TestSuite();

    void testInputs();
    void testOperatingVectors();
    void testOperatingMatrices();
    void testDataFitting();

private:
    void display_matrix(const vector<vector<double>>& mat);
    void display_matrix(OperatingMatrices mat);
    void display_vector(const vector<double> &vec);

};


#endif //PROJET_TEST_SUITE_H
