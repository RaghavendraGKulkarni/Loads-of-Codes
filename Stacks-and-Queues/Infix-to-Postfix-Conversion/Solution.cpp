// Include the required header files
#include<iostream>
#include<fstream>
#include<array>
#include<stack>
using namespace std;

/*
Name        : priority()
Description : Returns the priority of an operator
Arguments   : A character denoting the operator
Return      : An integer denoting the priority
*/
int priority(char op) {
    if(op == '^')
        return 2;
    if(op == '*' || op == '\\')
        return 1;
    return 0;
}

/*
Name        : infixToPostfix()
Description : Converts the valid infix expression to postfix expression
Arguments   : The infix expression string
Return      : The postfix expression string
*/
string infixToPostfix(string infix) {
    
    // Initialize the required local variables
    string postfix = "";
    stack<char> st;
    int p;

    // Loop through the infix expression
    for(auto &ch : infix) {

        // Select the operation based on the character
        switch(ch) {
            case '(':st.push(ch);
                        break;
            case ')':while(st.top() != '(') {
                        postfix.push_back(st.top());
                        st.pop();
                    }
                    st.pop();    
                    break;
            case '+':p = priority(ch);
                    while(!st.empty() && st.top() != '(' && priority(st.top()) >= p) {
                        postfix.push_back(st.top());
                        st.pop();
                    }
                    st.push(ch);
                    break;
            case '-':p = priority(ch);
                    while(!st.empty() && st.top() != '(' && priority(st.top()) >= p) {
                        postfix.push_back(st.top());
                        st.pop();
                    }
                    st.push(ch);
                    break;
            case '*':p = priority(ch);
                    while(!st.empty() && st.top() != '(' && priority(st.top()) >= p) {
                        postfix.push_back(st.top());
                        st.pop();
                    }
                    st.push(ch);
                    break;
            case '/':p = priority(ch);
                    while(!st.empty() && st.top() != '(' && priority(st.top()) >= p) {
                        postfix.push_back(st.top());
                        st.pop();
                    }
                    st.push(ch);
                    break;
            case '^':p = priority(ch);
                    while(!st.empty() && st.top() != '(' && priority(st.top()) > p) {
                        postfix.push_back(st.top());
                        st.pop();
                    }
                    st.push(ch);
                    break;
            default:postfix.push_back(ch);
                    break;
        }
    }

    // Append all the remaining operators to the postfix expression
    while(!st.empty()) {
        postfix.push_back(st.top());
        st.pop();
    }

    // Return the postfix expression
    return postfix;
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
    string infix;
    input >> infix;

    // Close the input file
    input.close();

    // Call the subroutine to convert the expression to postfix
    string postfix = infixToPostfix(infix);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << postfix;
    
    // Close the output file and return
    output.close();
    return 0;
}