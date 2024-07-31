// Include the required header files
#include<iostream>
#include<fstream>
#include<stack>
#include<array>
#include<vector>
using namespace std;

/*
Name        : largestHistogram()
Description : Computes the largest rectangle in a histogram
Arguments   : The vector of histogram heights
Return      : An array of three elements denoting the area, left and right boundary indices of the rectangle
*/
array<int, 3> largestHistogram(vector<int> row) {
    
    // Declare the required local variables
    int n = row.size(), maxArea = 0, height, width, left, right;
    stack<int> st;

    // Loop through the array of heights
    for(int i = 0; i <= n; i++){

        // Find the left boundary for rectangle with current bar as right boundary
        while(!st.empty() && (i == n || row[st.top()] >= row[i])){
            height = row[st.top()];
            st.pop();
            if(st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            if(maxArea < height * width) {
                maxArea = height * width;
                right = i;
                left = right - width + 1;
            }
        }

        // Push the index into the stack
        st.push(i);
    }

    // Return the rectangle area and boundaries
    return {maxArea, left, right};
}

/*
Name        : largestRectangle()
Description : Computes the largest rectangle of 1s in a binary matrix
Arguments   : A 2D vector denoting the binary matrix
Return      : An array of five elements denoting the area, top, bottom, left and right boundary indices of the rectangle
*/
array<int, 5> largestRectangle(vector<vector<int>>& matrix) {
    
    // Declare the required local variables
    int m = matrix.size(), n = matrix[0].size(), maxArea = 0, left, right, top, bottom, height, width;
    vector<int> row(n, 0);

    // Traverse the matrix to compute the largest rectangle
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 1)
                row[j] += 1;
            else
                row[j] = 0;
        }
        array<int, 3> result = largestHistogram(row);
        if(maxArea < result[0]) {
            maxArea = result[0];
            left = result[1];
            right = result[2];
            bottom = i + 1;
        }
    }

    // Compute the boundaries of the rectangle
    width = right - left + 1;
    height = maxArea/width;
    top = bottom - height + 1;

    // Return the rectangle boundaries
    return {maxArea, top, bottom, left, right};
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
    vector<vector<int>> matrix(m, vector<int> (n, 0));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            input >> matrix[i][j];

    // Close the input file
    input.close();

    // Call the subroutine to compute the largest rectangle
    array<int, 5> result = largestRectangle(matrix);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result[0] << endl;
    output << result[1] << ' ' << result[2] << ' ' << result[3] << ' ' << result[4];
    
    // Close the output file and return
    output.close();
    return 0;
}