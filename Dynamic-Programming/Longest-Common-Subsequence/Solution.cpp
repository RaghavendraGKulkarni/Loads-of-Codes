// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : trace()
Description : Traces back the dp array to construct the subsequence
Arguments   : The two arrays, 
                a 2D vector denoting the dp,
                and a vector to store the subsequence, in that order
Return      : None
*/
void trace(vector<int> arr1, vector<int> arr2, vector<vector<int>> dp, vector<int> &result) {
    
    // Declare the required local variables
    int i = arr1.size(), j = arr2.size();

    while(i > 0 && j > 0) {
        if(dp[i][j] == dp[i - 1][j - 1] + 1) {
            i--;
            j--;
            result.insert(result.begin(), arr1[i]);
        }
        else if(dp[i - 1][j] >= dp[i][j - 1])
            i--;
        else
            j--;
    }

    // Return
    return;
}

/*
Name        : longestCommon()
Description : Computes the longest common subsequence of the array
Arguments   : Two vectors denoting the arrays
Return      : A vector denoting the longest common subsequence
*/
vector<int> longestCommon(vector<int> arr1, vector<int> arr2) {
    
    // Declare the required local variables
    int i, j, m = arr1.size(), n = arr2.size();
    vector<int> result;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Run the nested loop to calculate the longest common subsequence
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(arr1[i - 1] == arr2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Trace back the dp array and construct the subsequence
    trace(arr1, arr2, dp, result);

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
    vector<int> arr1(m), arr2(n);
    for(int i = 0; i < m; i++)
        input >> arr1[i];
    for(int i = 0; i < n; i++)
        input >> arr2[i];

    // Close the input file
    input.close();

    // Call the subroutine to compute the Longest Common Subsequence
    vector<int> result = longestCommon(arr1, arr2);

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