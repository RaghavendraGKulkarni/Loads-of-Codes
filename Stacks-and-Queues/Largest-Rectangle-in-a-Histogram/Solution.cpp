// Include the required header files
#include<iostream>
#include<fstream>
#include<stack>
#include<array>
using namespace std;

/*
Name        : largestRectangle()
Description : Computes the largest rectangle in a histogram
Arguments   : The array of histogram heights and the size of the array, in that order
Return      : An array of three elements denoting the area, left and right boundary indices of the rectangle
*/
array<int, 3> largestRectangle(int arr[], int n) {
    
    // Declare the required local variables
    int maxArea = 0, height, width, left, right;
    stack<int> st;

    // Loop through the array of heights
    for(int i = 0; i <= n; i++){

        // Find the left boundary for rectangle with current bar as right boundary
        while(!st.empty() && (i == n || arr[st.top()] >= arr[i])){
            height = arr[st.top()];
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
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        input >> arr[i];

    // Close the input file
    input.close();

    // Call the subroutine to compute the largest rectangle
    array<int, 3> result = largestRectangle(arr, n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result[0] << endl;
    output << result[1] << ' ' << result[2];
    
    // Delete the arrays, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}