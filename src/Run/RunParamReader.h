//
// Created by KITANE YOUSSEF on 11.12.19.
//

#ifndef PROJET_RUNPARAMREADER_H
#define PROJET_RUNPARAMREADER_H

#include <string>
#include <vector>
using namespace std;

class RunParamReader {
public:
    static bool isValidOutputType(string s);
    static bool isValidOperation(string s);

    string retrieveInput(string question, vector<string> possible_values);
    string retrieveFreeTextInput(string question);
    int retrieveInt(string question);
    double retrieveDouble(string question);
    vector<double> retrieveDoubleVector(string question);

private:
    bool not_in(vector<string> possible_values, string choice);
};


#endif //PROJET_RUNPARAMREADER_H
