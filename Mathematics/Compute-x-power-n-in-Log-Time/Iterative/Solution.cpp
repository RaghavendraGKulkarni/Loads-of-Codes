// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : power()
Description : Computes the value of x power n in Log time iteratively
Arguments   : An integer denoting x and a non-negative integer denoting n
Return      : A single integer denoting the value of x power n
*/
long long int power(int x, int n) {
    
    // Handle the base case
    if(n == 0)
        return 1;
    if(x == 0)
        return 0;
    
    // Handle the negative base case
    bool neg;
    if(x < 0) {
        x *= -1;
        if(n % 2 == 1)
            neg = true;
    }

    // Initialize the required local variables
    long long int result = 1, power = (long long int)x;

    // Compute x power n
    while(n) {
        
        // If exponent is odd
        if(n % 2 == 1)
            result *= power;
        
        // Divide exponent by 2
        n /= 2;
        power *= power;
    }

    // Restore the negative base case
    if(neg)
        result *= -1;
    
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
    int x, n;
    input >> x >> n;

    // Close the input file
    input.close();

    // Call the subroutine to compute x power n
    long long int result = power(x, n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}