// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : pascalTriangle()
Description : Computes the first n rows of Pascal's Triangle
Arguments   : A single positive integer denoting n
Return      : A 2D vector denoting the n rows of Pascal's Triangle
*/
vector<vector<int>> pascalTriangle(int n) {
    
    // Declare the required local variables
    vector<vector<int>> rows;
    vector<int> row;

    // Populate the first row
    row.push_back(1);
    rows.push_back(row);

    // Calculate next row using the current row
    for(int i = 2; i <= n; i++) {
        row.push_back(0);
        for(int j = row.size() - 1; j > 0; j--)
            row[j] += row[j - 1];
        rows.push_back(row);
    }

    // Return the result
    return rows;
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

    // Close the input file
    input.close();

    // Call the subroutine to compute the rows
    vector<vector<int>> rows = pascalTriangle(n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < n; i++) {
        if(i > 0)
            output << endl;
        for(int j = 0; j < rows[i].size(); j++)
            (j == 0) ? (output << rows[i][j]) : (output << ' ' << rows[i][j]);
    }
    
    // Close the output file and return
    output.close();
    return 0;
}