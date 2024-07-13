// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : powerOf2()
Description : Checks whether a given number is a power of two or not
Arguments   : A single integer denoting the number to be checked
Return      : "Yes" if the number is a power of two and, "No" otherwise
*/
string powerOf2(int n) {
    
    // Check if the number of power of two
    if((n & (n - 1)) == 0)
        return "Yes";
    return "No";
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

    // Call the subroutine to check if power of 2
    string result = powerOf2(n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}