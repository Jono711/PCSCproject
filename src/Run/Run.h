//
// Created by morin on 09.12.2019.
//

#ifndef PROJET_RUN_H
#define PROJET_RUN_H

#include "../Input/Input.h"
#include "../Output/Output.h"
#include <string>
using namespace std;

class Run {
public:
    Run();

    Run(const string &param, const string &filename, const string &function_name, const bool &default_parameters,
        const vector<double> &x_coords, const bool &randomize, const string &operation, const int &degree,
        const string& output_type);
    ~Run();
    void launch();

private:
    Input* input;
    string operation;
    int degree;
    string output_type;

    void launchDataFitting();
    void launchDataFittingFind();
    void launchInterpolation();
    void launchPolyInterpolation();


};


#endif //PROJET_RUN_H
