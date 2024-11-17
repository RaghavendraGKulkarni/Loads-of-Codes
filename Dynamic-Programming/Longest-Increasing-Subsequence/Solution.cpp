// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : trace()
Description : Traces back the preceeding array to construct the subsequence
Arguments   : Two vectors denoting the elements and the preceeding numbers, 
                an integer denoting the last element index,
                and a vector to store the subsequence, in that order
Return      : None
*/
void trace(vector<int> arr, vector<int> prec, int last, vector<int> &result) {
    
    // Insert the element at the beginning of the subsequence
    result.insert(result.begin(), arr[last]);

    // Check if this element has any preceeding element
    if(prec[last] == -1)
        return;
    
    // If yes, continue constructing the sequence
    trace(arr, prec, prec[last], result);

    // Return
    return;

}

/*
Name        : longestIncreasing()
Description : Computes the longest increasing subsequence of the array
Arguments   : The array and a positive integer denoting the size of the array, in that order
Return      : A vector denoting the longest increasing subsequence
*/
vector<int> longestIncreasing(vector<int> arr) {
    
    // Declare the required local variables
    int n = arr.size(), i, j, maxLength, last;
    vector<int> result, dp(n), pred(n);

    // Initialize the base case
    dp[0] = 1;
    pred[0] = -1;
    last = 0;
    maxLength = 1;

    // Run the nested loop to calculate the longest increasing subsequence
    for(int i = 1; i < n; i++) {
        dp[i] = 1;
        pred[i] = -1;
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                pred[i] = j;
            }
        }
        if(dp[i] > maxLength) {
            maxLength = dp[i];
            last = i;
        }
    }

    // Trace back the prec array and construct the subsequence
    trace(arr, pred, last, result);

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
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        input >> arr[i];

    // Close the input file
    input.close();

    // Call the subroutine to compute the Longest Increasing Subsequence
    vector<int> result = longestIncreasing(arr);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < result.size(); i++)
        (i == 0) ? (output << result[i]) : (output << ' ' << result[i]);
    
    // Close the output file and return
    output.close();
    return 0;
}