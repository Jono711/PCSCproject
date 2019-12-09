//
// Created by morin on 25.11.2019.
//

#ifndef PROJET_INPUTREADER_H
#define PROJET_INPUTREADER_H

#include <string>
#include "../Input.h"

class InputReader : public Input{
public:
    explicit InputReader(std::string filename);
    virtual std::vector<std::vector<double>> generate() override;

private:
    std::string filename;
};


#endif //PROJET_INPUTREADER_H
