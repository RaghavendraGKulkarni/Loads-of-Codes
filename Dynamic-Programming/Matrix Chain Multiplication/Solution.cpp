// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : matrixChainMultiplication()
Description : Computes the minimum number of scalar multiplications required to calculate the product of matrices
Arguments   : A vector denoting the orders of the matrices
Return      : A pair of integer denoting the minimum number of scalar multiplications and a string denoting the optimal combination
*/
string trace(vector<vector<int>> split, int left, int right) {
    
    // Handle the base case
    if(left == right)
        return "M" + to_string(left);
    
    // Return the combined combination
    return "(" + trace(split, left, split[left][right]) + " " + trace(split, split[left][right] + 1, right) + ")";
}

/*
Name        : matrixChainMultiplication()
Description : Computes the minimum number of scalar multiplications required to calculate the product of matrices
Arguments   : A vector denoting the orders of the matrices
Return      : A pair of integer denoting the minimum number of scalar multiplications and a string denoting the optimal combination
*/
pair<int, string> matrixChainMultiplication(vector<int> orders) {
    
    // Declare the required local variables
    int n = orders.size() - 1, temp;
    vector<vector<int>> cost(n + 1, vector<int>(n + 1, 0)), split(n + 1,vector<int>(n + 1, 0));
    
    // Iterate through the cost matrix and check all possible splits
    for(int diff = 1; diff < n; diff++) {
        for(int i = 1; i + diff <= n; i++) {
            cost[i][i + diff] = cost[i][i] + (orders[i - 1] * orders[i] * orders[i + diff]) + cost[i + 1][i + diff];
            split[i][i + diff] = i;
            for(int k = i + 1; k < i + diff; k++) {
                temp = cost[i][k] + (orders[i - 1] * orders[k] * orders[i + diff]) + cost[k + 1][i + diff];
                if(temp < cost[i][i + diff]) {
                    cost[i][i + diff] = temp;
                    split[i][i + diff] = k;
                }
            }
        }
    }

    // Trace the split matrix to find the combination
    string combination = trace(split, 1, n);
    
    // Return the result
    return {cost[1][n], combination};
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
    vector<int> orders(n + 1);
    for(int i = 0; i <= n; i++)
        input >> orders[i];

    // Close the input file
    input.close();

    // Call the subroutine to compute the Longest Increasing Subsequence
    pair<int, string> result = matrixChainMultiplication(orders);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result.first << endl << result.second;
    
    // Close the output file and return
    output.close();
    return 0;
}