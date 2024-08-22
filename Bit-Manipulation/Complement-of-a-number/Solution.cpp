// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : complement()
Description : Computes the complement of the given number
Arguments   : A single integer denoting the number to be complemented
Return      : A single integer denoting the complement
*/
int complement(int n) {
    
    //Declare and initialize the required local variables
    long long int comp = 0, pow = 1;
    int rem;

    // Extract the binary representation and construct the complement
    while(n) {
        rem = n % 2;
        comp = comp + (1 - rem)*pow;
        pow *= 2;
        n /= 2;
    }

    // Return the complement
    return ((int)comp);
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

    // Call the subroutine to compute the complement
    int result = complement(n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}