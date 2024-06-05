// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : merge()
Description : Merges two sorted subarrays into one sorted array
Arguments   : The complete array, buffer array and the boundaries of subarrays, in that order
Return      : None
*/
void merge(int arr[], int temp[], int low, int mid, int high) {
    
    // Initialize the required local variables
    int i = low, j = mid + 1, k = low;

    // Compare front element from both the arrays and add it to buffer array
    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Append the remaining part of the arrays, if any
    while(i <= mid)
        temp[k++] = arr[i++];
    while(j <= high)
        temp[k++] = arr[j++];
    
    // Transfer back the contents to original array and return
    for(i = low; i <= high; i++)
        arr[i] = temp[i];
    return;
}

/*
Name        : mergeSort()
Description : Sorts the array using Merge Sort recursively
Arguments   : The array to be sorted, an extra buffer array and the boundaries of the array, in that order
Return      : None
*/
void mergeSort(int arr[], int temp[], int low, int high) {
    
    // Handle the base case
    if(low >= high)
        return;
    
    // Partition the array into two halves
    int mid = (low + high)/2;

    // Sort the left and right halves of the array
    mergeSort(arr, temp, low, mid);
    mergeSort(arr, temp, mid + 1, high);

    // Merge the sorted halves and return
    merge(arr, temp, low, mid, high);
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

    // Declare the required variables and read the input
    int n;
    input >> n;
    int *arr = new int[n], *temp = new int[n];
    for(int i = 0; i < n; i++)
        input >> arr[i];

    // Close the input file
    input.close();

    // Call the subroutine to sort the array
    mergeSort(arr, temp, 0, n - 1);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < n; i++)
        (i == 0) ? (output << arr[i]) : (output << ' ' << arr[i]);
    
    // Delete the array, close the output file and return
    delete[] arr;
    delete[] temp;
    output.close();
    return 0;
}