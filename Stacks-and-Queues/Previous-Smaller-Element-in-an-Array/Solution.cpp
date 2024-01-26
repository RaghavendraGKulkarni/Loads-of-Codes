// Include the required header files
#include<iostream>
#include<fstream>
#include<array>
#include<stack>
using namespace std;

/*
Name        : previousSmallerElement()
Description : Computes the immediate previous smaller element for every element
Arguments   : The array, the size of the array and the array to store the previous smaller elements
Return      : The array storing the previous smaller elements
*/
int* previousSmallerElement(int arr[], int n, int result[]) {
    
    // Initialize the required local variables
    stack<int> st;

    // For every element, compute the previous smaller element
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[i] <= st.top())
            st.pop();
        result[i] = (st.empty()) ? -1 : st.top();
        st.push(arr[i]);
    }
    
    // Return the result array
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

    // Declare the required variables and read the array
    int n, key;
    input >> n;
    int *arr = new int[n], *result = new int[n];
    for(int i = 0; i < n; i++)
        input >> arr[i];

    // Close the input file
    input.close();

    // Call the subroutine to calculate the first and last occurrences
    result = previousSmallerElement(arr, n, result);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the result to the output file
    for(int i = 0; i < n; i++)
        (i == 0) ? (output << result[i]) : (output << ' ' << result[i]);
    
    // Close the output file, free the memory and return
    output.close();
    delete[] arr;
    delete[] result;
    return 0;
}