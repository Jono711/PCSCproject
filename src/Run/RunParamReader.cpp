//
// Created by KITANE YOUSSEF on 11.12.19.
//

#include "RunParamReader.h"
#include <iostream>
#include <vector>

bool RunParamReader::isValidOutputType(string s) {
    if (s == "terminal" || s == "python" || s == "both") {
        return true;
    }
    return false;
}

bool RunParamReader::isValidOperation(string s) {
    if(s == "DataFitting" || s == "DataFittingFind"
       || s == "InterpolationClamped" || s == "InterpolationNatural" || s == "PolyInterpolation" ) {
        return true;
    }
    return false;
}

bool RunParamReader::not_in(vector<string> possible_values, string choice) {
    bool found = false;
    for(int i=0; i<possible_values.size(); i++){
        if (possible_values[i] == choice) {
            found = true;
            break;
        }
    }
    return !found;
}
string RunParamReader::retrieveInput(string question, vector<string> possible_values) {
    string param("");
    do{
        cin.clear();
        cout << question << " [";
        for (auto value: possible_values) {
            cout << value << ",";
        }
        cout << "]" << endl;
        cin >> param;
    } while( not_in(possible_values, param) );
    return param;
}

string RunParamReader::retrieveFreeTextInput(string question) {
    string param("");
    do{
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << question << endl;
        cin >> param;
    } while( cin.fail() );

    return param;
}

int RunParamReader::retrieveInt(string question) {
    int res;
    do{
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << question << " (Number expected)" << endl;
        cin >> res;
    } while(cin.fail());

    return res;
}
double RunParamReader::retrieveDouble(string question) {
    double res;
    do{
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << question << " (Number expected)" << endl;
        cin >> res;
    } while(cin.fail());

    return res;
}


vector<double> RunParamReader::retrieveDoubleVector(string question) {
    vector<double> res;
    double input_read;
    cout << question << " (enter any letter to stop)" << endl;
    do {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input_read;

        if(!cin.fail())
            res.push_back(input_read);
    }  while(!cin.fail());
    return res;
}






