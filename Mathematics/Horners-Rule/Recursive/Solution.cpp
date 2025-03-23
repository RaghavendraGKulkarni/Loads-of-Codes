// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : recursiveHornersRule()
Description : Evaluates a polynomial on a given value using Horner's Rule recursively
Arguments   : An integer denoting the degree of the polynomial, an array of polynomial coefficients, the value of x and
            , the current index of evalauation, in that order
Return      : An integer denoting the value of the polynomial
*/
int recursiveHornersRule(int n, int coefficients[], int x, int index = 0) {
    
    // Handle the base case
    if(index == n + 1)
        return 0;
    
    // Recursive rule for the Horner's Rule
    int result = coefficients[index] + ( x * recursiveHornersRule(n, coefficients, x, index + 1));

    // Return the result
    return result;
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
    int result = recursiveHornersRule(n, coefficients, x);

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
