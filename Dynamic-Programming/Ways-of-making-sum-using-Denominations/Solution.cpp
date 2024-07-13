// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : numWays()
Description : Computes the number of ways of making sum k with the n distinct denominations
Arguments   : The array of denominations and two positive integers denoting the size of the array and the target sum, in that order
Return      : An integer denoting the number of ways of making the sum k
*/
int numWays(int arr[], int n, int sum) {
    
    // Intitialize the required local variables
    int *dp = new int[sum + 1], result;
    dp[0] = 1;
    for(int i = 1; i <= sum; i++)
        dp[i] = 0;
    
    // Run the nested loop to compute the number of ways
    for(int i = 0; i < n; i++)
        for(int j = 1; j <= sum; j++)
            if(arr[i] <= j)
                dp[j] += dp[j - arr[i]];
    
    // Store the result and delete the array
    result = dp[sum];
    delete[] dp;

    // Return the ressult
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
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        input >> arr[i];

    // Close the input file
    input.close();

    // Call the subroutine to compute the number of ways
    int result = numWays(arr, n, k);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Delete the array, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}