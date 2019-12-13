//
// Created by KITANE YOUSSEF on 09.12.19.
//

#include "gtest/gtest.h"
#include "Input/Input.h"
#include "Input/InputCreator/InputCreator.h"
#include "Data_Fitting/LeastSquares.h"
#include <vector>
using namespace std;

void ASSERT_VECTOR_EQUAL(vector<double> a, vector<double> b) {
    ASSERT_EQ( a.size(), b.size());
    for (int i = 0; i < a.size(); i++) {
        ASSERT_DOUBLE_EQ( a[i], b[i]);
    }
}

TEST(LeastSquares, solversimple){
    InputCreator input("y=x",vector<double> {-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10});
    LeastSquares solver(input.generate());
    ASSERT_VECTOR_EQUAL(solver.dataFitting(1), vector<double>{0.,1.});
}

TEST(LeastSquares, solvercomplex){
    InputCreator input("y=3x^(2)-6x+4",vector<double> {-20,-19,-18,-17,-16,-15,-14,-13,-12,-11,-10,-9,-8,-7,-6,-5,-4,
                                                      -3,-2,-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20});
    LeastSquares solver(input.generate());
    ASSERT_VECTOR_EQUAL(solver.dataFitting(2), vector<double>{4.,-6.,3.});
}

TEST(LeastSquares, loss){
    InputCreator input("y=x",vector<double> {0,1,2,3,4});
    LeastSquares solver(input.generate());
    vector<double> coeff = solver.dataFitting(0);
    ASSERT_DOUBLE_EQ(solver.leastSquareLoss(coeff), 10);
}