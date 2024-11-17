// Include the required header files
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

/*
Name        : merge()
Description : Merges the two sorted arrays into one sorted array
Arguments   : The two sorted arrays, in that order
Return      : None
*/
void merge(vector<int> &arr1, vector<int> &arr2) {
    
    // Initialize the required local variables
    int i = arr1.size() - 1, j = 0;

    // Swap the elements
    while(i >= 0 && j < arr2.size()) {
        if(arr1[i] > arr2[j]) {
            swap(arr1[i], arr2[j]);
            i--;
            j++;
        }
        else
            break;
    }

    // Sort both the arrays
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

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
    int m, n;
    input >> m >> n;
    vector<int> arr1(m), arr2(n);
    for(int i = 0; i < m; i++)
        input >> arr1[i];
    for(int i = 0; i < n; i++)
        input >> arr2[i];

    // Close the input file
    input.close();

    // Call the subroutine to merge the arrays
    merge(arr1, arr2);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < m; i++)
        (i == 0) ? (output << arr1[i]) : (output << ' ' << arr1[i]);
    output << endl;
    for(int i = 0; i < n; i++)
        (i == 0) ? (output << arr2[i]) : (output << ' ' << arr2[i]);
    
    // Delete the arrays, close the output file and return
    output.close();
    return 0;
}