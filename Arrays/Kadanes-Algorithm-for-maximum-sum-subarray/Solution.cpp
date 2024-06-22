// Include the required header files
#include<iostream>
#include<fstream>
#include<array>
#include<limits>
using namespace std;

/*
Name        : kadane()
Description : Computes the maximum sum of a subarray in the array
Arguments   : An array of integers and a positive integer denoting the size of the array, in that order
Return      : An array of three integers denoting the left boundary, right boundary and the sum of the subarray
*/
array<int, 3> kadane(int arr[], int n) {

    // Initialize the required local variables
    int sum = 0, max = INT_MIN, i, start = 0, end = -1, s = 0;
    
    // Traverse the array to find the maximum subarray sum
    for(i = 0; i < n; i++) {

        // Add the element to the sum
        sum += arr[i];

        // Check for maximum and reassign start and end boundaries
        if(max < sum) {
            max = sum;
            start = s;
            end = i;
        }

        // If negative sum, restart subarray sum and boundaries
        if(sum < 0) {
            sum = 0;
            s = i + 1;
        }
    }

    // If no such subarray exists, search for maximum single element
    if(end == -1) {
        max = INT_MIN;
        for(i = 0; i < n; i++)
            if(max < arr[i]) {
                max = arr[i];
                start = i;
                end = i;
            }
    }

    // Return the subarray boundaries and the sum
    return {start, end, max};
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

    // Call the subroutine to compute the maximum subarray sum
    array<int, 3> result = kadane(arr, n);

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