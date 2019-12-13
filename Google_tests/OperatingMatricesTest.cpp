//
// Created by KITANE YOUSSEF on 09.12.19.
//

#include "gtest/gtest.h"
#include "Operations/OperatingVectors.h"
#include "Operations/OperatingMatrices.h"

void ASSERT_VECTOR_EQUAL(OperatingVectors a, OperatingVectors b) {
    ASSERT_EQ( a.size(), b.size());
    for (int i = 0; i < a.size(); i++) {
        ASSERT_DOUBLE_EQ( a[i], b[i]);
    }
}

void ASSERT_MATRIX_EQUAL(OperatingMatrices a, OperatingMatrices b) {
    ASSERT_EQ( a.size(), b.size());
    for (int i = 0; i < a.size(); i++) {
        ASSERT_VECTOR_EQUAL(a[i], b[i]);
    }
}


TEST(OperatingMatrices, addition){
    OperatingMatrices m1(vector<vector<double>> {{1,0,0,0},{1,1,0,0},{1,1,1,0},{1,1,1,1}});
    OperatingMatrices m2(vector<vector<double>> {{1,1,1,1},{0,1,1,1},{0,0,1,1},{0,0,0,1}});
    OperatingMatrices m3(vector<vector<double>> {{2,1,1,1},{1,2,1,1},{1,1,2,1},{1,1,1,2}});

    ASSERT_MATRIX_EQUAL(m1+m2, m3);
}


TEST(OperatingMatrices, multiplication){
    OperatingMatrices m1(vector<vector<double>> {{1,0,0,0},{1,1,0,0},{1,1,1,0},{1,1,1,1}});
    OperatingMatrices m2(vector<vector<double>> {{1,1,1,1},{0,1,1,1},{0,0,1,1},{0,0,0,1}});
    OperatingMatrices m3(vector<vector<double>> {{1, 1, 1, 1}, {1, 2, 2, 2}, {1, 2, 3, 3}, {1, 2, 3, 4}});

    ASSERT_MATRIX_EQUAL(m1*m2, m3);
}


TEST(OperatingMatrices, vector_multiplication){
    OperatingMatrices m1(vector<vector<double>> {{1,0,0,0},{1,1,0,0},{1,1,1,0},{1,1,1,1}});
    OperatingVectors vec1(vector<double> {1,2,3,4});
    OperatingVectors vec2(vector<double> {1, 3, 6, 10});

    ASSERT_VECTOR_EQUAL(m1*vec1, vec2);
}


TEST(OperatingMatrices, determinant){
    vector<vector<double>> matrice = {{-16,-7,0,0},{-7,-2,6,0},{0,6,4,-4},{0,0,-4,14}};
    OperatingMatrices m(matrice);

    ASSERT_DOUBLE_EQ(m.determinant(m, 4), 7384);
}

TEST(OperatingMatrices, comatrix){
    vector<vector<double>> matrice = {{-16,-7,0,0},{-7,-2,6,0},{0,6,4,-4},{0,0,-4,14}};
    OperatingMatrices m(matrice);

    OperatingMatrices comatrix = m.adjoint();

    vector<vector<double>> real_comatrix = {{-584,280,-588,-168},{280,-640,1344,384},{-588,1344,-238,-68},{-168,384,-68,508}};
    OperatingMatrices m_real(real_comatrix);

    ASSERT_MATRIX_EQUAL(comatrix, m_real);
}


TEST(OperatingMatrices, transpose){
    vector<vector<double>> matrice = {{-16,-7,0,0},{-7,-2,6,0},{0,6,4,-4},{0,0,-4,14}};
    OperatingMatrices m(matrice);

    OperatingMatrices transpose = m.transpose();

    vector<vector<double>> real_transpose = {{-16,-7,0,0},{-7,-2,6,0},{0,6,4,-4},{0,0,-4,14}};
    OperatingMatrices m_real(real_transpose);

    ASSERT_MATRIX_EQUAL(transpose, m_real);
}





