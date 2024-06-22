// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : trailingZeros()
Description : Computes the number of consecutive zeros at the end of n!
Arguments   : A single positive integer denoting n
Return      : A single integer denoting the number of consecutive zeros at the end of n!
*/
int trailingZeros(int n) {
    
    // Declare the required local variables
    int z2 = 0, z5 = 0, x;

    // Number of 2 factors in n!
    x = 2;
    while(x <= n) {
        z2 += (n/x);
        x *= 2;
    }

    // Number of 5 factors in n!
    x = 5;
    while(x <= n) {
        z5 += (n/x);
        x *= 5;
    }

    // Return the number of 10 factors in n!
    return min(z2, z5);
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

    // Call the subroutine to compute the number of consecutive zeros at the end of n!
    int result = trailingZeros(n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}