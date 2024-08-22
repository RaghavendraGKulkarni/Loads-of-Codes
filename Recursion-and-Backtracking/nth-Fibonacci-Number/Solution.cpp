// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : nthFibonacciNumber()
Description : Computes the nth Fibonaccu Number
Arguments   : A single non-negative integer denoting n
Return      : A single non-negative integer denoting the nth Fibonacci Number
*/
int nthFibonacciNumber(int n) {
    
    // Handle the base cases
    if(n <= 1)
        return n;
    
    // Express the recursive formula
    return nthFibonacciNumber(n - 1) + nthFibonacciNumber(n - 2);
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
    int n;
    input >> n;

    // Close the input file
    input.close();

    // Call the subroutine to compute the Fibonacci Number
    int result = nthFibonacciNumber(n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}