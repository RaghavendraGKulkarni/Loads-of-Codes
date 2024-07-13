// Include the required header files
#include<iostream>
#include<fstream>
#include<array>
#include<stack>
using namespace std;

/*
Name        : prefixToInfix()
Description : Converts the valid prefix expression to infix expression
Arguments   : The prefix expression string
Return      : The infix expression string
*/
string prefixToInfix(string prefix) {
    
    // Initialize the required local variables
    stack<string> st;

    // Loop the prefix expression backwards
    for(int i = prefix.size() - 1; i >= 0; i--) {

        // Select the operation based on the character
        char ch = prefix[i];
        string str = "";
        if(ch == '^' || ch == '/' || ch == '*' || ch == '+' || ch == '-') {
            str.push_back('(');
            str += st.top();
            st.pop();
            str.push_back(ch);
            str += st.top();
            st.pop();
            str.push_back(')');
            st.push(str);
        }
        else {
            str.push_back(ch);
            st.push(str);
        }
    }

    // Return the final infix expression
    return st.top();
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
    string prefix;
    input >> prefix;

    // Close the input file
    input.close();

    // Call the subroutine to convert the expression to infix
    string infix = prefixToInfix(prefix);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << infix;
    
    // Close the output file and return
    output.close();
    return 0;
}