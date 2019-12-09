//
// Created by morin on 25.11.2019.
//

#ifndef PROJET_INPUTCREATOR_H
#define PROJET_INPUTCREATOR_H

#include "../Input.h"
#include <string>
#include <vector>
using namespace std;

class InputCreator : public Input {
public:
    explicit InputCreator(std::string function_name, const std::vector<double>& x_coords = {}, bool generate_random_displacement = false);
    std::vector<std::vector<double>> generate() override;
private:
    std::string function_name;
    bool generate_random_displacement;
    std::vector<double> x_coords;
    struct module;
};


#endif //PROJET_INPUTCREATOR_H
