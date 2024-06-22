// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : peak()
Description : Computes the peak element in an unsorted array
Arguments   : The array and the size of the array, in that order
Return      : An integer denoting the peak element
*/
int peak(int arr[], int n) {
    
    // Handle the edge element cases
    if(n == 1)
        return arr[0];
    if(arr[0] > arr[1])
        return arr[0];
    if(arr[n - 1] > arr[n - 2])
        return arr[n - 1];

    // Initialize the required local variables
    int low = 1, mid, high = n - 2;

    // Binary search to find the peak element
    while(low <= high) {
        mid = low + (high - low)/2;
        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return arr[mid];
        else if(arr[mid] < arr[mid + 1])
            low = mid + 1;
        else
            high = mid - 1;
    }

    // Return -1 if element not found
    return -1;
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

    // Call the subroutine to find the peak element
    int result = peak(arr, n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the result to the output file
    output << result;
    
    // Delete the array, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}