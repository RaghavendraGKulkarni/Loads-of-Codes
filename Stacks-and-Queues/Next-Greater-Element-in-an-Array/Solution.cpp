// Include the required header files
#include<iostream>
#include<fstream>
#include<stack>
#include<vector>
using namespace std;

/*
Name        : nextGreaterElement()
Description : Computes the immediate next greater element for every element
Arguments   : The array and the size of the array, in that order
Return      : A vector storing the next greater elements
*/
vector<int> previousSmallerElement(int arr[], int n) {
    
    // Initialize the required local variables
    stack<int> st;
    vector<int> result;

    // For every element, compute the next greater element
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && st.top() <= arr[i])
            st.pop();
        if(st.empty())
            result.insert(result.begin(), -1);
        else
            result.insert(result.begin(), st.top());
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

    // Declare the required variables and read the input
    int n;
    input >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        input >> arr[i];

    // Close the input file
    input.close();

    // Call the subroutine to calculate the next greater element of every element
    vector<int> result = previousSmallerElement(arr, n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < n; i++)
        (i == 0) ? (output << result[i]) : (output << ' ' << result[i]);
    
    // Delete the arrays, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}