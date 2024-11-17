// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : isPalindrome()
Description : Checks if a substring is valid palindrome
Arguments   : The string to be checked and boundaries of the substring, in that order
Return      : True if it is palindrome, and False otherwise
*/
bool isPalindrome(string s, int left, int right) {

    // Iteratively check for palindrome
    while(left < right) {
        if(s[left] != s[right])
            return false;
        left++;
        right--;
    }

    // Return true
    return true;
}

/*
Name        : checkPalindrome()
Description : Checks if a string can be made a valid palindrome with atmost one deletion
Arguments   : The string to be checked
Return      : "Yes" if the string can be made, and "No" otherwise
*/
string checkPalindrome(string s) {

    // Declare the required local variables
    int left = 0, right = s.size() - 1;

    // Iteratively check for mismatch
    while(left < right) {

        // Continue if extreme characters are equal
        if(s[left] == s[right]) {
            left++;
            right--;
        }
        else {

            // Try deleting left extreme
            if(isPalindrome(s, left + 1, right))
                return "Yes";
            
            // Try deleting right extreme
            if(isPalindrome(s, left, right - 1))
                return "Yes";
            
            // Return false
            return "No";
        }
    }

    // Return True
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
    getline(input, str);

    // Close the input file
    input.close();

    // Call the subroutine to check if the string can be made palindrome with atmost one deletion
    string result = checkPalindrome(str);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}