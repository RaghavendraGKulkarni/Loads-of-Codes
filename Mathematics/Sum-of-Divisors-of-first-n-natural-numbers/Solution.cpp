// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : sumOfDivisors()
Description : Computes the sum of divisors of first n natural numbers
Arguments   : A single positive integer denoting n
Return      : A single integer denoting the sum of divisors of first n natural numbers
*/
int sumOfDivisors(int n) {
    
    // Declare the required local variables
    int result = 0;

    // Find the sum of divisors of first n natural numbers
    for(int i = 1; i <= n; i++)
        result += (i * (n/i));

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
    int n;
    input >> n;

    // Close the input file
    input.close();

    // Call the subroutine to compute the Catalan Number
    int result = sumOfDivisors(n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}