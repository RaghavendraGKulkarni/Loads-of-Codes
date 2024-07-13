// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : getSetClear()
Description : Performs Get, Set or Clear operation on the kth bit of a 32-bit integer
Arguments   : A 32-bit integer n, the bit number k and the operation to be performed, in that order
Return      : A single integer denoting the result of the operation
*/
int getSetClear(int n, int k, const string op) {
    
    // Select the operation based on the string
    if(op == "GET")
        return ((n & (1 << (k - 1))) >> (k - 1));
    if(op == "SET")
        return (n | (1 << (k - 1)));
    return (n & (~(1 << (k - 1))));
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
    int n, k;
    string op;
    input >> n >> k >> op;

    // Close the input file
    input.close();

    // Call the subroutine to perform the operation
    int result = getSetClear(n, k, op);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}