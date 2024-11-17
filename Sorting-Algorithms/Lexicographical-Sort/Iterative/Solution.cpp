// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : iterativeLexicographicalSort()
Description : Sorts the range [1, n] in lexicographical order, iteratively
Arguments   : A positive integer n denoting the range end point
Return      : A vector denoting the sorted array
*/
vector<int> iterativeLexicographicalSort(int n) {
    
    // Declare the required local variables
    vector<int> result;
    int number = 1;

    // Run the loop to store the numbers in lexicographical order
    for(int i = 0; i < n; i++) {
        result.push_back(number);
        if(number * 10 <= n)
            number *= 10;
        else {
            if(number == n)
                number /= 10;
            number++;
            while(number % 10 == 0)
                number /= 10;
        }
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
    int n;
    input >> n;

    // Close the input file
    input.close();

    // Call the subroutine to print the array
    vector<int> result = iterativeLexicographicalSort(n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < n; i++)
        (i == 0) ? (output << result[i]) : (output << ' ' << result[i]);
    
    // Close the output file and return
    output.close();
    return 0;
}