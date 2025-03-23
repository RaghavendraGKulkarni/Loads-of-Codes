// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : iterativeHornersRule()
Description : Evaluates a polynomial on a given value using Horner's Rule iteratively
Arguments   : An integer denoting the degree of the polynomial, an array of polynomial coefficients and the value of x, in that order
Return      : An integer denoting the value of the polynomial
*/
int iterativeHornersRule(int n, int coefficients[], int x) {

    // Declare the required local variables
    int y = 0;

    // Compute the polynomial value
    for(int i = n-1; i >= 0; i--)
        y = (y * x) + coefficients[i];
    
    // Return the result
    return y;
}

/*
Name        : main()
Description : Handles I/O and calls the required subroutines
Arguments   : None
Return      : Integer 0
*/
int main() {

    // Open the input file and handle the exception
    ifstream input;
    input.open("Input.txt");
    if(input.fail()) {
        cerr << "Please provide the correct Input File...!!!" << endl;
        exit(0);
    }

    // Declare the required variables and read the input
    int n, x;
    input >> n >> x;
    int *coefficients = new int[n + 1];
    for(int i = 0; i <= n; i++)
        input >> coefficients[i];

    // Close the input file
    input.close();

    // Call the subroutine to evaluate the polynomial
    int result = iterativeHornersRule(n, coefficients, x);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Delete the array, close the output file and return
    delete[] coefficients;
    output.close();
    return 0;
}
