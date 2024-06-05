// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : spiral()
Description : Traverses the matrix elements in clockwise spiral order starting from the first row
Arguments   : A 2D vector denoting the matrix
Return      : A 2D vector denoting the rotated matrix
*/
vector<int> spiral(vector<vector<int>> matrix) {

    // Declare and initialize the required local variables
    int m, n;
    m = matrix.size();
    n = matrix[0].size();
    int left = 0, right = n - 1, up = 0, bottom = m - 1;
    vector<int> traversal;

    while(up <= bottom) {
        
        for(int i = left; i <= right; i++)
            traversal.push_back(matrix[up][i]);
        up++;
        
        if(right >= left)
            for(int i = up; i <= bottom; i++)
                traversal.push_back(matrix[i][right]);
        right--;
        
        if(bottom >= up)
            for(int i = right; i >= left; i--)
                traversal.push_back(matrix[bottom][i]);
        bottom--;
        
        if(left <= right)
            for(int i = bottom; i >= up; i--)
                traversal.push_back(matrix[i][left]);
        left++;

    }

    // Return the traversed elements
    return traversal;
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
    int m, n;
    input >> m >> n;
    vector<vector<int>> matrix(m, vector<int> (n, 0));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            input >> matrix[i][j];

    // Close the input file
    input.close();

    // Call the subroutine to traverse the matrix in spiral order
    vector<int> traversal = spiral(matrix);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < traversal.size(); i++)
        (i == 0) ? (output << traversal[i]) : (output << ' ' << traversal[i]);
    
    // Close the output file and return
    output.close();
    return 0;
}