//
// Created by KITANE YOUSSEF on 11.12.19.
//

#ifndef PROJET_RUNPARAMREADER_H
#define PROJET_RUNPARAMREADER_H

#include <string>
#include <vector>
using namespace std;

//! Helper Class to read input from the standard input stream, from the terminal.
/*!
 */

class RunParamReader {
public:
    //! Return whether the string s is a valid output type. i.e:
    //!  It can be either "terminal", "python" or "both"
    /*!
      \return true or false
    */

    static bool isValidOutputType(string s);
    //! Return whether the string s is a valid operation. i.e:
    //!  It can be either PolyInterpolation, DataFitting, DataFittingFind, InterpolationClamped, InterpolationNatural
    /*!
      \return true or false
    */
    static bool isValidOperation(string s);

    //! Helper function to read a string from the standard input stream
    //! The method asks a question to the user and retries till the user input one of the possible values
    /*!
      \param question Question to be asked to the user.
      \param possible_values List of possible values.
      \return String
    */
    string retrieveInput(string question, vector<string> possible_values);

    //! Helper function to read a string from the input
    //! The method asks a question to the user and collect the free text answer
    /*!
      \param question Question to be asked to the user.
      \return String
    */
    string retrieveFreeTextInput(string question);

    //! Helper function to read an Int from the standard input stream
    //! The method asks a question to the user and retries till the user inputs a valid Integer
    /*!
      \param question Question to be asked to the user.
      \return int
    */
    int retrieveInt(string question);

    //! Helper function to read a Double from the standard input stream
    //! The method asks a question to the user and retries till the user inputs a valid Double
    /*!
      \param question Question to be asked to the user.
      \return double
    */
    double retrieveDouble(string question);

    //! Helper function to read a list of Doubles from the standard input stream
    //! The method asks a question to the user and a collect a list of doubles, one by one, till the user quits by typing a letter.
        /*!
      \param question Question to be asked to the user.
      \return vector<double>
    */
    vector<double> retrieveDoubleVector(string question);
private:
    //! Checks if the string choice is not in the list of possible values
    /*!
      \param possible_values List of possible values.
      \param choice String.
      \return true or false
    */
    bool not_in(vector<string> possible_values, string choice);
};


#endif //PROJET_RUNPARAMREADER_H
