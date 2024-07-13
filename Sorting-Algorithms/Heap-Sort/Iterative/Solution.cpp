// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : heapify()
Description : Heapifies a subheap iteratively
Arguments   : The array to be heapified, the root index and the last index of the array, in that order
Return      : None
*/
void heapify(int arr[], int index, int n) {
    
    // Initialize the required local variables
    bool heap = false;
    int v = arr[index], j, k;

    // Heapify the sub-heap
    while(!heap && 2*index + 1 < n) {
        j = 2*index + 1;
        if(j + 1 < n && arr[j] < arr[j + 1])
            j++;
        if(v >= arr[j])
            heap = true;
        else {
            arr[index] = arr[j];
            index = j;
        }
    }
    arr[index] = v;

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
Name        : iterativeHeapSort()
Description : Sorts the array using iterative heapify
Arguments   : The array to be sorted and the size of the array, in that order
Return      : None
*/
void iterativeHeapSort(int arr[], int n) {
    
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
    iterativeHeapSort(arr, n);

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