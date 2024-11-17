// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : countSquares()
Description : Counts the number of square submatrices with all ones in it
Arguments   : The binary matrix
Return      : An integer denoting the number of square matrices
*/
int countSquares(vector<vector<int>> matrix) {
    
    // Declare the required local variables
    int m = matrix.size(), n = matrix[0].size(), result = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Calculate the number of submatrices for every cell ending submatrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = matrix[i][j];
            else if(matrix[i][j] == 1)
                dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
            result += dp[i][j];
        }
    }

    // Return the result
    return result;
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
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            input >> matrix[i][j];

    // Close the input file
    input.close();

    // Call the subroutine to compute the number of square submatrices with all ones
    int result = countSquares(matrix);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}