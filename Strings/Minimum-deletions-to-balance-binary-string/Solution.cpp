// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : balanceBinaryString()
Description : Computes the minimum number of deletions to balance a binary string
Arguments   : The string to be balanced
Return      : The minimum number of deletions
*/
int balanceBinaryString(string str) {
    
    // Initialize the required local variables
    int aLeft = 0, bLeft = 0, aRight = 0, bRight = 0, deletions;
    
    // Count the number of As and Bs
    for(auto &ch : str) {
        if(ch == 'A')
            aRight++;
        else
            bRight++;
    }

    // Loop through the string to check each partition
    deletions = bLeft + aRight;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == 'A') {
            aLeft++;
            aRight--;
        }
        else {
            bLeft++;
            bRight--;
        }
        deletions = min(deletions, bLeft + aRight);
    }

    // Return the number of deletions
    return deletions;
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
    string str;
    getline(input, str);

    // Close the input file
    input.close();

    // Call the subroutine to check if the string is a Pangram
    int result = balanceBinaryString(str);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}