// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : determinant()
Description : Computes the determinant of a square matrix by converting it to row-reduced echleon form
Arguments   : The square matrix
Return      : A single float denoting the determinant
*/
float determinant(vector<vector<float>> matrix) {
    
    // Declare the required local variables
    float det = 1.0, factor;
    int n = matrix.size();

    // Perform reduced row operations on the matrix to bring the upper triangular matrix
    for(int j = 0; j < n; j++) {
        for(int i = j + 1; i < n; i++) {
            factor = matrix[i][j]/matrix[j][j];
            for(int k = j; k < n; k++)
                matrix[i][k] = matrix[i][k] - factor * matrix[j][k];
        }
    }

    // Compute the determinant of this upper triangular matrix
    for(int i = 0; i < n; i++)
        det *= matrix[i][i];

    // Return the determinant
    return det;
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
    vector<vector<float>> matrix(n, vector<float>(n, 0.0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            input >> matrix[i][j];

    // Close the input file
    input.close();

    // Call the subroutine to compute the determinant of the matrix
    float result = determinant(matrix);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}