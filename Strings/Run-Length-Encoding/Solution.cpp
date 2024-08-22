// Include the required header files
#include<iostream>
#include<fstream>
#include<unordered_map>
using namespace std;

/*
Name        : RLE()
Description : Computes the Run Length Encoding of a numerical string n
Arguments   : A string denoting the number n
Return      : A string denoting the Run Length Encoding of n
*/
string RLE(string str) {

    // Declare and initialize the required local variables
    int count = 1;
    char digit = str[0];
    string result = "";

    // Run through the string to compute the Encoding
    for(int i = 1; i < str.size(); i++) {
        if(str[i] == digit)
            count++;
        else {
            result += to_string(count);
            result.push_back(digit);
            digit = str[i];
            count = 1;
        }
    }
    result += to_string(count);
    result.push_back(digit);

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
    string number;
    input >> number;

    // Close the input file
    input.close();

    // Call the subroutine to compute the Run Length Encoding
    string result = RLE(number);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}