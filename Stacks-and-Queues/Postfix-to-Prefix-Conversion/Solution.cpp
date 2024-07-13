// Include the required header files
#include<iostream>
#include<fstream>
#include<array>
#include<stack>
using namespace std;

/*
Name        : postfixToPrefix()
Description : Converts the valid postfix expression to prefix expression
Arguments   : The postfix expression string
Return      : The prefix expression string
*/
string postfixToPrefix(string postfix) {
    
    // Initialize the required local variables
    stack<string> st;

    // Loop through the postfix expression
    for(auto &ch : postfix) {

        // Select the operation based on the character
        string str = "";
        if(ch == '^' || ch == '/' || ch == '*' || ch == '+' || ch == '-') {
            str.push_back(ch);
            string op1 = st.top();
            st.pop();
            str += st.top() + op1;
            st.pop();
            st.push(str);
        }
        else {
            str.push_back(ch);
            st.push(str);
        }
    }

    // Return the final prefix expression
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

    // Call the subroutine to convert the expression to prefix
    string prefix = postfixToPrefix(postfix);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << prefix;
    
    // Close the output file and return
    output.close();
    return 0;
}