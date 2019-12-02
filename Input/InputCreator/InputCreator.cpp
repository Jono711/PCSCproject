//
// Created by morin on 25.11.2019.
//

#include "InputCreator.h"
#include <utility>
#include <vector>
#include <cmath>
#include <iostream>
#include <random>
#include <chrono>

using namespace std;

InputCreator::InputCreator(string function_name, bool generate_random_displacement, const vector<double>& x_coords){
    this->function_name = std::move(function_name);
    this->generate_random_displacement = generate_random_displacement;
    if (x_coords.empty())
    {

        this->x_coords = vector<double> ({0.,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0});
    } else {
        this->x_coords = x_coords;
    }
}

struct module{
    vector<double> coefficients;
    string type;
};

vector<vector<double>> InputCreator::generate() {
    vector<double> y_coords;
    /*
    * Format of function name: "y=" module A + module B
    * Module = Ax^(B) | Acos(Bx+C) | Asin(Bx+C) | Atan(Bx+C) | Aexp(Bx)
    * /!\ if a constant is to be added, add it at the end /!\
    */
    vector<module> modules;
    // Create coefficients from the string
    int save(2);
    int i(2);
    while(i < function_name.size()){

        if (function_name.substr(i, 1) == "x"){
            module new_module;
            new_module.type = "power";
            if (function_name.substr(save, i-save).empty() or function_name.substr(save, i-save)=="+"){
                new_module.coefficients.push_back(1.);
            }else if (function_name.substr(save, i-save)=="-"){
                new_module.coefficients.push_back(-1.);
            }else{
                new_module.coefficients.push_back(stod(function_name.substr(save, i-save)));
            }
            if (function_name.substr(i, 3) == "x^(")
            {
                i = i+3;
                save = i;
                while(function_name.substr(i, 1) != ")") { i=i+1; }
                new_module.coefficients.push_back(stod(function_name.substr(save, i-save)));
            }else {
                new_module.coefficients.push_back(1.);
            }
            modules.push_back(new_module);
            save = i+1;
        }

        if (function_name.substr(i, 4) == "cos(" or function_name.substr(i, 4) == "sin(" or function_name.substr(i, 4) == "exp("){
            module new_module;
            if (function_name.substr(i, 4) == "cos("){
                new_module.type = "cosinus";
            }else if (function_name.substr(i, 4) == "sin("){
                new_module.type = "sinus";
            }else if (function_name.substr(i, 4) == "exp("){
                new_module.type = "exponential";
            }else{
                new_module.type = "Impossible error";
            }

            if (function_name.substr(save, i-save).empty() or function_name.substr(save, i-save)=="+"){
                new_module.coefficients.push_back(1.);
            }else if (function_name.substr(save, i-save)=="-"){
                new_module.coefficients.push_back(-1.);
            }else{
                new_module.coefficients.push_back(stod(function_name.substr(save, i-save)));
            }
            i = i + 4;
            save = i;
            while(function_name.substr(i, 1) != "x") { i = i + 1; }
            new_module.coefficients.push_back(stod(function_name.substr(save, i-save)));

            save = i + 1;
            while(function_name.substr(i, 1) != ")") { i = i + 1; }
            if (i!=save){
                new_module.coefficients.push_back(stod(function_name.substr(save, i-save)));
            } else {
                new_module.coefficients.push_back(0.);
            }

            modules.push_back(new_module);
            i = i + 1;
            save = i + 1;
        }

        i = i + 1;
    }
    if (save != i)
    {
        module new_module;
        new_module.type = "constant";
        new_module.coefficients.push_back(stod(function_name.substr(save, i-save)));
        modules.push_back(new_module);
    }

    for (auto x : x_coords){
        double y = 0.;
        for (auto mod : modules){
            if (mod.type == "constant"){
                y += mod.coefficients[0];
            }
            if (mod.type == "power"){
                if (x == 0. and mod.coefficients[1] < 0.) {
                    cerr << "Cannot compute any form of 1/x[i] with x[i]=0. Resuming the program ignoring this input.";
                }else if(x < 0. and mod.coefficients[1]-int(mod.coefficients[1]) > 1e-14){
                    cerr << "Cannot compute a negative square root. Resuming the program ignoring this input.";
                }else{
                    y += mod.coefficients[0] * pow(x, mod.coefficients[1]);
                }
            }
            if (mod.type == "exponential"){
                y += mod.coefficients[0] * exp(mod.coefficients[1] * x + mod.coefficients[2]);
            }
            if (mod.type == "cosinus"){
                y += mod.coefficients[0] * cos(mod.coefficients[1] * x + mod.coefficients[2]);
            }
            if (mod.type == "sinus"){
                y += mod.coefficients[0] * sin(mod.coefficients[1] * x + mod.coefficients[2]);
            }
        }
        if(generate_random_displacement){
            unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
            default_random_engine generator(seed1);
            uniform_real_distribution<double> distribution(-0.2*y,0.2*y);
            y += distribution(generator);
        }
        y_coords.push_back(y);
    }
    return vector<vector<double>>({x_coords, y_coords});
}
