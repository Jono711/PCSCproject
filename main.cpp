#include "Data_approximation/PolynomialApproximationTest.h"
#include "src/Operations/OperatingVectors.h"
#include "src/Operations/OperatingMatrices.h"
#include "src/Run/Run.h"
#include "src/Output/Output.h"

#include <iostream>
using namespace std;

int main() {
    //TestSuite test1;
    // test1.testDataFitting();

    /*
    vector<double> operating_vector = {1,3,4,8,4,2};
    OperatingVectors vecteur(operating_vector);
    PolynomialApproximationTest poly_1;
    OperatingVectors resultat_diff = poly_1.difference_data(vecteur) ;

    resultat_diff.afficher_Operating_vector();
    */

    /*
    Run run("creator", "", "y=x", true,
    vector<double>(), false, "Data_Fitting", 2, "both");
    run.launch();
    */

    //vector<double> coefficients;
    //vector<double> x_coords;
    //vector<double> y_coords;

    vector<double> x_coordinate = {3,2,-5,1,-3,8};
    OperatingVectors transformed_x(x_coordinate);

    vector<double> y_coordinate = {4,1,-3,6,-2,-4};
    OperatingVectors transformed_y(y_coordinate);

    PolynomialApproximationTest m ;
    OperatingMatrices natural_spline_matrix  = m.natural_spline_data_matrix(transformed_x);
    OperatingVectors natural_spline_vector = m.natural_spline_vector(transformed_x,transformed_y);

    OperatingVectors derivatives  = (natural_spline_matrix.inverse())*natural_spline_vector ;

    OperatingMatrices coefficients = m.natural_spline_coefficients(derivatives,transformed_x,transformed_y);


    Output::displayNaturalSpline(natural_spline_matrix, natural_spline_vector, coefficients, x_coordinate );
    // Afficher natural_spline_matrix
    // Afficher natural_spline_vector
    // Afficher derivatives
    // Afficher coefficents
    // Afficher equation en fonction des coefficients

    return 0;
}

