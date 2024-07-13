// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : singleElement()
Description : Computes the element that occurs only once in the array
Arguments   : The integer array and an integer denoting the size of the array, in that order
Return      : A single integer denoting the element occuring only once
*/
int singleElement(int arr[], int n) {
    
    // Initialize the required local variables
    int single = 0;

    // Loop through the elements to find the single occuring element
    for(int i = 0; i < n; i++)
        single ^= arr[i];
    
    // Return the single occuring element
    return single;
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
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        input >> arr[i];

    // Close the input file
    input.close();

    // Call the subroutine to perform the operation
    int result = singleElement(arr, n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Delete the array, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}