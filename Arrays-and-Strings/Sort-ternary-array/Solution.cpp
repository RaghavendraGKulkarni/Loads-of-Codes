// Include the required header files
#include<iostream>
#include<fstream>
#include<array>
#include<limits>
using namespace std;

/*
Name        : sortTernary()
Description : Sorts a ternary array in linear time and constant space
Arguments   : An array of integers and a positive integer denoting the size of the array, in that order
Return      : None
*/
void sortTernary(int arr[], int n) {

    // Handle the base case
    if(n == 1)
        return;
    
    // Initialize the required local variables
    int low = 0,  mid = 0, high = n - 1;
    
    // Traverse through the elements
    while(mid <= high) {

        // Check for the element
        switch(arr[mid]) {

            // Push 0s to the left
            case 0:swap(arr[low], arr[mid]);
                    low++;
                    mid++;
                    break;
            
            // Push 2s to the right
            case 2:swap(arr[mid], arr[high]);
                    high--;
                    break;
            
            // Keep 1s as it is
            default:mid++;
                    break;
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

    // Declare the required variables and read the array
    int n;
    input >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        input >> arr[i];

    // Close the input file
    input.close();

    // Call the subroutine to sort the ternary array
    sortTernary(arr, n);

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