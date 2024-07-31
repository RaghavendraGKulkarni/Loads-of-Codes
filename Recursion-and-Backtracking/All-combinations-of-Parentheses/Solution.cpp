// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : generate()
Description : Builds different combinations of parentheses and checks for termination condition
Arguments   : A vector of strings to store combinations, 
                a string denoting current combination, 
                the total number parentheses pairs and,
                two integers to track count opening and closing parentheses in the current combination, 
                in that order
Return      : None
*/
void generate(vector<string>& combinations, string combination, int n, int open, int close) {
    
    // Check the termination condition
    if(close == n) {
        combinations.push_back(combination);
        return;
    }

    // Check if a closing parentheses needs to be added
    if(open > close)
        generate(combinations, combination + ")", n, open, close + 1);

    // Check if a opening parentheses needs to be added
    if(open < n)
        generate(combinations, combination + "(", n, open + 1, close);

    // Return
    return;
}

/*
Name        : generateParentheses()
Description : Computes all possible sequences of balanced parentheses
Arguments   : The positive integer n, denoting the number of pairs of parentheses
Return      : A vector of strings denoting the combinations
*/
vector<string> generateParentheses(int n) {
    
    // Declare a vector to store the combinations
    vector<string> combinations;

    // Call the recursive subroutine to generate the combinations
    generate(combinations, "", n, 0, 0);

    // Return the combinations
    return combinations;
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

    // Declare the required local variables and read the input
    int n;
    input >> n;

    // Close the input file
    input.close();

    // Call the subroutine to generate all combinations of valid parentheses
    vector<string> result = generateParentheses(n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the result to the output file
    for(int i = 0; i < result.size(); i++)
        (i == 0) ? (output << result[i]) : (output << '\n' << result[i]);
    
    // Close the output file and return
    output.close();
    return 0;
}