//
// Created by morin on 06.12.2019.
//

#include "TestSuite.h"
#include "../Input/Input.h"
#include "../Input/InputCreator/InputCreator.h"
#include "../Input/InputReader/InputReader.h"
#include "../Operations/OperatingMatrices.h"
#include "../Operations/OperatingVectors.h"
#include "../Data_Fitting/LeastSquares.h"
#include "../Run/Run.h"
#include <iostream>
#include <vector>
using namespace std;

TestSuite::TestSuite() = default;

void TestSuite::display_matrix(const vector<vector<double>>& x_y_coords){
    bool first_row = true;
    for(const auto& row : x_y_coords){
        if (first_row){
            cout << "x: ";
            first_row = false;
        } else {
            cout << "y: ";
            first_row = true;
        }
        for(const auto& dat : row){
            cout << dat << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

void TestSuite::display_matrix(OperatingMatrices mat){
    for(size_t i(0); i < mat.get().size(); i++){
        for(size_t j(0); j < mat.get()[0].size(); j++){
            cout << mat[i][j] << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

void TestSuite::display_vector(const vector<double>& x_coords){
    cout << "x: ";
    for(const auto& elem : x_coords){
        cout << elem << ", ";
    }
    cout << endl << endl;
}

string TestSuite::displayEquation(const vector<double>& coefficients) {
    string to_return("y=");
    for(unsigned int i = coefficients.size()-1; i > 0; --i){
        if (coefficients[i] > 0 && to_return.size() > 2)
            to_return += "+";
        to_return += to_string(coefficients[i]);
        if (i==1) {
            to_return += "x";
        }else{
            to_return += "x^(" + to_string(i) + ")";
        }
    }

    if (coefficients[0] > 0 && to_return.size() > 2)
        to_return += "+";
    to_return += to_string(coefficients[0]);

    return to_return;
}


void TestSuite::testInputs() {
    // Test of  InputReader class

    // Starting test, when everything should be running perfectly
    cout << "test InputReader file.dat:" << endl;
    InputReader testinputreader(R"(C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\Test_Suites\Test_Files\testinputdat.dat)");
    vector<vector<double>> x_y_coords = testinputreader.generate();
    display_matrix(x_y_coords);


    cout << "test InputReader file.txt:" << endl;
    testinputreader = InputReader(R"(C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\Test_Suites\Test_Files\testinputtxt.txt)");
    x_y_coords = testinputreader.generate();
    display_matrix(x_y_coords);

    cout << "test InputReader file.csv:" << endl;
    testinputreader = InputReader(R"(C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\Test_Suites\Test_Files\testinputcsv.csv)");
    x_y_coords = testinputreader.generate();
    display_matrix(x_y_coords);

    // Second test, with 'questionable' data
    cout << "test false InputReader file.txt:" << endl;
    testinputreader = InputReader(R"(C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\Test_Suites\Test_Files\testfalseinputtxt.txt)");
    x_y_coords = testinputreader.generate();
    display_matrix(x_y_coords);

    cout << "test false InputReader file.txt:" << endl;
    testinputreader = InputReader(R"(C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\Test_Suites\Test_Files\noinput)");
    x_y_coords = testinputreader.generate();
    display_matrix(x_y_coords);


    // Test of  InputCreator

    // Starting test, when everything should be running perfectly
    cout << "test InputCreator y=x+1:" << endl;
    InputCreator testinputcreator("y=x+1");
    x_y_coords = testinputcreator.generate();
    display_matrix(x_y_coords);

    cout << "test InputCreator y=2.5x^(2.5)+cos(x+3.14)-2.5sin(x-3.14)-0.5exp(-3x+6):" << endl;
    testinputcreator = InputCreator("y=2.5x^(2.5)+cos(x+3.14)-2.5sin(x-3.14)-0.5exp(-3x+6)");
    x_y_coords = testinputcreator.generate();
    display_matrix(x_y_coords);

    cout << "test InputCreator y=x+1 with x={0,1,2} and adding some random displacement:" << endl;
    testinputcreator = InputCreator("y=x+1", vector<double> {0, 1, 2}, true);
    x_y_coords = testinputcreator.generate();
    display_matrix(x_y_coords);

    // Second test, with 'questionable' data
    cout << "test false InputCreator y=x^(-1)" << endl;
    testinputcreator = InputCreator("y=x^(-1)");
    x_y_coords = testinputcreator.generate();
    display_matrix(x_y_coords);

    cout << "test false InputCreator y=x^(0.5)" << endl;
    testinputcreator = InputCreator("y=x^(0.5)", vector<double> {-1, 0, 1});
    x_y_coords = testinputcreator.generate();
    display_matrix(x_y_coords);

    cout << "test false InputCreator y=23x*x" << endl;
    testinputcreator = InputCreator("y=23x*x");
    x_y_coords = testinputcreator.generate();
    display_matrix(x_y_coords);
}

void TestSuite::testOperatingVectors() {

    // Test under 'normal' conditions.
    cout << "Normal conditions:" << endl;
    OperatingVectors vec1(vector<double> {0,1,2});
    OperatingVectors vec2(vector<double> {0,1,2});

    cout << "test getter:" << endl;
    display_vector(vec1.get());

    cout << "test addition with double:" << endl;
    OperatingVectors result = (vec1+1.);
    display_vector(result.get());

    cout << "test multiplication with double:" << endl;
    result = vec1*2.;
    display_vector(result.get());

    cout << "test addition with vector:" << endl;
    result = vec1+vec2;
    display_vector(result.get());

    cout << "test multiplication with vector:" << endl;
    cout << "x: " << vec1*vec2 << endl << endl;;

    cout << "test power:" << endl;
    result = vec1^2;
    display_vector(result.get());


    // Test under 'anormal' conditions.
    cout << "Anormal conditions:" << endl;
    vec1 = OperatingVectors(vector<double> {0,1});
    vec2 = OperatingVectors(vector<double> {0,1,2,3});

    cout << "test addition with vector:" << endl;
    result = vec1+vec2;
    display_vector(result.get());

    cout << "test addition with vector (other side):" << endl;
    result = vec2+vec1;
    display_vector(result.get());

    cout << "test multiplication with vector:" << endl;
    cout << "x: " << vec1*vec2 << endl << endl;;

    cout << "test multiplication with vector (other side):" << endl;
    cout << "x: " << vec2*vec1 << endl << endl;;
}

void TestSuite::testOperatingMatrices() {

    // Test under 'normal' conditions.
    cout << "Normal conditions:" << endl;
    OperatingVectors vec1(vector<double> {0,1,2}), vec2(vector<double> {3,4,5}), vec3(vector<double> {6,7,8});
    OperatingVectors vec4(vector<double> {1,0,0}), vec5(vector<double> {0,1,0}), vec6(vector<double> {0,0,1});
    OperatingMatrices mat1(vector<OperatingVectors> {vec1, vec2, vec3}), mat2(vector<OperatingVectors> {vec4, vec5, vec6});

    cout << "test display:" << endl;
    display_matrix(mat1);

    cout << "test addition with double:" << endl;
    display_matrix(mat1+1.);

    cout << "test multiplication with double:" << endl;
    display_matrix(mat1*2.);

    cout << "test addition with matrix:" << endl;
    display_matrix(mat1+mat2);

    cout << "test multiplication with matrix:" << endl;
    display_matrix(mat1*mat2);

    cout << "test multiplication with vector:" << endl;
    display_vector((mat1*vec1).get());

    cout << "test transpose:" << endl;
    display_matrix(mat1.transpose());

    cout << "test determinant:" << endl;
    cout << "det: " << mat2.determinant(mat2, mat2.get().size()) << endl;

    OperatingMatrices mat3(vector<OperatingVectors> {vec1, vec2, vec4});
    cout << "test inverse:" << endl;
    display_matrix(mat3.inverse());


    // Test under 'anormal' conditions.
    cout << "Anormal conditions:" << endl;
    OperatingMatrices mat4(vector<OperatingVectors> {vec1});
    OperatingVectors vec0(vector<double> {1,0});

    cout << "test wrong matrix dimension:" << endl;
    OperatingMatrices mat5(vector<OperatingVectors> {vec1, vec0});
    display_matrix(mat5);

    cout << "test addition with matrix:" << endl;
    display_matrix(mat1+mat4);

    cout << "test addition with matrix (other side):" << endl;
    display_matrix(mat4+mat1);

    cout << "test multiplication with matrix:" << endl;
    display_matrix(mat1*mat4);

    cout << "test multiplication with matrix (other side):" << endl;
    display_matrix(mat4*mat1);

    cout << "test transpose:" << endl;
    display_matrix(mat4.transpose());

    cout << "test multiplication with vector:" << endl;
    display_vector((mat4.transpose()*vec1).get());

    cout << "test determinant:" << endl;
    cout << "det: " << mat4.determinant(mat4, mat4.get().size()) << endl;

    cout << "test inverse:" << endl;
    display_matrix(mat4.inverse());
}

void TestSuite::testDataFitting() {

    // Test under 'normal' conditions.
    InputCreator generator("y=1");
    vector<vector<double>> x_y_coords = generator.generate();
    LeastSquares solver(x_y_coords);
    vector<double> coefficients = solver.dataFitting(0);
    cout << "test for y=1, solver 0D."<< endl;
    cout << displayEquation(coefficients) << endl;

    generator = InputCreator("y=3.5x+2");
    x_y_coords = generator.generate();
    solver = LeastSquares(x_y_coords);
    coefficients = solver.dataFitting(1);
    cout << "test for y=3.5x+2, solver 1D." << endl;
    cout << displayEquation(coefficients) << endl;

    generator = InputCreator("y=-2.66x^(6)+2.34x^(3)+1.76x^(2)+2.66x^(5)+2",{-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10});
    x_y_coords = generator.generate();
    solver = LeastSquares(x_y_coords);
    coefficients = solver.dataFitting(6);
    cout << "test for y=-2.66x^(6)+2.34x^(3)+1.76x^(2)+2.66x^(5)+2, solver 6D."<< endl;
    cout << displayEquation(coefficients) << endl;


    // Test under 'Anormal' conditions.
    generator = InputCreator("y=-2.66x^(6)+2.34x^(3)+1.76x^(2)+2.66x^(5)+2",{-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10});
    x_y_coords = generator.generate();
    x_y_coords.push_back(vector<double> {3.44});
    cout << "test for three-dimensional input."<< endl;
    solver = LeastSquares(x_y_coords);


    generator = InputCreator("y=x", {-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10}, true);
    x_y_coords = generator.generate();
    solver = LeastSquares(x_y_coords);
    coefficients = solver.dataFitting(2);
    cout << "test for y=x with random displacement, solver 2D."<< endl;
    cout << displayEquation(coefficients) << endl;

}

void TestSuite::testRun() {
    // First test
    Run run("creator", "", "y=x", true, vector<double>(), false, "Data_Fitting", 1, "both") ;
    run.launch();

    // Second test
    Run run2("creator", "", "y=x^(2)+1", false, {-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10}, true,
            "Data_Fitting_Find", 7, "both");
    run2.launch();
}