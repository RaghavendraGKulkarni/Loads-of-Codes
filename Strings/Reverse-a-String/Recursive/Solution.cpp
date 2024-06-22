// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : recursiveReverse()
Description : Reverses a string iteratively
Arguments   : The string to be reversed
Return      : The reversed string
*/
string recursiveReverse(string str, int low, int high) {
    
    // Handle the base condition
    if(low >= high)
        return str;
    
    // Swap the end characters
    swap(str[low], str[high]);

    // Recursively reverse the inner substring
    str = recursiveReverse(str, low + 1, high - 1);

    // Return the reversed string
    return str;
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
    string str;
    input >> str;

    // Close the input file
    input.close();

    // Call the subroutine to find the reverse the string
    string rev_str = recursiveReverse(str, 0, str.size() - 1);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << rev_str;
    
    // Close the output file and return
    output.close();
    return 0;
}