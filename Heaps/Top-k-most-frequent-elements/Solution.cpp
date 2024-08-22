// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

/*
Name        : topKFrequent()
Description : Computes the top k most frequent elements in an array
Arguments   : An array of integers and two positive integers n and k denoting the size of the array and value of k, in that order
Return      : A vector of k elements denoting the top k most frequent elements
*/
vector<int> topKFrequent(int arr[], int n, int k) {

    // Initialize the required local variables
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> mp;
    vector<int> result;
    
    // Traverse the array to count the frequencies
    for(int i = 0; i < n; i++)
        mp[arr[i]]++;
    
    // Put the frequency element pair in a heap
    for(auto &it : mp)
        pq.push({it.second, it.first});
    
    // Extract the top k most frequent elements
    while(k--) {
        result.push_back(pq.top().second);
        pq.pop();
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
    int n, k;
    input >> n >> k;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        input >> arr[i];

    // Close the input file
    input.close();

    // Call the subroutine to find the top k most frequent elements
    vector<int> result = topKFrequent(arr, n, k);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < result.size(); i++)
        (i == 0) ? (output << result[i]) : (output << ' ' << result[i]);
    
    // Delete the array, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}