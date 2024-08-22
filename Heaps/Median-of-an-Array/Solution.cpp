// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;

/*
Name        : median()
Description : Computes the median of every prefix subarray
Arguments   : An array of integers and a positive integer denoting the size of the array, in that order
Return      : A vector of n elements denoting the median of n prefix subarrays
*/
vector<double> median(int arr[], int n) {

    // Initialize the required local variables
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    double median;
    vector<double> result;
    
    // Loop through the array to find the medians
    for(int i = 0; i < n; i++) {

        // If first element, initialize it as median
        if(i == 0)
            median = arr[i];

        else {

            // If number less than median, add it to left
            if(arr[i] < median) {
                left.push(arr[i]);
                if(i % 2 == 1) {
                    right.push(median);
                    median = (left.top() + right.top())/2.0;
                }
                else {
                    median = left.top();
                    left.pop();
                }
            }

            // If number greater than median, add it to right
            else {
                right.push(arr[i]);
                if(i % 2 == 1) {
                    left.push(median);
                    median = (left.top() + right.top())/2.0;
                }
                else {
                    median = right.top();
                    right.pop();
                }
            }
        }

        // Record the median
        result.push_back(median);
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
    int n;
    input >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        input >> arr[i];

    // Close the input file
    input.close();

    // Call the subroutine to find the medians
    vector<double> result = median(arr, n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < result.size(); i++)
        (i == 0) ? (output << result[i]) : (output << endl << result[i]);
    
    // Delete the array, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}