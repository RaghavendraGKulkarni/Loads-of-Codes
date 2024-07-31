// Include the required header files
#include<iostream>
#include<fstream>
#include<stack>
#include<vector>
using namespace std;

/*
Name        : subArrayMaximum()
Description : Computes the maximum of every subarray of length k in the array
Arguments   : The array of numbers, the size of the array and the subarray size k, in that order
Return      : A vector containing the maximum values
*/
vector<int> subArrayMaximum(vector<int> arr, int n, int k) {

    // Handle the base case of subarray size 1
    if(k == 1)
        return arr;

    // Declare the required local variables
    deque<int> dq;
    vector<int> result;

    // Loop through the vector for calculating the maximums
    for(int i = 0; i < arr.size(); i++) {

        // Move the window to exclude the left end
        if(!dq.empty() && dq.front() == i - k)
            dq.pop_front();
        
        // Insert the right end into the window
        while(!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();
        dq.push_back(i);

        // Record the maximum
        if(i >= k - 1)
            result.push_back(arr[dq.front()]);
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
    int n, k;
    input >> n >> k;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++)
        input >> arr[i];

    // Close the input file
    input.close();

    // Call the subroutine to compute the largest rectangle
    vector<int> result = subArrayMaximum(arr, n, k);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result.size() << endl;
    for(int i = 0; i < result.size(); i++)
        (i == 0) ? (output << result[i]) : (output << ' ' << result[i]);
    
    // Close the output file and return
    output.close();
    return 0;
}