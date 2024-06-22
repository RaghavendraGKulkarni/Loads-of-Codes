// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
Name        : twoSum()
Description : Computes the unique pairs with a given sum in the array
Arguments   : An array of integers, a positive integer denoting the size of the array and an integer denoting the sum, in that order
Return      : A vector of pairs giving the sum 
*/
vector<vector<int>> twoSum(int arr[], int n, int k) {

    // Initialize the required local variables
    unordered_map<int, int> mp;
    vector<vector<int>> result;
    
    // Iterate through the array and check for pairs
    for(int i = 0; i < n; i++) {

        // If the current element was already checked, skip
        if(mp.find(arr[i]) != mp.end())
            continue;

        // If the required element exists in map, add the pair to the result
        if(mp.find(k - arr[i]) != mp.end())
            result.push_back({k - arr[i], arr[i]});

        // Store the first encountered index of the element
        mp.insert({arr[i], i});
    }

    // Return the pairs
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

    // Call the subroutine to compute the pairs of given sum
    vector<vector<int>> result = twoSum(arr, n, k);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < result.size(); i++)
        (i == 0) ? (output << result[i][0] << ' ' << result[i][1]) : (output << endl << result[i][0] << ' ' << result[i][1]);
    
    // Delete the array, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}