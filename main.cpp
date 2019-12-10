#include "Data_approximation/PolynomialApproximationTest.h"
#include "src/Operations/OperatingVectors.h"
#include "src/Operations/OperatingMatrices.h"
#include "src/Run/Run.h"


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

    Run run("creator", "", "y=x", true,
    vector<double>(), false, "Data_Fitting", 2, "both");
    run.launch();

    cout << "Hello" << endl;

    return 0;
}

