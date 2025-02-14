// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : recursiveHornersRule()
Description : Evaluates a polynomial on a given value using Horner's Rule recursively
Arguments   : The vector of polynomial coefficients and the value of x, in that order
Return      : An integer denoting the value of the polynomial
*/
int recursiveHornersRule(vector<int> coefficients, int x, int index = 0) {
    
    // Handle the base case
    if(index == coefficients.size())
        return 0;
    
    // Recursive rule for the Horner's Rule
    int result = coefficients[index] + ( x * recursiveHornersRule(coefficients, x, index + 1));

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
    vector<int> coefficients(n + 1);
    for(int i = 0; i <= n; i++)
        input >> coefficients[i];

    // Close the input file
    input.close();

    // Call the subroutine to evaluate the polynomial
    int result = recursiveHornersRule(coefficients, x);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}
