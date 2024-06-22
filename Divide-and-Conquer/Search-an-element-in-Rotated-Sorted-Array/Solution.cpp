// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : search()
Description : Computes the index of an element in the sorted rotated array
Arguments   : The array, the size of the array and the element to be searched, in that order
Return      : An integer denoting the index of the element if found and -1 otherwise
*/
int search(int arr[], int n, int key) {
    
    // Initialize the required local variables
    int low = 0, mid, high = n - 1;

    // Binary search to find the index of the element
    while(low <= high) {
        mid = low + (high - low)/2;
        if(arr[mid] == key)
            return mid + 1;
        if(arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++;
            high--;
        }
        else if(arr[low] <= arr[mid]) {
            if(arr[low] <= key && key <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else {
            if(arr[mid] <= key && key <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
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
    int n, key;
    input >> n >> key;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        input >> arr[i];

    // Close the input file
    input.close();

    // Call the subroutine to find the index of the element
    int result = search(arr, n, key);

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