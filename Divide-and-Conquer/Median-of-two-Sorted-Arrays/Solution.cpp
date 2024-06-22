// Include the required header files
#include<iostream>
#include<fstream>
#include<limits>
using namespace std;

/*
Name        : median()
Description : Computes the median of two sorted arrays
Arguments   : The two arrays and two integers denoting the sizes of first and second array, in that order
Return      : A float value denoting the median of the combined sorted array
*/
float median(int arr1[], int arr2[], int m, int n) {
    
    // If first array is larger, reverse the order
    if(m > n)
        return median(arr2, arr1, n, m);
    
    // Initialize the required local variables
    int total = m + n, left = (total + 1)/2;
    int low = 0, high = m, mid1, mid2, left1, right1, left2, right2;
    float med;

    // Binary search on how many elements of first array to include in the left half
    while(low <= high) {
        
        // Initialize the pointer values
        mid1 = low + (high - low)/2;
        mid2 = left - mid1;

        // Compute the left and right half extreme values
        left1 = (mid1 >= 1) ? arr1[mid1 - 1] : INT_MIN;
        right1 = (mid1 < m) ? arr1[mid1] : INT_MAX;
        left2 = (mid2 >= 1) ? arr2[mid2 - 1] : INT_MIN;
        right2 = (mid2 < n) ? arr2[mid2] : INT_MAX;

        // Check for valid left and right half and compute the median
        if(left1 <= right2 && left2 <= right1) {
            med = (total % 2 == 0) ? (max(left1, left2) + min(right1, right2))/2.0 : max(left1, left2);
            break;
        }

        // Eliminate the invalid half according to the condition
        if(left1 > right2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }

    // Return the median
    return med;
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
    int m, n;
    input >> m >> n;
    int *arr1 = new int[m];
    for(int i = 0; i < m; i++)
        input >> arr1[i];
    int *arr2 = new int[n];
    for(int i = 0; i < n; i++)
        input >> arr2[i];

    // Close the input file
    input.close();

    // Call the subroutine to find the median of the combined sorted array
    float result = median(arr1, arr2, m, n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the result to the output file
    output << result;
    
    // Delete the arrays, close the output file and return
    delete[] arr1;
    delete[] arr2;
    output.close();
    return 0;
}