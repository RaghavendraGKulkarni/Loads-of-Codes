// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : recursiveBubbleSort()
Description : Sorts the array using Bubble Sort recursively
Arguments   : The array to be sorted and the left and right indices of the array, in that order
Return      : None
*/
void recursiveBubbleSort(int arr[], int k, int n) {
    
    // Handle the base case
    if(k == n - 1)
        return;
    
    // Declare the required local variables
    int j;
    bool swapped = false;

    // For every adjacent element pair up to last k elements, check for correct order and swap
    for(j = 0; j < n - k - 1; j++)
        if(arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
            swapped = true;
    }
    
    // If there is a swap, recursively call for right subarray
    if(swapped)
        recursiveBubbleSort(arr, k + 1, n);
    
    // Return
    return;
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

    // Call the subroutine to sort the array
    recursiveBubbleSort(arr, 0, n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the sorted array to the output file
    for(int i = 0; i < n; i++)
        (i == 0) ? (output << arr[i]) : (output << ' ' << arr[i]);
    
    // Delete the array, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}