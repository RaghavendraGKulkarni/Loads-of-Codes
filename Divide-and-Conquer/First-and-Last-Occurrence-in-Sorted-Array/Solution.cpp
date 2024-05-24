// Include the required header files
#include<iostream>
#include<fstream>
#include<array>
using namespace std;

/*
Name        : occurrence()
Description : Computes the subarray that crosses mid index and has the maximum sum
Arguments   : The array and the indices low, mid and high, in that order
Return      : An array denoting the left and right boundaries of the subarray and the maximum sum
*/
array<int, 2> occurrence(int arr[], int n, int key) {
    
    // Initialize the required local variables
    int low = 0, mid, high = n - 1, left = -1, right = -1;

    // Binary search to find the left occurrence
    while(low <= high) {
        mid = low + (high - low)/2;
        if(arr[mid] > key)
            high = mid - 1;
        else if(arr[mid] < key)
            low = mid + 1;
        else {
            left = mid;
            high = mid - 1;
        }
    }

    // re-initialize the local variables
    low = 0;
    high = n - 1;

    // Binary search to find the right occurrence
    while(low <= high) {
        mid = low + (high - low)/2;
        if(arr[mid] > key)
            high = mid - 1;
        else if(arr[mid] < key)
            low = mid + 1;
        else {
            right = mid;
            low = mid + 1;
        }
    }

    // Add the left and right sums and return the array
    return {left, right};
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

    // Declare the required variables and read the array
    int n, key;
    input >> n >> key;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        input >> arr[i];

    // Close the input file
    input.close();

    // Call the subroutine to calculate the first and last occurrences
    array<int, 2> result = occurrence(arr, n, key);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the result to the output file
    if(result[0] == -1)
        output << "-1";
    else
        output << result[0] + 1 << ' ' << result[1] + 1;
    
    // Delete the array, close the output file and return
    output.close();
    delete[] arr;
    return 0;
}