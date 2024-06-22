// Include the required header files
#include<iostream>
#include<fstream>
#include<limits>
#include<array>
using namespace std;

/*
Name        : minMax()
Description : Computes the minimum and maximum in the sorted rotated array
Arguments   : The array and the size of the array, in that order
Return      : An array of two integers denoting the minimum and maximum respectively
*/
array<int, 2> minMax(int arr[], int n) {
    
    // Initialize the required local variables
    int low = 0, mid, high = n - 1, minElement = INT_MAX, maxElement = INT_MIN;

    // Binary search to find the index of the element
    while(low <= high) {
        mid = low + (high - low)/2;
        if(arr[low] <= arr[high]) {
            minElement = min(minElement, arr[low]);
            maxElement = max(maxElement, arr[high]);
            break;
        }
        if(arr[low] <= arr[mid]) {
            minElement = min(minElement, arr[low]);
            maxElement = max(maxElement, arr[mid]);
            low = mid + 1;
        }
        else {
            minElement = min(minElement, arr[mid]);
            maxElement = max(maxElement, arr[high]);
            high = mid - 1;
        }
    }

    // Return -1 if element not found
    return {minElement, maxElement};
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

    // Call the subroutine to find the minimum and maximum
    array<int, 2> result = minMax(arr, n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the result to the output file
    output << result[0] << ' ' << result[1];
    
    // Delete the array, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}