// Include the required header files
#include<iostream>
#include<fstream>
#include<array>
#include<limits>
using namespace std;

/*
Name        : sortBinary()
Description : Sorts a binary array in linear time and constant space
Arguments   : An array of integers and a positive integer denoting the size of the array, in that order
Return      : None
*/
void sortBinary(int arr[], int n) {

    // Handle the base case
    if(n == 1)
        return;
    
    // Initialize the local variables
    int i = 0, j;

    // Move i to the first 1 in the array
    while(i < n && arr[i]==0)
        i++;
    
    // Bring every 0 to this position and increment i
    for(j = i; j < n; j++)
        if(arr[j] == 0) {
            swap(arr[i], arr[j]);
            i++;
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

    // Call the subroutine to sort the binary array
    sortBinary(arr, n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < n; i++)
        (i == 0) ? (output << arr[i]) : (output << ' ' << arr[i]);
    
    // Free the array, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}