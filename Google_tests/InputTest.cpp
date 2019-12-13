//
// Created by KITANE YOUSSEF on 09.12.19.
//

#include "gtest/gtest.h"
#include "Input/Input.h"
#include "Input/InputCreator/InputCreator.h"
#include "Input/InputReader/InputReader.h"
#include <vector>
using namespace std;

void ASSERT_MATRIX_EQUAL(vector<vector<double>> a, vector<vector<double>> b) {
    ASSERT_EQ( a.size(), b.size());
    for (size_t i = 0; i < a.size(); i++) {
        ASSERT_EQ( a[i].size(), b[i].size());
        for(size_t j = 0; j < a[i].size(); j++){
            ASSERT_DOUBLE_EQ( a[i][j], b[i][j]);
        }
    }
}

void ASSERT_MATRIX_NEARLY_EQUAL(vector<vector<double>> a, vector<vector<double>> b) {
    ASSERT_EQ( a.size(), b.size());
    for (size_t i = 0; i < a.size(); i++) {
        ASSERT_EQ( a[i].size(), b[i].size());
        for(size_t j = 0; j < a[i].size(); j++){
            ASSERT_LT( a[i][j]-b[i][j], 1e-12);
        }
    }
}

TEST(InputReader, generatetxt){
    vector<vector<double>> original_file = {{0,-2,2,3.6666, 4},{0,3.4,1,1.5,-2.0}};
    InputReader testinput("../../Google_tests/Test_Files/testinputtxt.txt");

    ASSERT_MATRIX_EQUAL(testinput.generate(), original_file);
}



TEST(InputReader, generatecsv){
    vector<vector<double>> original_file = {{0,0.5,1,1.5,2,2.5,3,3.5,4,4.5},{1,-0.5,-1,-1.5,-2,-15.3,-3.5,-3.5,-4,-4.5}};
    InputReader testinput("../../Google_tests/Test_Files/testinputcsv.csv");

    ASSERT_MATRIX_EQUAL(testinput.generate(), original_file);
}

TEST(InputCreator, generate_simple){
    vector<vector<double>> original_file = {{0,-2,2,3.6666, 4},{0,-2,2,3.6666,4}};
    InputCreator testinput("y=x", original_file[0]);

    ASSERT_MATRIX_EQUAL(testinput.generate(), original_file);
}


TEST(InputCreator, generate_complex){
    vector<vector<double>> original_file = {{0,-2,2,3.6666, 4},{13.4161468365471, 16.5133794749801, 19.3719254493227, 32.6094958453450, 36.2281276280071}};
    InputCreator testinput("y=x^(2)-cos(3x-2)+exp(0.5x)+12", original_file[0]);

    ASSERT_MATRIX_NEARLY_EQUAL(testinput.generate(), original_file);
}