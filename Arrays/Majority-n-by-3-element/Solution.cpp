// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
#include<limits>
using namespace std;

/*
Name        : majorityBy3()
Description : Finds the elements occuring more than n/3 times, if they exist
Arguments   : An array of integers and a positive integer denoting the size of the array, in that order
Return      : A vector denoting the majority elements
*/
vector<int> majorityBy3(int arr[], int n) {
    
    // Initialize the local variables
    int a = INT_MIN, countA = 0, b = INT_MIN, countB = 0;
    vector<int> result;
    
    // Traverse every element
    for(int i = 0; i < n; i++) {

        // If a is not found and current element is not b, set a to current element and increment countA
        if(countA == 0 && b != arr[i]) {
            countA++;
            a = arr[i];
        }
        
        // Else if b is not found and current element is not a, set b to current element and increment countB
        else if(countB == 0 && a != arr[i]) {
            countB++;
            b = arr[i];
        }
        
        // Else if a is found and current element is equal to a, increment countA
        else if(a == arr[i])
            countA++;
        
        // Else if b is found and current element is equal to b, increment countB
        else if(b == arr[i])
            countB++;
        
        // Else, decrement both countA and countB
        else {
            countA--;
            countB--;
        }
    }

    // Re-check if the majority elements occur for more than n/3 times
    countA = 0;
    countB = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == a)
            countA++;
        else if(arr[i] == b)
            countB++;
    }

    // Add the valid majority elements to the result
    if(countA >= int(n/3) + 1)
        result.push_back(a);
    if(countB >= int(n/3) + 1)
        result.push_back(b);

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
    int n;
    input >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        input >> arr[i];

    // Close the input file
    input.close();

    // Call the subroutine to find the majority element(s)
    vector<int> majority = majorityBy3(arr, n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    switch(majority.size()) {
        case 1:output << majority[0];
                break;
        case 2:output << majority[0] << ' ' << majority[1];
                break;
        default:output << "None";
                break;
    }
    
    // Delete the array, close the output file and return
    delete[] arr;
    output.close();
    return 0;
}