// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : repeating()
Description : Finds the repeating element in a range bounded array
Arguments   : An array of integers and a positive integer denoting the size of the array, in that order
Return      : An integer denoting the repeating number
*/
int repeating(int arr[], int n) {
    
    // Initialize the required local variables
    int slow = arr[0], fast = arr[0];

    // Move the slow fast pointers until they meet
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while(slow != fast);

    // Find the entry point of the cycle
    slow = arr[0];
    while(slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    // Return the repeating element
    return slow;
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

    // Call the subroutine to find the repeating element
    int result = repeating(arr, n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Delete the array, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}