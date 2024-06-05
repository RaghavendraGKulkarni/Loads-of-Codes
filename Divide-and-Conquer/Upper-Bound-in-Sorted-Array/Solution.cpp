// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : upperBound()
Description : Computes the smallest element greater than a given number in a sorted array
Arguments   : The array, the size of the array and the number, in that order
Return      : The index of the smallest element greater than the given number
*/
int upperBound(int arr[], int n, int key) {
    
    // Initialize the required local variables
    int low = 0, mid, high = n - 1;

    // Binary search to find the upper bound
    while(low <= high) {
        mid = low + (high - low)/2;
        if(arr[mid] < key)
            low = mid + 1;
        else if(arr[mid] >= key && (mid == 0 || arr[mid - 1] <= key))
            return mid;
        else
            high = mid - 1;
    }

    // Return -1 on failure
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
    int n, key;
    input >> n >> key;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        input >> arr[i];

    // Close the input file
    input.close();

    // Call the subroutine to calculate the upper bound
    int result = upperBound(arr, n, key);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the result to the output file
    if(result == -1)
        output << "-1";
    else
        output << result + 1;
    
    // Delete the array, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}