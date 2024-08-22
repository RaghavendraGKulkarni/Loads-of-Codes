// Include the required header files
#include<iostream>
#include<fstream>
#include<array>
#include<stack>
using namespace std;

/*
Name        : validParentheses()
Description : Checks if the given combination of parentheses is valid or not
Arguments   : The parentheses string
Return      : True, if the parentheses combination is valid and False, otherwise
*/
bool validParentheses(string parentheses) {
    
    // Initialize the required local variables
    int minOpen = 0, maxOpen = 0;

    // For every parenthesis
    for(auto &parenthesis : parentheses) {
        
        switch(parenthesis) {

            // If the parenthesis is an opening parenthesis, increment both minOpen and maxOpen
            case '(':minOpen++;
                    maxOpen++;
                    break;
            
            // If the parenthesis is a closing parenthesis, derement both minOpen and maxOpen
            case ')':minOpen--;
                    maxOpen--;
                    break;
            
            // If the parenthesis is a '*', decrement minOpen and increment maxOpen
            default:minOpen--;
                    maxOpen++;
                    break;
        }

        // Check for validity
        if(maxOpen < 0)
            return false;
        if(minOpen < 0)
            minOpen = 0;
    }

    // Return the validity status
    return (minOpen == 0);
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
    string parentheses;
    bool result;
    input >> parentheses;

    // Close the input file
    input.close();

    // Call the subroutine to check for validity of the parentheses
    result = validParentheses(parentheses);

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