// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : rotate()
Description : Rotates the matrix clockwise or anti-clockwise by 90 degrees
Arguments   : A 2D vector denoting the matrix and an integer dir denoting the direction of rotation
Return      : A 2D vector denoting the rotated matrix
*/
vector<vector<int>> rotate(vector<vector<int>> matrix, int dir) {

    // Declare and initialize the required local variables
    int m, n;
    m = matrix.size();
    n = matrix[0].size();

    // Exchange rows or columns according to the direction
    if(dir == 1)
        for(int j = 0; j < n; j++)
            for(int i = 0; i < m - 1 - i; i++)
                swap(matrix[i][j], matrix[m - 1 - i][j]);
    else
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n - 1 - j; j++)
                swap(matrix[i][j], matrix[i][n - 1 - j]);

    // Take the transpose of the matrix
    for(int i = 0; i < m; i++)
        for(int j = 0; j < i; j++)
            if(i != j)
                swap(matrix[i][j], matrix[j][i]);

    // Return the rotated matrix
    return matrix;
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

    // Declare the required variables, read the input
    int m, n, dir;
    input >> m >> n;
    vector<vector<int>> matrix(m, vector<int> (n, 0));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            input >> matrix[i][j];
    input >> dir;

    // Close the input file
    input.close();

    // Call the subroutine to rotate the matrix
    matrix = rotate(matrix, dir);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < m; i++) {
        if(i > 0)
            output << endl;
        for(int j = 0; j < n; j++)
            (j == 0) ? (output << matrix[i][j]) : (output << ' ' << matrix[i][j]);
    }
    
    // Close the output file and return
    output.close();
    return 0;
}