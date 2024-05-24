// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : partition()
Description : Partitions the array into two subarrays by finding a pivot point
Arguments   : The array and the boundaries of subarrays, in that order
Return      : The index of the pivot partition
*/
int partition(int arr[], int low, int high) {
    
    // Initialize the required local variables
    int pivot = low - 1;

    // Swap the first and last element of the subarray
    swap(arr[low], arr[high]);

    // Traverse the subarray to find the pivot point
    for(int i = low; i < high; i++) {
        if(arr[i] < arr[high]) {
            pivot++;
            swap(arr[pivot], arr[i]);
        }
    }

    // Return the pivot element
    swap(arr[pivot + 1], arr[high]);
    return pivot + 1;
}

/*
Name        : quickSort()
Description : Sorts the array using Quick Sort recursively
Arguments   : The array to be sorted and the boundaries of the array, in that order
Return      : None
*/
void quickSort(int arr[], int low, int high) {
    
    // Handle the base case
    if(low >= high)
        return;
    
    // Partition the array by the pivot element
    int pivot = partition(arr, low, high);

    // Sort the left and right subarrays of the pivot
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);

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
    quickSort(arr, 0, n - 1);

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