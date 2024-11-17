// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : longestBalancedSubstring()
Description : Computes the longest balanced substring
Arguments   : The string of parentheses
Return      : A vector containing the start index and length of the longest balanced substring
*/
vector<int> longestBalancedSubstring(string s) {
    
    // Initialize the required local variables
    int maxDiff = 0, n = s.size(), start = -1;
    vector<int> indices = {-1};

    // Scan the string and store mismatched indices
    for(int i = 0; i < n; i++) {
        if(s[i] == '(')
            indices.push_back(i);
        else {
            if(indices.back() != -1 && s[indices.back()] == '(')
                indices.pop_back();
            else
                indices.push_back(i);
        }
    }
    indices.push_back(n);

    // Find the maximum difference
    for(int i = 1; i < indices.size(); i++) {
        if(maxDiff < indices[i] - indices[i - 1] - 1) {
            maxDiff = indices[i] - indices[i - 1] - 1;
            start = indices[i - 1] + 1;
        }
    }

    // Return the result
    return {start, maxDiff};
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

    // Call the subroutine to find the longest balanced substring
    vector<int> result = longestBalancedSubstring(s);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    if(result[1] == 0)
        output << "None";
    else
        output << s.substr(result[0], result[1]);
    
    // Close the output file and return
    output.close();
    return 0;
}