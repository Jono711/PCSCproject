//
// Created by morin on 25.11.2019.
//

#ifndef PROJET_INPUTCREATOR_H
#define PROJET_INPUTCREATOR_H

#include "../Input.h"
#include <string>
#include <vector>
using namespace std;

//! This class allows you to generate y coordinates using a specified function and x coordinates
/*!
   Format of function name: "y=" + "module1" + "module2"
   A Module can be one of the following formats:

   Ax^(B) | Acos(Bx+C) | Asin(Bx+C) | Aexp(Bx)

   /!\ if a constant is to be added, add it at the end /!\

   Example of valid format:

   y= 2.5x^(2.5)+cos(x+3.14)-2.5sin(x-3.14)-0.5exp(-3x+6)+1
 */

class InputCreator : public Input {
public:
    //! InputCreator constructor
    /*!
      \param function_name Function used to generate y coordinates
      \param x_coords X coordinates
      \param generate_random_displacement Boolean to indicate whether to generate random fluctuation on the y coordinates
    */
    explicit InputCreator(std::string function_name, const std::vector<double>& x_coords = {}, bool generate_random_displacement = false);

    //! Main method use to generate the coordinates y from a specified function.
    std::vector<std::vector<double>> generate() override;
private:
    //! Function used to generate y coordinates. Please see above for the specific function format.
    std::string function_name;
    //! Boolean to indicate whether to generate random fluctuation on the y coordinates.
    bool generate_random_displacement;
    //! Input x coordinates used to generate y coordinates
    std::vector<double> x_coords;

    struct module;
};


#endif //PROJET_INPUTCREATOR_H
