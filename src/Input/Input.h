//
// Created by morin on 25.11.2019.
//

#ifndef PROJET_INPUT_H
#define PROJET_INPUT_H

#include <vector>

//! Abstract class that is the basis for all Input classes.
class Input {
    /**
     * Abstract class that is the basis for all Input classes.
     */

public:
    virtual std::vector<std::vector<double>> generate();


};


#endif //PROJET_INPUT_H
