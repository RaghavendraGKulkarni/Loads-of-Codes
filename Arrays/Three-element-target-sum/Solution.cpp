// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Name        : threeSum()
Description : Computes the unique triplets with a given sum in the array
Arguments   : An array of integers, a positive integer denoting the size of the array and an integer denoting the sum, in that order
Return      : A vector of triplets giving the sum 
*/
vector<vector<int>> threeSum(int arr[], int n, int k) {

    // Initialize the required local variables
    vector<vector<int>> result;

    // Sort the array
    sort(arr, arr + n);
    
    // Iterate through the array and check for triplets
    for(int i = 0; i < n; i++) {

        // Skip duplicate elements
        if(i > 0 && arr[i] == arr[i - 1])
            continue;
        
        // Initialize two pointers
        int l = i + 1, r = n - 1;
        
        // Move the pointers according to the current sum
        while(l < r) {

            // Calculate sum
            int sum = arr[i] + arr[l] + arr[r];
            
            // If sum is less than the target, increment left
            if(sum < k)
                l++;
            
            // Else if sum is greater than the target, decrement right
            else if(sum > k)
                r--;
            
            // Else, add the triplet to the result and skip duplicate elements
            else {
                result.push_back({arr[i], arr[l], arr[r]});
                l++;
                r--;
                while(l < r && arr[l] == arr[l - 1])
                    l++;
                while(l < r && arr[r] == arr[r + 1])
                    r--;
            }
        }
    }

    // Return the triplets
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

    // Call the subroutine to compute the triplets of given sum
    vector<vector<int>> result = threeSum(arr, n, k);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < result.size(); i++)
        (i == 0) ? (output << result[i][0] << ' ' << result[i][1] << ' ' << result[i][2]) : (output << endl << result[i][0] << ' ' << result[i][1] << ' ' << result[i][2]);
    
    // Delete the array, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}