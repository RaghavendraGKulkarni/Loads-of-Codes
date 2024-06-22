// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : squareRoot()
Description : Computes the square root of n rounded off to nearest integer
Arguments   : A positive integer n
Return      : An integer denoting the square root of n rounded off to nearest integer
*/
int squareRoot(int n) {
    
    // Initialize the required local variables
    int low = 1, mid, high = n;

    // Binary search to find the floor of square root
    while(low <= high) {
        mid = low + (high - low)/2;
        if(mid*mid == n)
            break;
        if(mid*mid < n && (mid + 1)*(mid + 1) > n)
            break;
        if(mid*mid > n)
            high = mid - 1;
        else
            low = mid + 1;
    }

    // Return the nearest integer
    return ((n - mid*mid) < ((mid + 1)*(mid + 1) - n)) ? mid : (mid + 1);
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
    int n;
    input >> n;

    // Close the input file
    input.close();

    // Call the subroutine to find the square root
    int result = squareRoot(n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the result to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}