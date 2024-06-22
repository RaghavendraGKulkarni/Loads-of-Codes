// Include the required header files
#include<iostream>
#include<fstream>
#include<array>
#include<unordered_map>
using namespace std;

/*
Name        : longestSubarray()
Description : Computes the longest subarray with a given sum in the array
Arguments   : An array of integers, a positive integer denoting the size of the array and an integer denoting the sum, in that order
Return      : An array of two integers denoting the left and right boundaries of the subarray
*/
array<int, 2> longestSubarray(int arr[], int n, int k) {

    // Initialize the required local variables
    int *leftSum = new int[n + 1], maxLength = 0, start, end;
    unordered_map<int, int> mp;

    // Construct the left prefix sum array
    leftSum[0] = 0;
    for(int i = 1; i <= n; i++)
        leftSum[i] = leftSum[i - 1] + arr[i - 1];
    
    // Iterate through the array and check for pairs
    for(int i = 1; i <= n; i++) {

        // If current prefix sum is required sum
        if(leftSum[i] == k && maxLength < i) {
            maxLength = i;
            start = 1;
            end = i;
        }

        // If the remaining prefix sum exists in the map
        else if(mp.find(leftSum[i] - k) != mp.end() && maxLength < (i - mp[leftSum[i] - k])) {
            maxLength = i - mp[leftSum[i] - k];
            start = mp[leftSum[i] - k] + 1;
            end = i;
        }

        // Store the first encountered prefix sum index
        if(mp.find(leftSum[i]) == mp.end())
            mp.insert({leftSum[i], i});
    }

    // Return the boundaries of the subarray
    return {start, end};
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
    input >> n >> k;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        input >> arr[i];

    // Close the input file
    input.close();

    // Call the subroutine to compute the longest subarray with given sum
    array<int, 2> result = longestSubarray(arr, n, k);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = result[0]; i <= result[1]; i++)
        (i == result[0]) ? (output << arr[i - 1]) : (output << ' ' << arr[i - 1]);
    
    // Delete the array, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}