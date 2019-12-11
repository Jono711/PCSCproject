//
// Created by morin on 09.12.2019.
//

#include "Output.h"
#include <utility>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "math.h"

using namespace std;

Output::Output(vector<vector<double>> coefficients, vector<vector<double>> x_y_coords, string method, string output_type, bool regular_polynome) {
    this->coefficients = move(coefficients);
    if(x_y_coords.size()!=2){
        cout << x_y_coords.size() << endl;
        cout << "There shouldn't be more or less than two coordinates. Creating method with no coordinates." << endl;
        this->x_y_coords=vector<vector<double>> ();
    } else if(x_y_coords[0].size()!=x_y_coords[1].size()){
        cout << "The two coordinates don't have the same size. Creating method with no coordinates." << endl;
        this->x_y_coords=vector<vector<double>> ();
    } else {
        this->x_y_coords=move(x_y_coords);
    }
    this->method = move(method);
    if(output_type!="terminal" && output_type!="python" && output_type!="both"){
        cout << "Unknown output type. Switching to default type: terminal." << endl;
        this->output_type="terminal";
    } else {
        this->output_type=move(output_type);
    }

    this->regular_polynome = regular_polynome;
}

void Output::display(){
    if(output_type=="terminal" || output_type=="both")
        terminal_display();
    if(output_type=="python" || output_type=="both")
        python_display();
}

void Output::terminal_display() {
    cout << "The solution to " << method << endl
    << "with x and y data such as :" << endl;
    for(int i = 0; i <2 ; i++){
        if(i==0){
            cout << "x: (";
        } else {
            cout << "y: (";
        }
        for(const auto & elem : x_y_coords[i]){
            cout << elem;
            if (&elem != &x_y_coords[i].back()){
                cout << ", " ;
            }else{
                cout << ")" << endl;
            }
        }
    }
    cout << endl << "is the equation: " << this->displayEquation() << endl << endl;

}

void Output::python_display_polynome(ofstream &outputFile, vector<vector<double>> coefficients, vector<double> x_coords, bool regular_polynome) {

    if (coefficients.size() == 1) {
        outputFile << "x_conditions = [ x < float('inf') ]" << endl;
        outputFile << "y_list = ["
                    << endl;
    } else {
        outputFile << "x_conditions = [ " << endl;
        for (int i = 0; i < coefficients.size() ; i++) {
            outputFile << " (x >= " << to_string(x_coords[i])
                        << ") * ( "
                        << "x < " << to_string(x_coords[i+1])
                        << "),"
                        << endl;
        }
        outputFile << endl
                    << "]"
                    << endl;

        outputFile << "y_list = ["
                   << endl;

    }

    for (int a = 0; a < coefficients.size(); a++) {
        string equation("lambda x:");
        for (unsigned int i = coefficients[a].size() - 1; i > 0; --i) {
            if (coefficients[a][i] >= 0 && equation.size() > 2)
                equation += "+";
            equation += to_string(coefficients[a][i]);
            if (i == 1) {
                if (regular_polynome) {
                    equation += "*x";
                } else {
                    equation += "* (x ";
                    if (x_coords[a] < 0) {
                        equation += "+";
                    } else {
                        equation += "-";
                    }
                    equation += to_string(abs(x_coords[a]));
                    equation += ")";
                }
            } else {
                if (regular_polynome) {
                    equation += "*(x**(" + to_string(i) + "))";
                } else {
                    equation += "* ((x ";
                    if (x_coords[a] < 0) {
                        equation += "+";
                    } else {
                        equation += "-";
                    }
                    equation += to_string(abs(x_coords[a]));
                    equation += ")";

                    equation += "**(" + to_string(i) + "))";
                }
            }
        }

        if (coefficients[a][0] >= 0 && equation.size() > 2)
            equation += "+";
        equation += to_string(coefficients[a][0]);

        outputFile << equation << "," << endl;
    }

    outputFile << "] \n";
    outputFile << "y = np.piecewise(x, x_conditions, y_list)" << endl;

}
void Output::python_display() {
    replace(method.begin(), method.end(), ' ', '_');
    method =  method + ".py";
    ofstream outputFile;
    outputFile.open (method, std::ofstream::out | std::ofstream::trunc);
    if(!outputFile.is_open()){
        cout << method + " could not be opened." << endl;
    }else {
        outputFile << "import numpy as np\n"
                   << "import matplotlib.pyplot as plt\n\n";
        outputFile << "# Writing x and y starting points\n";
        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                outputFile << "x_points = np.array([";
            } else {
                outputFile << "y_points = np.array([";
            }
            for (const auto &elem : x_y_coords[i]) {
                outputFile << elem;
                if (&elem != &x_y_coords[i].back()) {
                    outputFile << ", ";
                } else {
                    outputFile << "])" << endl;
                }
            }
        }

        outputFile << "# Create a mesh with 1000 points from min(x)-0.05|min(x)| to max(x)+0.05|max(x)|\n";
        double x_max(x_y_coords[0][0]);
        double x_min(x_y_coords[0][0]);
        for (const auto &elem : x_y_coords[0]) {
            if (elem > x_max)
                x_max = elem;
            if (elem < x_min)
                x_min = elem;
        }
        x_max += 0.05 * abs(x_max);
        x_min -= 0.05 * abs(x_min);

        outputFile << "x = np.linspace(" << x_min << ", " << x_max << ", 1000)\n\n";

        this->python_display_polynome(outputFile, coefficients, x_y_coords[0], regular_polynome);

        outputFile
                << "plt.plot(x_points, y_points, color=\"red\", marker=\"+\", linestyle=\"\", label=\"Data points\")\n"
                << R"(plt.plot(x, y, color="blue", linewidth=2.5, linestyle="-", label=")" << method << "\")\n"
                << "# Adding legends\n"
                << "plt.legend()\n\n"
                << "plt.show() # show figure";

        outputFile.flush();

        outputFile.close();


        cout << "Successfully created the python file." << endl;
    }
}

void Output::full_display() {
    terminal_display();
    python_display();
}

string Output::displayEquation() {
    string to_return("y=");
    for(unsigned int i = coefficients.size()-1; i > 0; --i){
        if (coefficients[0][i] >= 0 && to_return.size() > 2)
            to_return += "+";
        to_return += to_string(coefficients[0][i]);
        if (i==1) {
            to_return += "x";
        }else{
            to_return += "x^(" + to_string(i) + ")";
        }
    }

    if (coefficients[0][0] >= 0 && to_return.size() > 2)
        to_return += "+";
    to_return += to_string(coefficients[0][0]);

    return to_return;
}



void Output::displayNaturalSpline(OperatingMatrices natural_spline_matrix, OperatingVectors natural_spline_vector, OperatingMatrices coefficients,
                                  vector<double> x_coords) {
    cout << "Natural spline matrix = [" << endl;
    Output::displayMatrix(natural_spline_matrix);
    cout << "]" << endl;
    cout << "" << endl ;

    cout << "Natural spline vector = [ " ;
    Output::displayVector(natural_spline_vector);
    cout << "]" << endl;
    cout << "" << endl ;

    cout << "Natural spline coefficients = [" << endl;
    Output::displayMatrix(coefficients);
    cout << "]" << endl;
    cout << "" << endl ;

    for( int i = 0 ; i < coefficients.size(); i++){
        char buffer[100];
        sprintf(buffer, "Equation pour le polynome interpolant entre x[%d] et x[%d]",i,i+1);
        cout << buffer;
        cout << "" << endl;

        sprintf(buffer, "Y%d =", i);
        cout << buffer;

        if(x_coords[i] >= 0) {
            float abs_coord_i = abs(x_coords[i]);
            sprintf(buffer, " %.2f(x-%.2f)^3 + %.2f(x-%.2f)^2 + %.2f(x-%.2f)",
                    coefficients[i][0],abs_coord_i, coefficients[i][1], abs_coord_i, coefficients[i][2], abs_coord_i);
        } else {
            float abs_coord_i = abs(x_coords[i]);
            sprintf(buffer, " %.2f(x+%.2f)^3 + %.2f(x+%.2f)^2 + %.2f(x+%.2f)",
                    coefficients[i][0],abs_coord_i, coefficients[i][1], abs_coord_i, coefficients[i][2], abs_coord_i);
        }
        cout << buffer;

        if (coefficients[i][3] >=0) {
            float abs_const = abs(coefficients[i][3]);
            sprintf(buffer, " + %.2f", abs_const);
        } else {
            float abs_const = abs(coefficients[i][3]);
            sprintf(buffer, " - %.2f", abs_const);
        }
        cout << buffer;

        cout << "" << endl ;
        cout << "" << endl ;
    }
}


void Output::displayClampedSpline(OperatingMatrices natural_spline_matrix, OperatingVectors natural_spline_vector, OperatingMatrices coefficients,
                                  vector<double> x_coords) {

    cout << "Clamped spline matrix = [" << endl;
    Output::displayMatrix(natural_spline_matrix);
    cout << "]" << endl;
    cout << "" << endl ;

    cout << "Clamped spline vector = [ " ;
    Output::displayVector(natural_spline_vector);
    cout << "]" << endl;
    cout << "" << endl ;

    cout << "Clamped spline coefficients = [" << endl;
    Output::displayMatrix(coefficients);
    cout << "]" << endl;
    cout << "" << endl ;

    for( int i = 0 ; i < coefficients.size(); i++){
        char buffer[100];
        sprintf(buffer, "Equation pour le polynome interpolant entre x[%d] et x[%d]",i,i+1);
        cout << buffer;
        cout << "" << endl;

        sprintf(buffer, "Y%d =", i);
        cout << buffer;

        if(x_coords[i] >= 0) {
            float abs_coord_i = abs(x_coords[i]);
            sprintf(buffer, " %.2f(x-%.2f)^3 + %.2f(x-%.2f)^2 + %.2f(x-%.2f)",
                    coefficients[i][0],abs_coord_i, coefficients[i][1], abs_coord_i, coefficients[i][2], abs_coord_i);
        } else {
            float abs_coord_i = abs(x_coords[i]);
            sprintf(buffer, " %.2f(x+%.2f)^3 + %.2f(x+%.2f)^2 + %.2f(x+%.2f)",
                    coefficients[i][0],abs_coord_i, coefficients[i][1], abs_coord_i, coefficients[i][2], abs_coord_i);
        }
        cout << buffer;

        if (coefficients[i][3] >=0) {
            float abs_const = abs(coefficients[i][3]);
            sprintf(buffer, " + %.2f", abs_const);
        } else {
            float abs_const = abs(coefficients[i][3]);
            sprintf(buffer, " - %.2f", abs_const);
        }
        cout << buffer;

        cout << "" << endl ;
        cout << "" << endl ;
    }

}

 void  Output::displayPolynomeInterpolation(OperatingMatrices VandermondeMatrix, OperatingVectors y_coords,OperatingVectors coefficients){
     cout << "Vandermonde matrix = [" << endl;
     Output::displayMatrix(VandermondeMatrix);
     cout << "]" << endl;
     cout << "" << endl ;

     cout << "Coordinates of y vector = [ " ;
     Output::displayVector(y_coords);
     cout << "]" << endl;
     cout << "" << endl ;

     cout << "Coefficients of the interpolating polynome = [ " ;
     Output::displayVector(coefficients);
     cout << "]" << endl;
     cout << "" << endl ;

     char buffer[100];
     sprintf(buffer, "Equation pour le polynome interpolant de degré %d",coefficients.size()-1);
     cout << buffer;
     cout << "" << endl;
     sprintf(buffer, "P(x) = ");
     cout << buffer;

     //Afficher l'equation :
     //poly(x) = an*x(n) + an-1*x(n-1) + an-2*x(n-2) + .... + a2*x(2) + a1*x(1) + a0
     for ( int i = 0 ; i < coefficients.size() ; i++ ) {
            if ( i != coefficients.size()-1){
                sprintf(buffer, "%.2fx^%d + ",coefficients[i],coefficients.size()-i-1) ;
                cout << buffer ;
            } else {
                sprintf(buffer, " %.2f ",coefficients[i]) ;
                cout << buffer ;
            }
     }
}


void Output::displayMatrix(OperatingMatrices m) {
    for (int i = 0; i < m.size(); i ++) {
        Output::displayVector( m[i] );
        cout << endl;
    }
}

void Output::displayVector(OperatingVectors m) {
    for (int i = 0; i < m.size(); i++ ) {
        cout << m[i] << " ";
    }
}


