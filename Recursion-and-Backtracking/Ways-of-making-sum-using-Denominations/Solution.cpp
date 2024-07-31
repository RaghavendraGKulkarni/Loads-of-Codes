// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Name        : build()
Description : Builds up each combination until the sum is reached or crossed
Arguments   : An array of the denominations, 
                an integer denoting the number of denominations
                an integer denoting the current index of denomination, 
                an integer denoting the sum remaining,
                a vector denoting the combination in building, and
                a 2D vector to store all the denominations
                in that order
Return      : None
*/
void build(int arr[], int n, int index, int target, vector<int> combination, vector<vector<int>> &combinations) {
    
    // Detect if the target is reached
    if(target == 0) {
        combinations.push_back(combination);
        return;
    }

    // Try adding all the possible denominations one by one
    for(int i = index; i < n && arr[i] <= target; i++) {
        combination.push_back(arr[i]);
        build(arr, n, i, target - arr[i], combination, combinations);
        combination.pop_back();
    }

    // Return
    return;
}

/*
Name        : ways()
Description : Generates all possible combinations of denominations for given sum
Arguments   : The array of denominations, the number of denominations and the target sum, in that order
Return      : A 2D vector denoting the combinations
*/
vector<vector<int>> ways(int arr[], int n, int k) {
    
    // Initialize the required local variables
    vector<vector<int>> combinations;
    vector<int> combination;

    // Sort the denominations array
    sort(arr, arr + n);

    // Build the combinations
    build(arr, n, 0, k, combination, combinations);
    
    // Return the combinations
    return combinations;
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

    // Call the subroutine to construct the ways
    vector<vector<int>> result = ways(arr, n, k);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < result.size(); i++) {
        if(i > 0)
            output << endl;
        for(int j = 0; j < result[i].size(); j++)
            (j == 0) ? (output << result[i][j]) : (output << ' ' << result[i][j]);
    }
    
    // Delete the array, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}