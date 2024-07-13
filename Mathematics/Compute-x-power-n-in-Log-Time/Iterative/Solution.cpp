// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : power()
Description : Computes the value of x power n in Log time iteratively
Arguments   : A double denoting x and an integer denoting n, in that order
Return      : A double denoting the value of x power n
*/
double power(double x, int n) {
    
    // Handle the base case
    if(n == 0)
        return 1.0;
    if(x == 0)
        return 0.0;
    
    // Handle the negative power and base case
    bool neg = false, rec = false;
    long long int p = (long long int)n;
    if(p < 0) {
        p *= -1;
        rec = true;
    }
    if(x < 0) {
        x *= -1;
        if(p % 2 == 1)
            neg = true;
    }

    // Initialize the required local variables
    double result = 1, power = x;

    // Compute x power n
    while(p) {
        
        // If exponent is odd
        if(p % 2 == 1)
            result *= power;
        
        // Divide exponent by 2
        p /= 2;
        power *= power;
    }

    // Restore the negative power and base case
    if(neg)
        result *= -1;
    if(rec)
        result = 1/result;
    
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
    double x;
    int n;
    input >> x >> n;

    // Close the input file
    input.close();

    // Call the subroutine to compute x power n
    double result = power(x, n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}