// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : longestPalindromicSubstring()
Description : Computes the longest palindromic substring of length atleast two in the string, if it exists
Arguments   : The string
Return      : A string denoting the longest palindromic substring, if it exists and null string otherwise
*/
string longestPalindromicSubstring(string s) {
    
    // Declare the required local variables
    int i, j, k, n = s.size(), maxLength = 0, start;
    string result = "";
    vector<vector<bool>> dp(n, vector<bool> (n, true));
    
    // For every length
    for(k = 1; k < n; k++) {
        
        i = 0;
        j = k;

        // For every substring
        while(i < n && j < n) {

            // If end letters are not equal, set false. Else check the inner substring
            dp[i][j] = (s[i] == s[j]) ? dp[i + 1][j - 1] : false;
            
            // Compare length, if substring is a palindrome
            if(dp[i][j] && maxLength < j - i + 1) {
                maxLength = j - i + 1;
                start = i;
            }

            i++;
            j++;
        }
    }

    // Return the result
    result = s.substr(start, maxLength);
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
    string s;
    input >> s;

    // Close the input file
    input.close();

    // Call the subroutine to compute the longest palindromic substring
    string result = longestPalindromicSubstring(s);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    (result.size() > 0) ? output << result : output << "None";
    
    // Delete the array, close the output file and return
    output.close();
    return 0;
}