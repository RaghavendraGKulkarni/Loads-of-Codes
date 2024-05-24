// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : nthCatalanNumber()
Description : Computes the nth Catalan Number using Dynamic Programming
Arguments   : A single non-negative integer denoting n
Return      : A single non-negative integer denoting the nth Catalan Number
*/
int nthCatalanNumber(int n) {
    
    // Declare the required local variables
    int i, j, *dp = new int[n + 1], result;

    // Handle the base case
    dp[0] = 1;
    dp[1] = 1;

    // Find the nth catalan number using nested loop
    for(i = 2; i <= n; i++) {
        dp[i] = 0;
        for(j = 0; j < i; j++)
            dp[i] += (dp[j] * dp[(i - 1) - j]);
    }

    // Copy the required result and free the array used
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

    // Call the subroutine to compute the Catalan Number
    int result = nthCatalanNumber(n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}