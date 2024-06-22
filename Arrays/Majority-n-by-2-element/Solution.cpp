// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : majorityBy2()
Description : Finds the element occuring more than n/2 times, if it exists
Arguments   : An array of integers, a positive integer denoting the size of the array and a variable to store the majority element, in that order
Return      : True, if majority element exists and False otherwise
*/
bool majorityBy2(int arr[], int n, int &majority) {
    
    // Initialize the local variables
    int count = 1;
    majority = arr[0];
    
    // Traverse every element
    for(int i = 1; i < n; i++) {

        // If current element is majority element, increment count
        if(arr[i] == majority)
            count++;
        
        // If not, decrease the count
        else
            count--;
        
        // If count becomes 0, set the current element as majority
        if(count == 0) {
            count = 1;
            majority = arr[i];
        }
    }

    // Re-check if the majority element occurs for more than n/2 times
    count = 0;
    for(int i = 0; i < n; i++)
        if(arr[i] == majority)
            count++;

    // Return the condition truth value
    return (count >= int(n/2) + 1);
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
    int n, majority;
    input >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        input >> arr[i];

    // Close the input file
    input.close();

    // Call the subroutine to find the majority element
    bool found = majorityBy2(arr, n, majority);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    (found) ? (output << majority) : (output << "None");
    
    // Delete the array, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}