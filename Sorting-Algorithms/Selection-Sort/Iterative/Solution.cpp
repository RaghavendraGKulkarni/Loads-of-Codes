// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : iterativeSelectionSort()
Description : Sorts the array using Selection Sort recursively
Arguments   : The array to be sorted and the size of the array, in that order
Return      : None
*/
void iterativeSelectionSort(int arr[], int n) {
    
    // Declare the required local variables
    int i, j = 0, index;

    // Find the maximum of the array and swap with the last element
    for(i = 0; i < n; i++) {
        index = i;
        for(j = i; j < n; j++)
            if(arr[j] < arr[index])
                index = j;
        swap(arr[i], arr[index]);
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
    iterativeSelectionSort(arr, n);

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