// Include the required header files
#include<iostream>
#include<fstream>
#include<array>
using namespace std;

/*
Name        : search()
Description : Computes the index of an element in the sorted matrix
Arguments   : The matrix, the number of rows and columns in the matrix and the element to be searched, in that order
Return      : An pair of integers denoting the index of the element if found and -1 otherwise
*/
array<int, 2> search(int **arr, int m, int n, int key) {
    
    // Initialize the required local variables
    int low = 0, high = m - 1, mid, mid1;

    // Search along the first column for the appropriate row
    while(low <= high) {
        mid = low + (high - low)/2;
        if(arr[mid][0] > key)
            high = mid - 1;
        else if(mid + 1 < m && arr[mid][0] <= key && key < arr[mid + 1][0])
            break;
        else
            low = mid + 1;
    }

    // Check if element to be found is less than first element
    if(key < arr[mid][0])
        return {-1, -1};
    
    // Check if element is present in the first column itself
    if(arr[mid][0] == key)
        return {mid + 1, 1};
    
    // Check if element lies between two row ranges or is greater than the last element
    if(arr[mid][n - 1] < key)
        return {-1, -1};
    
    // Binary search on the appropriate row for the element
    low = 0, high = n - 1;
    while(low <= high) {
        mid1 = low + (high - low)/2;
        if(arr[mid][mid1] == key)
            return {mid + 1, mid1 + 1};
        if(arr[mid][mid1] > key)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }

    // Return -1 if element not found
    return {-1, -1};
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
    int m, n, key;
    input >> m >> n >> key;
    int **arr = new int*[m];
    for(int i = 0; i < m; i++) {
        arr[i] = new int[n];
        for(int j = 0; j < n; j++)
            input >> arr[i][j];
    }

    // Close the input file
    input.close();

    // Call the subroutine to find the index of the element
    array<int, 2> result = search(arr, m, n, key);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the result to the output file
    (result[0] == -1) ? output << "-1" : output << result[0] << ' ' << result[1];
    
    // Delete the matrix, close the output file and return
    for(int i = 0; i < m; i++)
        delete[] arr[i];
    delete[] arr;
    output.close();
    return 0;
}