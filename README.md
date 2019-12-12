# Project 6: Data Approximation

This data approximation project aims to implement a fully functionnal program for polynomial interpolation, piece-wise polynomial interpolation and least-square data fitting.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

There are no real prerequisite to the installation of this program, except of course having a C++ compiler. If you use a program such as CLion, you can open a project in your installation folder.

A Python compiler is strongly recommended as this program can generate a python file as an output. It is however not required to make the program work.

### Installing

/!\ TO DO

A step by step series of examples that tell you how to get a development env running

Say what the step will be

```
Give the example
```

And repeat

```
until finished
```

## Program flow

The program starts with the 'Input' super class. Here the choice is given between two 'Input' subclasses: 'InputReader' and 'InputCreator' in order to generate our (x,y) couples of data points. The former reads data from a given file and the latter generate the (x,y(x)) points of a given y(x) function and from a given data set of x. You can even add a random displacement to those y(x) points.

Once the (x,y) data points are generated, you can choose one from a variety of action to be done:

	1) Do some data fitting of the data points, given a certain degree of polynome to be found;

	2) Find the best polynome to approximate our data, up to a certain degree of polynome;

	3) Find the piece-wise interpolation of degree three with given derivative at the first point and at the end point;

	4) Find the piece-wise interpolation of degree three with the same derivative at the first point and at the end point;  

	5) Find the polynomial interpolation of the data.

Finally 'Output' class allows for to display the results in three different fashions. A terminal message that will display the original data as well as the found function, a python file that will display both the (x,y) data points with the computed function, or both.

## Usage of the program

The program is pretty simple to use: a 'Run' class contains everything the user should have to use.

A first call the 'Run' default constructor will ask the user the different parameters to be used. Let's go through them all in order:

&nbsp;1) Choose the type of input between "reader" and "creator";  
&nbsp;|-> 2) (1-Optionnal) If "reader" is chosen in (1), precise the file name;  
&nbsp;--> 3) (1-Optionnal) If "creator" is chosen in (1), precise the function name\*;  
&nbsp;&nbsp;--> 4) (1-Optionnal) If "creator" is chosen in (1), precise if you want to use the default parameters for the function\*\*;  
&nbsp;&nbsp;&nbsp;--> 5) (4-Optionnal) If "false" is chosen in (4), precise your coordinate in x (enter any non-double to stop);  
&nbsp;&nbsp;&nbsp;&nbsp;--> 6) (4-Optionnal) If "false" is chosen in (4), precise if you want to add a randomness to the y data;  
&nbsp;7) Precise the type of data analysis you want to do between "DataFitting", "DataFittingFind", "InterpolationClamped", "InterpolationNatural" and "PolyInterpolation";  
&nbsp;|-> 8) (7-Optionnal) If "DataFitting" is chosen in (7), precise the degree of the polynome to be computed;  
&nbsp;|-> 9) (7-Optionnal) If "DataFittingFind" is chosen in (7), precise the maximum degree of polynome to be considered;  
&nbsp;--> 10 & 11) (7-Optionnal) If "InterpolationClamped" is chosen in (7), precise the value of the first derivative at the first point and at the last point;  
&nbsp;12) Finally choose the type of output between "terminal", "python" or "both".  

Then simply call the function 'launch' of your new run object, and voilà! If you chose the "terminal" output type, the program should output you the chosen x and y data. If you chose the 'python' output type, a 'Successfully created the python file.' should appear. The new file will be located in the main folder unless precised otherwise.

/!\ Other Run constructors?

```
Example:
Choose the type of input of your data: [reader,creator,]
creator
Precise the function for InputCreator:
y=x
Do you want default parameters? [true,false,]
true
Choose the type of data analysis you want to do: [DataFitting,DataFittingFind,InterpolationClamped,InterpolationNatural,
PolyInterpolation,]
DataFitting
Enter the degree of the polynome to be computed (Number expected)
2
Choose the type of output you want: [terminal,python,both,]
both
The solution to DataFitting
with x and y data such as :
x: (0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1)
y: (0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1)

is the equation: y=0.000000x^(2)+1.000000x+0.000000

Successfully created the python file.

Process finished with exit code 0
```


(\*) The syntax for the function name is the following: start with "y=" and add any number of modules following it. The modules are of the following form:

* a)'power': Ax^(B) or Ax, with A and B double;
* b)'cosinus': Acos(Bx+C) or Acos(Bx), with A, B and C double;
* c)'sinus': Asin(Bx+C) or Asin(Bx), with A, B and C double;
* b)'exponential': Aexp(Bx+C) or Aexp(Bx), with A, B and C double;
* e)'constant': A, with A double, be careful! If added, this module must be the last one;

Example: "y=2x^(2)+3x-3.5cos(9x)+sin(4.5x-2)+exp(x)+2.34".
Another example: "y=-x^(-1/2)-3cos(x-2)+2.33exp(6.3x-6)";
Be careful not to add any space inside the equation.

(\*\*) The default parameters are x = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0} and no random displacement;

## List of features

First, it seems important to precise that the code structure is easily available via [Doxygen](http://www.doxygen.nl/), it uses [Google_test](https://github.com/google/googletest) and is implemented with a wide range of error handling. Then let's see the special features implemented through each class.

* Input: A parent class that souldn't be used directly. It is not purely virtual since it is an attributes in the "Run" class, which allows to elegantly switch it one of its daughter class during construction. Contains the "generate()" method that returns the x and y coordinates.

* InputCreator: One of the two daughter class of "Input". The "generate()" method allows to translate a function given as a string (following a certain syntax) to double values for y(x).

* InputReader: The other daughter class of "Input". The "generate()" method allows to read the (x,y) data given as two columns from easily readable files such as .txt and .dat. The ability to also read more complex .csv files has also been implemented.

* PolynomialApproximation: This class contains the methods used to do both the polynomial interpolation as well as the piece-wise polynomial interpolation.

* LeastSquares: This class contains the method used to do the least-square approximation, as well as a method to calculate the least-square loss of an approximation.

* Output: The class used to mainly present the results to the user. Includes methods to display information in the terminal, in a python file as well as methods that allows to translate the computed polynomes into string and/or their python equivalent.

* Run: The class that holds the whole project together, so that the user has the least code to write. Includes a big selection of private "launch" methods that use the right method from the right classes at the right time to produce the desired user output. It can be noted that both a method that finds the polynomial for data approximation and two different methods specifying different boundary conditions for the piece-wise interpolation were implemented.

* OperatingVectors and OperatingMatrices: These two classes allows for easy matrix and vector operation, including addition and multiplication with double, vector and matrices. It also includes several construction of operating matrices and vectors as well as the computation of the determinant, the transpose, the adjoint and the inverse of a matrix.

## List of tests

/!\ TO DO


## Issues

* The will to let the user have the least code possible to write to use this program makes the implementation of the "Run" and the "Output" classes very complicated. If another developer wants to add new features to this program, he will not only have to write his new data approximation script but he will also probably need to add his unique implementation to the "Run" and "Output" classes, which will make them heavier and heavier incrementally as new implementations are added. A way to solve this problem would be to increase the level of abstraction these class use and fragmentize the code even more.

* Sometimes the program tends to be very slow when manipulating big matrices (if you try a DataFittingFind of degree >= 6 for a pretty complex data set for example). Since the matrices are mostly used to solve linear algebra, an implementation of LU factorisation and its variants would be a good idea.

## Perspectives

* Other than those explained above, the perspective of upgrade for this program are humongous. New data approximation techniques, new inputs methods, new output methods and so forth. With the current setup of the program, the implementation of new input methods would probably be the most easy to achieve since, as said before, implementing new approximation techniques and outputs would prove a bit more difficult in the Run part (although is it totally faisible).

## Authors

* **Youssef Kitane**
* **Jonas Morin**.

## Acknowledgments

* Scientific Computing with MATLAB and Octave, Alfio Quarteroni and Fausto Saleri, "https://link.springer.com/book/10.1007%2F3-540-32613-8"

* Programming concepts in scientific computing course, Anciaux Guillaume, "https://edu.epfl.ch/coursebook/fr/programming-concepts-in-scientific-computing-MATH-458"

* Machine learning course, Jaggi Martin and Urbanke Rüdiger, "https://edu.epfl.ch/coursebook/en/machine-learning-CS-433"