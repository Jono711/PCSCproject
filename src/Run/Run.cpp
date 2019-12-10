//
// Created by morin on 09.12.2019.
//

#include "Run.h"
#include "../Output/Output.h"
#include "../Input/InputCreator/InputCreator.h"
#include "../Input/InputReader/InputReader.h"
#include "../Data_Fitting/LeastSquares.h"
#include <iostream>
#include <vector>

const double DBL_MAX = 5;
Run::Run(const string& param, const string& filename, const string& function_name, const bool& default_parameters,
                const vector<double>& x_coords, const bool& randomize, const string& operation,
                const int& degree, const string& output_type) {

    if(param == "reader"){
        input = new InputReader(filename);
    } else if(param == "creator"){
        if(!default_parameters){
            input = new InputCreator(function_name, x_coords, randomize);
        }else{
            input = new InputCreator(function_name);
        }
    } else {
        cout << "Impossible error!!! Using standard input creator." << endl ;
        input = new InputCreator("y=1");
    }
    if(operation!="Data_Fitting" && operation!="Data_Fitting_Find" && operation!="Interpolation"
                && operation!="Poly-Interpolation"){
        cout << "Please choose an operation between Data_Fitting, Data_Fitting_Find, Interpolation and "
                "Poly-Interpolation. Choosing default parameter: Data_Fitting." << endl;
        this->operation = "Data_Fitting";
    }else{
        this->operation = operation;
    }
    this->degree = degree;
    if(output_type!="terminal" && output_type!="python" && output_type!="both"){
        cout << "Please choose an output type between terminal, python and both. Choosing default parameter: terminal."
        << endl;
        this->output_type="terminal";
    } else {
        this->output_type=move(output_type);
    }

}


Run::Run() {
    // Choisir input + paramètre input
    string param("");
    do{
        cout << "Choose the type of input of your data (reader or creator): " << endl;
        cin >> param;
    }while(param!="reader" && param!="creator");

    if(param == "reader"){
        string filename;
        do{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Precise the filename for InputReader: " << endl;
            cin >> filename;
        }while(cin.fail());
        input = new InputReader(filename);
    } else if(param == "creator"){
        string function;
        do{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Precise the function for InputCreator: " << endl;
            cin >> function;
        }while(cin.fail());
        bool default_parameters = true;
        do{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Do you want default parameters? (true/false)" << endl;
            cin >> default_parameters;
        }while(cin.fail());
        if(!default_parameters){
            vector<double> x_coords;
            double x_coord;
            cout << "Precise your coordinates in x (enter any letter to stop): " << endl;
            do{
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> x_coord;
                if(!cin.fail())
                    x_coords.push_back(x_coord);
            }while(!cin.fail());
            bool randomize = false;
            do{
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Do you want to randomize your data? (true=1/false=0)" << endl;
                cin >> randomize;
            }while(cin.fail());
            input = new InputCreator(function, x_coords, randomize);
        }else{
            input = new InputCreator(function);
        }
    } else {
        cout << "Impossible error!!! Using standard input creator." << endl ;
        input = new InputCreator("y=1");
    }

    // Choisir opération + paramètre opération
    do{
        cout << "Choose the type of data analysis you want to do (Data_Fitting, Data_Fitting_Find, Interpolation,"
                " Poly-Interpolation): " << endl;
        cin >> operation;
    }while(operation!="Data_Fitting" && operation!="Data_Fitting_Find" && operation!="Interpolation"
            && operation!="Poly-Interpolation");
    if(operation == "Data_Fitting" || operation == "Interpolation"){
        do{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter the degree of the polynome to be computed: " << endl;
            cin >> degree;
        }while(cin.fail());
    }
    if(operation == "Data_Fitting_Find"){
        do{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter the maximum degree of the polynome to be considered: " << endl;
            cin >> degree;
        }while(cin.fail());
    }

    // Choisir output + paramètre output
    do{
        cout << "Choose the type of output you want (terminal, python, both): " << endl;
        cin >> output_type;
    }while(output_type!="terminal" && output_type!="python" && output_type!="both");
}

Run::~Run() {
    delete input;
}

void Run::launch() {
    if(operation=="Data_Fitting"){
        launchDataFitting();
    }else if(operation == "Data_Fitting_Find"){
        launchDataFittingFind();
    }else if(operation == "Interpolation"){
        launchInterpolation();
    }else if(operation == "Poly-Interpolation"){
        launchPolyInterpolation();
    }else{
        cout << "Strange, it seems you don't have specified a valid input..." << endl;
    }
}

void Run::launchDataFitting() {
    vector<vector<double>> x_y_coords = input->generate();
    LeastSquares solver(x_y_coords);
    vector<double> coefficients = solver.dataFitting(degree);
    Output output(coefficients, x_y_coords,operation+" with degree " + to_string(degree), output_type);
    output.display();
}

void Run::launchDataFittingFind() {
    // Variables to store the best lost and the best coefficients.
    double best_loss(DBL_MAX);
    unsigned int best_degree;
    vector<double> best_coefficients;

    vector<vector<double>> x_y_coords = input->generate();
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
    Output output(best_coefficients, x_y_coords,
            operation+" is the equation of degree " + to_string(best_degree) + " with loss " + to_string(best_loss),
            output_type);
    output.display();
}

void Run::launchInterpolation() {

}

void Run::launchPolyInterpolation() {

}
