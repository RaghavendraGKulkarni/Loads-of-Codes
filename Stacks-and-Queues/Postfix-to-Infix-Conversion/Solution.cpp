// Include the required header files
#include<iostream>
#include<fstream>
#include<array>
#include<stack>
using namespace std;

/*
Name        : postfixToInfix()
Description : Converts the valid postfix expression to infix expression
Arguments   : The postfix expression string
Return      : The infix expression string
*/
string postfixToInfix(string postfix) {
    
    // Initialize the required local variables
    stack<string> st;

    // Loop through the postfix expression
    for(auto &ch : postfix) {

        // Select the operation based on the character
        string str = "";
        if(ch == '^' || ch == '/' || ch == '*' || ch == '+' || ch == '-') {
            str.push_back('(');
            string op1 = st.top();
            st.pop();
            str += st.top();
            st.pop();
            str.push_back(ch);
            str += op1;
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
    string postfix;
    input >> postfix;

    // Close the input file
    input.close();

    // Call the subroutine to convert the expression to infix
    string infix = postfixToInfix(postfix);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << infix;
    
    // Close the output file and return
    output.close();
    return 0;
}