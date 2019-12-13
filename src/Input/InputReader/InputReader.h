//
// Created by morin on 25.11.2019.
//

#ifndef PROJET_INPUTREADER_H
#define PROJET_INPUTREADER_H

#include <string>
#include "../Input.h"

//! This class allows you to read x and y coordinates from a file
/*!
 The input file must be of one of the two following types:

 csv file:

    "x1","y1"

    "x2","y2"

    x3,y3

    x4,y4

 txt file:

    x1 y1

    x2 y2
 */
class InputReader : public Input{
public:
    //! InputReader constructor
    /*!
      \param filename File path to load from disk
    */
    explicit InputReader(std::string filename);

    //! Main method use to read the coordinates x and coordinates y from an Input file
    virtual std::vector<std::vector<double>> generate() override;

private:
    //! Filename to be read from disk
    std::string filename;
};


#endif //PROJET_INPUTREADER_H
