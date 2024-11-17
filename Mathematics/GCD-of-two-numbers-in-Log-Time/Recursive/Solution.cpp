// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : recursiveGCD()
Description : Computes the GCD of two numbers using Euler's method recursively
Arguments   : The two positive integers, in any order
Return      : A single integer denoting the GCD
*/
int recursiveGCD(int m, int n) {
    
    // Swap the variables if they are not in correct order
    if(m < n)
        swap(m, n);

    // Handle the base case
    if(n == 0)
        return m;
    
    // Return the gcd
    return recursiveGCD(n, m % n);
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
    int m, n;
    input >> m >> n;

    // Close the input file
    input.close();

    // Call the subroutine to compute the gcd
    int result = recursiveGCD(m, n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}