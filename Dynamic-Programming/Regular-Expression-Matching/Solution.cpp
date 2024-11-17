// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : regularMatching()
Description : Checks whether a text matches a regular expression or not
Arguments   : The text and the regular expression, in that order
Return      : True if it matches and False otherwise
*/
bool regularMatching(string s, string p) {
    
    // Declare the required local variables
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool> (n + 1, false));
    
    // Handle the base case
    dp[0][0] = true;
    for(int j = 2; j <= n; j++)
        if(p[j - 1] == '*')
            dp[0][j] = dp[0][j - 2];
    
    // Scan the text and pattern to check for match
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(p[j - 1] == '*')
                dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
            else
                dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        }
    }

    // Return the truth value
    return dp[m][n];
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
    string s, p;
    input >> s >> p;

    // Close the input file
    input.close();

    // Call the subroutine to check for Regular Expression Matching
    bool result = regularMatching(s, p);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    if(result)
        output << "Yes";
    else
        output << "No";
    
    // Close the output file and return
    output.close();
    return 0;
}