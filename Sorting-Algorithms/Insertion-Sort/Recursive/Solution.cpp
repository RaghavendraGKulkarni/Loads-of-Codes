// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : recursiveInsertionSort()
Description : Sorts the array using Insertion Sort recursively
Arguments   : The array to be sorted, the index of array element to be inserted and the size of the array, in that order
Return      : None
*/
void recursiveInsertionSort(int arr[], int k, int n) {
    
    // Handle the base case
    if(k == n)
        return;
    
    // Declare the required local variables
    int j, v;
    v = arr[k];
    j = k - 1;

    // Insert the kth element to its correct position
    while(j >= 0 && arr[j] > v) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = v;

    // Recursively call for next right subarray
    recursiveInsertionSort(arr, k + 1, n);
    
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
    recursiveInsertionSort(arr, 0, n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < n; i++)
        (i == 0) ? (output << arr[i]) : (output << ' ' << arr[i]);
    
    // Delete the array, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}