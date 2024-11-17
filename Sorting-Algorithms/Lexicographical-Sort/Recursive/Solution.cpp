// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : build()
Description : Recursively builds the numbers in lexicographical order
Arguments   : A positive integer n denoting the range end point, the start point and a vector to store the result, in that order
Return      : None
*/
void build(int n, int start, vector<int> &result) {
    
    // Check if range boundary is crossed
    if(start > n)
        return;

    // Add the current number to result
    result.push_back(start);

    // Build the next number in lexicographical manner
    for(int i = 0; i <= 9; i++)
        build(n, start*10 + i, result);
    
    // Return
    return;
}

/*
Name        : recursiveLexicographicalSort()
Description : Sorts the range [1, n] in lexicographical order, recursively
Arguments   : A positive integer n denoting the range end point
Return      : A vector denoting the sorted array
*/
vector<int> recursiveLexicographicalSort(int n) {
    
    // Declare the required local variables
    vector<int> result;

    // Initiate the recursion to add the numbers
    for(int start = 1; start <= 9; start++)
        build(n, start, result);
    
    // Return the result
    return result;
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

    // Call the subroutine to print the array
    vector<int> result = recursiveLexicographicalSort(n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < n; i++)
        (i == 0) ? (output << result[i]) : (output << ' ' << result[i]);
    
    // Close the output file and return
    output.close();
    return 0;
}