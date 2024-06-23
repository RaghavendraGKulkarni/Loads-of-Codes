// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : iterativeCheckPalindrome()
Description : Checks if a string is Palindrome iteratively
Arguments   : The string to be checked
Return      : "Yes" if the string is Palindrome and "No" otherwise
*/
string iterativeCheckPalindrome(string str) {
    
    // Initialize the local variables
    int i = 0, j = str.size() - 1;

    // Loop to reverse the string
    while(i < j) {
        if(str[i] != str[j])
            return "No";
        i++;
        j--;
    }

    // Return the reversed string
    return "Yes";
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
    string result = iterativeCheckPalindrome(str);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}