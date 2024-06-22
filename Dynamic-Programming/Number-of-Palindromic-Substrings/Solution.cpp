// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : palindromicSubstrings()
Description : Computes the number of palindromic substrings of length atleast two in the string
Arguments   : The string
Return      : An integer denoting the number of palindromic substrings
*/
int palindromicSubstrings(string s) {
    
    // Declare the required local variables
    int i, j, k, n = s.size(), count = 0;
    vector<vector<bool>> dp(n, vector<bool> (n, true));
    
    // For every length
    for(k = 1; k < n; k++) {
        
        i = 0;
        j = k;

        // For every substring
        while(i < n && j < n) {

            // If end letters are not equal, set false. Else check the inner substring
            dp[i][j] = (s[i] == s[j]) ? dp[i + 1][j - 1] : false;
            
            // Increment count, if substring is a palindrome
            if(dp[i][j])
                count++;

            i++;
            j++;
        }
    }

    // Return the count
    return count;
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

    // Call the subroutine to compute the number of palindromic substrings
    int result = palindromicSubstrings(s);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Delete the array, close the output file and return
    output.close();
    return 0;
}