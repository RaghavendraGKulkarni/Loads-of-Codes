// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : heapify()
Description : Heapifies a subheap recursively
Arguments   : The array to be heapified, the root index and the last index of the array, in that order
Return      : None
*/
void heapify(int arr[], int index, int n) {
    
    // Initialize the required local variables
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    // Determine the largest element
    if(left < n && arr[left] > arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;

    // Recursively heapify the child nodes
    if(largest != index) {
        swap(arr[index], arr[largest]);
        heapify(arr, largest, n);
    }

    // Return
    return;
}

/*
Name        : build()
Description : Heapifies a complete array iteratively
Arguments   : The array to be heapified, the size of the array, in that order
Return      : None
*/
void build(int arr[], int n) {
    
    // Loop through every parent node and heapify
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, i, n);
}

/*
Name        : recursiveHeapSort()
Description : Sorts the array using iterative heapify
Arguments   : The array to be sorted and the size of the array, in that order
Return      : None
*/
void recursiveHeapSort(int arr[], int n) {
    
    // Heapify the complete array
    build(arr, n);

    // Extract maximum element and heapify again
    for(int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }

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

    // Declare the required variables and read the input
    int n;
    input >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        input >> arr[i];

    // Close the input file
    input.close();

    // Call the subroutine to sort the array
    recursiveHeapSort(arr, n);

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