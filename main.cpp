#include "src/Data_approximation/Polynomial_approximation.h"
#include "src/Operations/OperatingVectors.h"
#include "src/Operations/OperatingMatrices.h"

#include <iostream>
using namespace std;

int main() {
    //TestSuite test1;
    // test1.testDataFitting();


    vector<double> operating_vector = {1,3,4,8,4,2};
    OperatingVectors vecteur(operating_vector);
    Polynomial_approximation poly_1;
    OperatingVectors resultat_diff = poly_1.difference_data(vecteur) ;

    resultat_diff.afficher_Operating_vector();

    cout << "Hello" << endl;

    return 0;
}

