//
// Created by morin on 09.12.2019.
//

#include "Run.h"
#include "Output/Output.h"
#include "Input/InputCreator/InputCreator.h"
#include "Input/InputReader/InputReader.h"
#include "Data_Fitting/LeastSquares.h"
#include "RunParamReader.h"
#include "Data_approximation/PolynomialApproximation.h"

#include <iostream>
#include <vector>

const double DBL_MAX = 5;
Run::Run() {
    RunParamReader a;
    // Choisir input + paramètre input
    string param = a.retrieveInput(
            "Choose the type of input of your data:",
            {"reader", "creator"}
            );

    if(param == "reader"){
        string filename = a.retrieveFreeTextInput("Precise the absolute filepath for InputReader:");
        input = new InputReader(filename);
    } else if(param == "creator"){
        string function = a.retrieveFreeTextInput("Precise the function for InputCreator:");

        string default_parameters_str = a.retrieveInput(
                "Do you want default parameters?",
                {"true", "false"}
        );
        bool default_parameters = (default_parameters_str == "true");

        if(!default_parameters){
            vector<double> x_coords = a.retrieveDoubleVector("Precise your coordinates x:");
            string randomize_str = a.retrieveInput(
                    "Do you want to randomize your coordinates?",
                    {"true", "false"}
            );
            bool randomize = (default_parameters_str == "true");

            input = new InputCreator(function, x_coords, randomize);
        }else{
            input = new InputCreator(function);
        }
    }

    // Choisir opération + paramètre opération
    operation = a.retrieveInput(
            "Choose the type of data analysis you want to do:",
            {
                "DataFitting",
                 "DataFittingFind",
                 "InterpolationClamped",
                 "InterpolationNatural",
                 "PolyInterpolation"
            }
    );


    if(operation == "DataFitting"){
        degree = a.retrieveInt("Enter the degree of the polynome to be computed");
    }
    if(operation == "DataFittingFind"){
        degree = a.retrieveInt("Enter the maximum degree of the polynome to be considered: ");
    }
    if(operation == "InterpolationClamped") {
        A = a.retrieveDouble("Specify first derivative at the first point");
        B = a.retrieveDouble("Specify first derivative at the end point");
    }

    output_type = a.retrieveInput(
            "Choose the type of output you want:",
            { "terminal", "python", "both" }
    );

}

Run::~Run() {
    delete input;
}

void Run::launch() {
    cout << "Running operation"
        << operation
        << endl;

    vector<vector<double>> x_y_coords = input->generate();

    if(operation=="DataFitting"){
        launchDataFitting(x_y_coords, degree);
    }else if(operation == "DataFittingFind"){
        launchDataFittingFind(x_y_coords, degree);
    }else if(operation == "InterpolationClamped"){
        launchInterpolationClamped(x_y_coords, A, B);
    }else if(operation == "InterpolationNatural"){
        launchInterpolationNatural(x_y_coords);
    }else if(operation == "PolyInterpolation"){
        launchPolyInterpolation(x_y_coords);
    }
}

void Run::launchDataFitting(vector<vector<double>> x_y_coords, int degree) {
    LeastSquares solver(x_y_coords);
    vector<double> coefficients = solver.dataFitting(degree);

    vector<vector<double>> coeffs_final = {coefficients};
    Output output(coeffs_final,
            x_y_coords,
            operation,
            operation +"_degree_" + to_string(degree),
            output_type,
            true);
    output.terminal_display();
    output.python_display();
}

void Run::launchDataFittingFind(vector<vector<double>> x_y_coords, int degree) {
    // Variables to store the best lost and the best coefficients.
    double best_loss(DBL_MAX);
    unsigned int best_degree;
    vector<double> best_coefficients;

    LeastSquares solver(x_y_coords);
    for(int i(0); i<=degree; i++){
        vector<double> coefficients = solver.dataFitting(i);
        double loss = solver.leastSquareLoss(coefficients);
        if(loss < best_loss){
            best_loss = loss;
            best_degree = i;
            best_coefficients = coefficients;
        }
    }
    vector<vector<double>> best_coeffs_final = { best_coefficients };
    Output output(best_coeffs_final,
            x_y_coords,
            operation,
            operation + "_best_degree_" + to_string(best_degree) + "_with_loss_" + to_string(best_loss),
            output_type,
            true);
    output.terminal_display();
    output.python_display();
}

void Run::launchInterpolationClamped(vector<vector<double>> x_y_coords, double A, double B) {
    vector<double> x_coords = x_y_coords[0];
    vector<double> y_coords = x_y_coords[1];

    OperatingVectors transformed_x(x_coords);
    OperatingVectors transformed_y(y_coords);

    PolynomialApproximation solver;
    OperatingMatrices clamped_spline_matrix  = solver.clamped_spline_data_matrix(transformed_x);
    OperatingVectors clamped_spline_vector = solver.clamped_spline_vector(transformed_x,transformed_y,A,B);
    OperatingVectors derivatives  = (clamped_spline_matrix.inverse())*clamped_spline_vector ;
    OperatingMatrices coefficients = solver.clamped_spline_coefficients(derivatives,transformed_x,transformed_y);

    //Outputcode
    //Polynomial Coefficients to display are in inverted order
    vector<vector<double>> final;
    for (auto t: coefficients.get()) {
        vector<double> t_double = t.get();
        reverse(t_double.begin(), t_double.end());
        final.push_back(t_double);
    }

    Output o(final,
             x_y_coords,
             operation,
             operation + "_" + to_string(A) + "_" + to_string(B),
             output_type,
             false);
    o.python_display();
    o.displayClampedSpline(clamped_spline_matrix, clamped_spline_vector, coefficients, x_coords);
}

void Run::launchInterpolationNatural(vector<vector<double>> x_y_coords) {
    vector<double> x_coords = x_y_coords[0];
    vector<double> y_coords = x_y_coords[1];

    OperatingVectors transformed_x(x_coords);
    OperatingVectors transformed_y(y_coords);


    PolynomialApproximation solver ;
    OperatingMatrices natural_spline_matrix  = solver.natural_spline_data_matrix(transformed_x);
    OperatingVectors natural_spline_vector = solver.natural_spline_vector(transformed_x,transformed_y);
    OperatingVectors derivatives  = (natural_spline_matrix.inverse())*natural_spline_vector ;
    OperatingMatrices coefficients = solver.natural_spline_coefficients(derivatives,transformed_x,transformed_y);


    //Polynomial Coefficients to display are in inverted order
    vector<vector<double>> final;
    for (auto t: coefficients.get()) {
        vector<double> t_double = t.get();
        reverse(t_double.begin(), t_double.end());
        final.push_back(t_double);
    }

    Output o(final,
               x_y_coords,
               operation,
               operation,
               output_type,
               false);
    o.python_display();
    o.displayNaturalSpline(natural_spline_matrix, natural_spline_vector, coefficients, x_coords );
}

void Run::launchPolyInterpolation(vector<vector<double>> x_y_coords) {
    vector<double> x_coords = x_y_coords[0];
    vector<double> y_coords = x_y_coords[1];

    OperatingVectors transformed_x(x_coords);
    OperatingVectors transformed_y(y_coords);


    PolynomialApproximation solver;
    OperatingMatrices Vandermonde_matrix = solver.polynomial_interpolation_data_matrix(transformed_x);
    OperatingMatrices inverse_data_matrix = Vandermonde_matrix.inverse() ;
    OperatingVectors result = inverse_data_matrix*transformed_y ;




    //Polynomial Coefficients are in x^0, x^1, x^2 order
    //We need the, in x^2, x^1, x^0 order
    vector<double> inverted_coefficients = result.get();
    reverse(inverted_coefficients.begin(), inverted_coefficients.end());
    vector<vector<double>> final = {inverted_coefficients};
    Output o(final,
            x_y_coords,
            operation,
            operation,
            output_type,
            true);

    o.python_display();
    o.displayPolynomeInterpolation(Vandermonde_matrix,transformed_y,result);
}
