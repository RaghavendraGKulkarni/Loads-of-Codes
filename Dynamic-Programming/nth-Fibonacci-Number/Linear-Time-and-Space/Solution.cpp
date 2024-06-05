// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : nthFibonacciNumber()
Description : Computes the nth Fibonacci Number
Arguments   : A single non-negative integer denoting n
Return      : A single non-negative integer denoting the nth Fibonacci Number
*/
int nthFibonacciNumber(int n) {
    
    // Declare the required local variables
    int i, *dp = new int[n + 1], result;

    // Handle the base case
    dp[0] = 0;
    dp[1] = 1;

    // Find the nth fibonacci number using linear loop
    for(i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    // Copy the required result and delete the array used
    result = dp[n];
    delete[] dp;

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