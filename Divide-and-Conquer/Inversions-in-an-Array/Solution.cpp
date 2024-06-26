// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : merge()
Description : Merges two sorted halves of the array and counts the number of inversions
Arguments   : The array to be sorted, a buffer array and the boundaries of the subarrays to be merged, in that order
Return      : The number of inversions computed in merging the sorted subarrays
*/
int merge(int arr[], int temp[], int low, int mid, int high) {
    
    // Initialize the required local variables
    int i = low, j = mid, k = low, inversions = 0;

    // Compare front element from both the arrays and add it to buffer array
    while(i <= mid - 1 && j <= high) {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inversions += (mid - i);
        }
    }

    // Append the remaining part of the arrays, if any
    while(i <= mid - 1)
        temp[k++] = arr[i++];
    while(j <= high){
        temp[k++] = arr[j++];
        inversions += (mid - i);
    }
    
    // Transfer back the contents to original array and return the number of inversions
    for(i = low; i <= high; i++)
        arr[i] = temp[i];
    return inversions;
}

/*
Name        : mergeSort()
Description : Counts the number of inversions in an array using Merge Sort recursively
Arguments   : The array to be sorted, a buffer array and the boundaries of the array, in that order
Return      : The number of inversions in the array
*/
int mergeSort(int arr[], int temp[], int low, int high) {
    
    // Handle the base case
    if(low >= high)
        return 0;
    
    // Partition the array into two halves
    int mid = (low + high)/2, inversions = 0;

    // Sort the left and right halves of the array
    inversions += mergeSort(arr, temp, low, mid);
    inversions += mergeSort(arr, temp, mid + 1, high);

    // Merge the sorted halves
    inversions += merge(arr, temp, low, mid + 1, high);
    
    // Return the number of inversions
    return inversions;
}

/*
Name        : countInversion()
Description : Counts the number of inversions in an array using Merge Sort recursively
Arguments   : The array and the size of the array, in that order
Return      : The number of inversions in the array
*/
int countInversion(int arr[], int n) {
    
    // Declare the required local variables
    int *temp = new int[n], inversions = 0;

    // Apply merge sort on the array
    inversions = mergeSort(arr, temp, 0, n - 1);

    // Delete the temporary buffer and return the number of inversions
    delete[] temp;
    return inversions;
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
    int n, inversions;
    input >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        input >> arr[i];

    // Close the input file
    input.close();

    // Call the subroutine to count the inversions in the array
    inversions = countInversion(arr, n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << inversions;
    
    // Delete the array, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}