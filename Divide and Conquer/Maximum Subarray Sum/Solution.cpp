// Include the required header files
#include<iostream>
#include<fstream>
#include<limits.h>
#include<array>
using namespace std;

/*
Name        : maximumCrossSubarraySum()
Description : Computes the subarray that crosses mid index and has the maximum sum
Arguments   : The array and the indices low, mid and high
Return      : An array denoting the left and right boundaries of the subarray and the maximum sum
*/
array<int, 3> maximumCrossSubarraySum(int arr[], int low, int mid, int high) {
    
    // Declare the required local variables
    int leftSum = INT_MIN, rightSum = INT_MIN, sum = 0, leftIndex = -1, rightIndex = -1;
    
    // Compute the maximum sum on the left of mid
    for(int i = mid; i >= low; i--) {
        sum += arr[i];
        if(leftSum < sum) {
            leftSum = sum;
            leftIndex = i;
        }
    }

    // Compute the maximum sum on the right of mid
    sum = 0;
    for(int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if(rightSum <= sum) {
            rightSum = sum;
            rightIndex = i;
        }
    }

    // Add the left and right sums and return the array
    return {leftIndex, rightIndex, leftSum + rightSum};
}

/*
Name        : maximumSubarraySum()
Description : Computes the subarray that is within the given boundary and has the maximum sum
Arguments   : The array and the indices low and high
Return      : An array denoting the left and right boundaries of the subarray and the maximum sum
*/
array<int, 3> maximumSubarraySum(int arr[], int low, int high) {
    
    // Handle the base case of one element subarray
    if(low == high)
        return {low, high, arr[low]};
    
    // Declare the required local variables
    array<int, 3> left, right, cross;
    int mid = low + (high - low)/2;

    // Calculate the left, right and crossing maximum subarray sums
    left = maximumSubarraySum(arr, low, mid);
    right = maximumSubarraySum(arr, mid + 1, high);
    cross = maximumCrossSubarraySum(arr, low, mid, high);
    
    // Compare the three sums and return the maximum
    if(left[2] > cross[2] && left[2] > right[2])
        return left;
    if(left[2] < cross[2] && cross[2] > right[2])
        return cross;
    return right;
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
    int n;
    input >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        input >> arr[i];

    // Close the input file
    input.close();

    // Call the subroutine to calculate the maximum sum subarray
    array<int, 3> result = maximumSubarraySum(arr, 0, n - 1);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the sum followed the subarray to the output file
    output << result[2] << endl;
    for(int i = result[0]; i <= result[1]; i++)
        (i == result[0]) ? (output << arr[i]) : (output << ' ' << arr[i]);
    
    // Close the output file, free the memory and return
    output.close();
    delete[] arr;
    return 0;
}