//
// Created by KITANE YOUSSEF on 09.12.19.
//

#include "gtest/gtest.h"
#include "Data_approximation/PolynomialApproximationTest.h"

void ASSERT_VECTOR_EQUAL2(OperatingVectors a, OperatingVectors b) {
    ASSERT_EQ( a.size(), b.size());
    for (int i = 0; i < a.size(); i++) {
        ASSERT_DOUBLE_EQ( a[i], b[i]);
    }
}
void ASSERT_MATRIX_EQUAL2(OperatingMatrices a, OperatingMatrices b) {
    ASSERT_EQ( a.size(), b.size());
    for (int i = 0; i < a.size(); i++) {
        ASSERT_VECTOR_EQUAL2(a[i], b[i]);
    }
}



TEST(PolynomialApproximation, natural_spline_data_matrix){
    vector<double> x_coordinate = {3,2,-5,1,-3,8};
    OperatingVectors transformed(x_coordinate);
    PolynomialApproximationTest m;

    OperatingMatrices matrix = m.natural_spline_data_matrix(transformed);

    vector<vector<double>> real_matrix =  {{-16,-7,0,0},{-7,-2,6,0},{0,6,4,-4},{0,0,-4,14}};
    OperatingMatrices m_real(real_matrix);

    ASSERT_MATRIX_EQUAL2(matrix,m_real);
}

TEST(PolynomialApproximation, clamped_spline_data_matrix) {
    vector<double> x_coordinate = {3,2,-5,1,-3,8};
    OperatingVectors transformed(x_coordinate);
    PolynomialApproximationTest m;

    OperatingMatrices matrix = m.clamped_spline_data_matrix(transformed);
    vector<vector<double>> real_matrix =  {{-2,-1,0,0,0,0},{-1,-16,-7,0,0,0},{0,-7,-2,6,0,0},{0,0,6,4,-4,0},{0,0,0,-4,14,11},{0,0,0,0,11,22}};
    OperatingMatrices m_real(real_matrix);

    ASSERT_MATRIX_EQUAL2(matrix,m_real);

}

TEST(PolynomialApproximation, natural_spline_vector) {

    vector<double> x_coordinate = {3,2,-5,1,-3,8};
    OperatingVectors transformed_x(x_coordinate);

    vector<double> y_coordinate = {4,1,-3,6,-2,-4};
    OperatingVectors transformed_y(y_coordinate);

    PolynomialApproximationTest m;

    OperatingVectors result = m.natural_spline_vector(transformed_x,transformed_y);

    vector<double> real_result = {(24.0/7)-18,9-(24.0/7),3,(-12.0/11)- 12};
    OperatingVectors  m_real(real_result);

    ASSERT_VECTOR_EQUAL2(result, m_real);

}

TEST(PolynomialApproximation, clamped_spline_vector) {

vector<double> x_coordinate = {3,2,-5,1,-3,8};
OperatingVectors transformed_x(x_coordinate);

vector<double> y_coordinate = {4,1,-3,6,-2,-4};
OperatingVectors transformed_y(y_coordinate);

double A = 2;
double B = 1;

PolynomialApproximationTest m;

OperatingVectors result = m.clamped_spline_vector(transformed_x,transformed_y,A,B);
vector<double> real_vector =  {6, (24.0/7)-18 ,9-(24.0/7), 3 ,(-12.0/11)-12,6 + (12.0/11)};
OperatingVectors m_real(real_vector);

ASSERT_VECTOR_EQUAL2(result,m_real);

}

TEST(PolynomialApproximation, polynomial_interpolation_data_matrix) {

vector<double> x_coordinate = {3,2,-5,1,-3,8};
OperatingVectors transformed(x_coordinate);

int degree = 3 ;

PolynomialApproximationTest m;

OperatingMatrices matrix  = m.polynomial_interpolation_data_matrix(transformed, degree) ;
vector<vector<double>> real_matrix = {{27,9,3,1},{8,4,2,1},{-125,25,-5,1},{1,1,1,1},{-27,9,-3,1},{512,64,8,1}};
OperatingMatrices  m_real(real_matrix);

ASSERT_MATRIX_EQUAL2(matrix,m_real);

}


TEST(PolynomialApproximation, Coefficients_natural_spline) {

vector<double> derivatives = {1,2,-3,1};
OperatingVectors transformed_d(derivatives);

vector<double> x_coordinate = {3,2,-5,1,-3,8};
OperatingVectors transformed_x(x_coordinate);

vector<double> y_coordinate = {4,1,-3,6,-2,-4};
OperatingVectors transformed_y(y_coordinate);

PolynomialApproximationTest m ;
OperatingMatrices  matrix = m.natural_spline_coefficients(transformed_d,transformed_x,transformed_y);

vector<vector<double>> real_matrix = {{(-1.0/6),0.5,3+(1.0/6),4},{(-1.0/42),1,(4.0/7)+(28.0/6),1},
                                      {(-5.0/36),-1.5,0.5,-3},{(-4.0/24),0.5,2-(10.0/3),6},
                                      {(-1.0/66),0,(-2.0/11)-(22.0/6),-2}};



OperatingMatrices  m_real(real_matrix);

ASSERT_MATRIX_EQUAL2(matrix,m_real);

}



TEST(PolynomialApproximation,Coefficients_clamped_spline) {

vector<double> derivatives = {1,1,2,-3,1,3};
OperatingVectors transformed_d(derivatives);

vector<double> x_coordinate = {3,2,-5,1,-3,8};
OperatingVectors transformed_x(x_coordinate);


vector<double> y_coordinate = {4,1,-3,6,-2,-4};
OperatingVectors transformed_y(y_coordinate);

PolynomialApproximationTest m ;

OperatingMatrices  matrix = m.clamped_spline_coefficients(transformed_d, transformed_x, transformed_y) ;

vector<vector<double>> real_matrix = {{0,0.5,3.5,4},{(-1.0/42),0.5,(4.0/7)+(28.0/6),1},
                                      {(-5.0/36),1,0.5,-3},{(-4.0/24),-1.5,2-(10.0/3),6},
                                      {(2.0/66),0.5,(-2.0/11)-(55.0/6),-2}};

OperatingMatrices  m_real(real_matrix);

ASSERT_MATRIX_EQUAL2(matrix,m_real);

}


TEST(PolynomialApproximation, Coefficients_hermite) {

    vector<double> x_coordinate = {3,2,-5,1,-3,8};
    OperatingVectors transformed_x(x_coordinate);

    PolynomialApproximationTest m ;
    double x = 1 ;

    OperatingMatrices matrix = m.poly_cubic_hermite_interpolation_data_coefficients(transformed_x,x);

    vector<vector<double>> real_matrix = {{5,-4,-2,-4},{(324.0/343),(19.0/343),(-36.0/49),(6.0/49)},
                                          {0,1,0,0},{1,0,0,0},
                                          {(931.0/1331),(400.0/1331),(196.0/121),(-112.0/121)}};

    OperatingMatrices  m_real(real_matrix);

    ASSERT_MATRIX_EQUAL2(matrix,m_real);

}


TEST(PolynomialApproximation , Difference) {

    vector<double> x_coordinate = {3,2,-5,1,-3,8};
    OperatingVectors transformed_x(x_coordinate);

    PolynomialApproximationTest m ;

    OperatingVectors result = m.difference_data(transformed_x);

    vector<double> real_result = {-1,-7,6,-4,11};
    OperatingVectors m_real(real_result);

    ASSERT_VECTOR_EQUAL2(result,m_real);
}


TEST(PolynomialApproximation, invert_Polynomial_interpolation){
    vector<double> b = {3,2,-5,1,-3,8};
    OperatingVectors transformed_b(b);

    vector<double> x_coordinate = {3,2,-5,1,-3,8};
    OperatingVectors transformed_x(x_coordinate);

    int degree = 5 ;

    PolynomialApproximationTest m;
    OperatingMatrices matrix  = m.polynomial_interpolation_data_matrix(transformed_x, degree) ;


    OperatingMatrices invert_matrix = matrix.inverse();

    OperatingVectors result = invert_matrix*transformed_b ;


}






