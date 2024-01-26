// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : iterativeInsertionSort()
Description : Sorts the array using Insertion Sort iteratively
Arguments   : The array to be sorted and the size of the array, in that order
Return      : None
*/
void iterativeInsertionSort(int arr[], int n) {
    
    // Declare the required local variables
    int i, j, v;

    // Insert the elements from right towards left in-place
    for(i = 1; i < n; i++) {
        v = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > v) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = v;
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

    // Declare the required variables and read the array
    int n;
    input >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        input >> arr[i];

    // Close the input file
    input.close();

    // Call the subroutine to sort the array
    iterativeInsertionSort(arr, n);

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