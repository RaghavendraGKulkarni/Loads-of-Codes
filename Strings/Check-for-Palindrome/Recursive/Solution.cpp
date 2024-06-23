// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : recursiveCheckPalindrome()
Description : Checks if a string is Palindrome recursively
Arguments   : The string to be checked
Return      : "Yes" if the string is Palindrome and "No" otherwise
*/
string recursiveCheckPalindrome(string str, int low, int high) {
    
    // Handle the base case
    if(low >= high)
        return "Yes";
    
    // Check if end characters are equal
    if(str[low] != str[high])
        return "No";

    // Check if inner substring is Palindrome or not
    return recursiveCheckPalindrome(str, low + 1, high - 1);
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

    // Call the subroutine to check if the string is a Palindrome
    string result = recursiveCheckPalindrome(str, 0, str.size() - 1);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}