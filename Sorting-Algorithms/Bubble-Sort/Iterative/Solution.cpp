// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : iterativeBubbleSort()
Description : Sorts the array using Bubble Sort iteratively
Arguments   : The array to be sorted and the size of the array, in that order
Return      : None
*/
void iterativeBubbleSort(int arr[], int n) {
    
    // Declare the required local variables
    int i, j;
    bool swapped = true;

    // Compare and swap adjacent elements until the array is sorted
    for(i = 0; (i < n - 1) && swapped; i++) {
        swapped = false;
        for(j = 0; j < n - i - 1; j++)
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
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
    iterativeBubbleSort(arr, n);

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