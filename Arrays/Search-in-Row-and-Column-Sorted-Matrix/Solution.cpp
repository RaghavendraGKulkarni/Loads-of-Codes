// Include the required header files
#include<iostream>
#include<fstream>
#include<array>
using namespace std;

/*
Name        : search()
Description : Computes the index of an element in the row and column sorted matrix
Arguments   : The matrix, the number of rows and columns in the matrix and the element to be searched, in that order
Return      : An pair of integers denoting the index of the element if found and -1 otherwise
*/
array<int, 2> search(int **arr, int m, int n, int key) {
    
    // Initialize the required local variables
    int row = 0, column = n - 1;

    // Search the matrix
    while(row < m && column >= 0) {
        if(arr[row][column] == key)
            return {row + 1, column + 1};
        if(arr[row][column] < key)
            row++;
        else
            column--;
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