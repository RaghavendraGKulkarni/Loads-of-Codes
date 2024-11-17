// Include the required header files
#include<iostream>
#include<fstream>
#include<stack>
#include<array>
using namespace std;

/*
Name        : smallestSubarray()
Description : Computes the smallest subarray with sum atleast K in an array
Arguments   : The array, the size of the array and an integer denoting k, in that order
Return      : An array of two integers denoting the subarray boundaries
*/
array<int, 2> smallestSubarray(int arr[], int n, int k) {
    
    // Declare the required local variables
    int minLength = -1, leftEnd = -1, rightEnd = -1;
    long long sum = 0;
    deque<pair<long long, int>> dq;

    // Run through the array to find the subarray
    for(int right = 0; right < n; right++) {
        sum += 1LL*arr[right];
        if(sum >= k && (minLength == - 1 || minLength > right + 1)) {
            minLength = right + 1;
            leftEnd = 0;
            rightEnd = right;
        }
        while(!dq.empty() && sum - dq.front().first >= k) {
            int left = dq.front().second;
            dq.pop_front();
            if(minLength == -1 || minLength > right - left) {
                minLength = right - left;
                rightEnd = right;
                leftEnd = left + 1;
            }
        }
        while(!dq.empty() && dq.back().first > sum)
            dq.pop_back();
        dq.push_back({sum, right});
    }
    return {leftEnd, rightEnd};
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

    // Call the subroutine to compute the smallest subarray
    array<int, 2> result = smallestSubarray(arr, n, k);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    if(result[0] == -1)
        output << "None";
    else {
        for(int i = result[0]; i <= result[1]; i++)
            (i == result[0]) ? (output << arr[i]) : (output << ' ' << arr[i]);
    }
    
    // Delete the arrays, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}