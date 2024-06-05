// Include the required header files
#include<iostream>
#include<fstream>
#include<array>
using namespace std;

/*
Name        : maxProductSubarray()
Description : Computes the maximum product of a subarray in the array
Arguments   : An array of integers and a positive integer denoting the size of the array, in that order
Return      : An array of three integers denoting the left boundary, right boundary and the product of the subarray
*/
array<int, 3> maxProductSubarray(int arr[], int n) {
    
    // Initialize the required variables
    int prefixProduct = 1, prefixStart = 0, prefixEnd, suffixProduct = 1, suffixStart, suffixEnd = n - 1, maxProduct = 1, maxStart, maxEnd;

    for(int i = 0; i < n; i++) {

        // If the prefix product is zero, restart the prefix product
        if(prefixProduct == 0) {
            prefixProduct = 1;
            prefixStart = i;
        }

        // If the suffix product is zero, restart the suffix product
        if(suffixProduct == 0) {
            suffixProduct = 1;
            suffixEnd = n - 1 - i;
        }

        // Multiply the ith element from start to the prefix product
        prefixProduct *= arr[i];
        prefixEnd = i;

        // Multiply the ith element from end to the suffix product
        suffixProduct *= arr[n - 1 - i];
        suffixStart = n - 1 - i;

        // Take the maximum of the products and store the indices
        if(prefixProduct >= maxProduct) {
            maxProduct = prefixProduct;
            maxStart = prefixStart;
            maxEnd = prefixEnd;
        }
        if(suffixProduct >= maxProduct) {
            maxProduct = suffixProduct;
            maxStart = suffixStart;
            maxEnd = suffixEnd;
        }
    }

    return {maxStart, maxEnd, maxProduct};
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
    input >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        input >> arr[i];

    // Close the input file
    input.close();

    // Call the subroutine to compute the maximum product subarray
    array<int, 3> result = maxProductSubarray(arr, n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result[2] << endl;
    for(int i = result[0]; i <= result[1]; i++)
        (i == result[0]) ? (output << arr[i]) : (output << ' ' << arr[i]);
    
    // Delete the array, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}