// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : jumpGame()
Description : Computes the minimum number of jumps to reach position n from position 1
Arguments   : The array of jumps and the size of the array, in that order
Return      : An integer denoting the minimum number of jumps
*/
vector<int> jumpGame(int arr[], int n) {
    
    // Initialize the required local variables
    int i, curMax = 0, maxReach = 0;
    vector<int> jumps = {0};

    // Loop through the jump array
    for(i = 0; i < n - 1; i++) {

        // Update the max reach
        if(maxReach < arr[i] + i) {
            maxReach = arr[i] + i;
            jumps[jumps.size() - 1] = i;
        }
        
        // Detect destination reached
        if(maxReach >= n - 1) {
            jumps.push_back(n - 1);
            break;
        }

        // Make a jump
        if(i == curMax) {
            jumps.push_back(i);
            curMax = maxReach;
        }
    }

    // Return the minimum number of jumps
    return jumps;
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

    // Call the subroutine to compute the minimum number of jumps
    vector<int> result = jumpGame(arr, n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    if(result.back() == n - 1) {
        output << result.size() - 1 << endl;
        for(int i = 0; i < result.size(); i++)
            (i == 0) ? (output << result[i]) : (output << " -> " << result[i]);
    }
    else
        output << "Not possible";
    
    // Delete the array, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}