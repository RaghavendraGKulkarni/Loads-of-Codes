// Include the required header files
#include<iostream>
#include<fstream>
#include<unordered_map>
using namespace std;

/*
Name        : countAtMostK()
Description : Computes the number of subarrays with atmost k distinct elements
Arguments   : The array and two positive integer denoting the size of the array and k, in that order
Return      : The number of subarrays with atmost k distinct elements
*/
int countAtMostK(int arr[], int n, int k) {
    
    // Declare the required local variables
    unordered_map<int, int> mp;
    int i = 0, j = 0, count = 0;

    // Slide the window to count the subarrays
    while(j < n) {

        // Include the new element in the window
        mp[arr[j]]++;

        // Shrink the window until it has more than k distinct elements
        while(i <= j && mp.size() > k) {
            mp[arr[i]]--;
            if(mp[arr[i]] == 0)
                mp.erase(arr[i]);
            i++;
        }

        // Count the total subarrays
        count += (j - i + 1);
        j++;
    }

    // Return the count
    return count;
}

/*
Name        : countKDistinct()
Description : Computes the number of subarrays with exactly k distinct elements
Arguments   : The array and two positive integer denoting the size of the array and k, in that order
Return      : The number of subarrays with exactly k distinct elements
*/
int countKDistinct(int arr[], int n, int k) {
    
    // Return the number of subarrays with exactly k distinct elements
    return countAtMostK(arr, n, k) - countAtMostK(arr, n, k - 1);
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

    // Call the subroutine to find the number of subarrays
    int result = countKDistinct(arr, n, k);

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