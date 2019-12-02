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
    explicit InputCreator(std::string function_name, bool generate_random_displacement = false, const std::vector<double>& x_coords = {});
    virtual std::vector<std::vector<double>> generate() override;
private:
    std::string function_name;
    bool generate_random_displacement;
    std::vector<double> x_coords;
};


#endif //PROJET_INPUTCREATOR_H
