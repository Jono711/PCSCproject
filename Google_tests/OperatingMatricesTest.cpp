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