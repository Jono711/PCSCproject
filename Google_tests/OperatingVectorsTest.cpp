//
// Created by KITANE YOUSSEF on 09.12.19.
//

#include "gtest/gtest.h"
#include "Operations/OperatingVectors.h"
#include <vector>
using namespace std;


void ASSERT_VECTOR_EQUAL3(OperatingVectors a, OperatingVectors b) {
    ASSERT_EQ( a.size(), b.size());
    for (int i = 0; i < a.size(); i++) {
        ASSERT_DOUBLE_EQ( a[i], b[i]);
    }
}


TEST(OperatingVectors, addition){
    OperatingVectors vec1(vector<double> {1,2,3,4,5,6});
    OperatingVectors vec2(vector<double> {6,5,4,3,2,1});
    OperatingVectors answ(vector<double> {7,7,7,7,7,7});

    ASSERT_VECTOR_EQUAL3(vec1+vec2, answ);
}

TEST(OperatingVectors, multiplication){
    OperatingVectors vec1(vector<double> {1,2,3,4,5,6});
    OperatingVectors vec2(vector<double> {6,5,4,3,2,1});
    double answ(56);

    ASSERT_DOUBLE_EQ(vec1*vec2, answ);
}


TEST(OperatingVectors, power){
    OperatingVectors vec1(vector<double> {1,2,3,4,5,6});
    OperatingVectors answ(vector<double> {1,8,27,64,125,216});

    ASSERT_VECTOR_EQUAL3(vec1^3, answ);

}





