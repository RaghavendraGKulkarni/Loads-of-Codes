// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : nthCatalanNumber()
Description : Computes the nth Catalan Number
Arguments   : A single non-negative integer denoting n
Return      : A single non-negative integer denoting the nth Catalan Number
*/
int nthCatalanNumber(int n) {
    
    // Handle the base case
    if(n == 0)
        return 1;
    
    // Express the recursive formula
    int result = 0;
    for(int i = 0; i < n; i++)
        result += (nthCatalanNumber(i) * nthCatalanNumber(n - 1 - i));

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