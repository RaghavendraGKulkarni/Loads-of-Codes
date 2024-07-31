// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : longestSubstring()
Description : Computes the longest substring without any repeating characters
Arguments   : The string s
Return      : The longest substring without any repeating characters
*/
string longestSubstring(string str) {
    
    // Handle the base case of null string
    if(str.size() == 0)
        return "";
    
    // Initialize the required local variables
    int count[256] = {0}, i = 0, j = 0, left, right, length, maxLength = 1;;

    // Initialize the window with the first character
    count[(int)str[0]] = 1;

    // Loop through the string to slide the window
    while(j + 1 < str.size()) {

        // Add the new character to the window on right
        count[(int)str[++j]]++;

        // Remove the characters from the window on left until all distinct
        while(i < j && count[(int)str[j]] > 1) {
            count[(int)str[i]]--;
            i++;
        }

        // Calculate the length and update the maximum
        length = j - i + 1;
        if(maxLength < length) {
            maxLength = length;
            left = i;
            right = j;
        }
    }

    // Return the longest substring
    return str.substr(left, maxLength);
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

    // Call the subroutine to find the longest substring
    string result = longestSubstring(str);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}