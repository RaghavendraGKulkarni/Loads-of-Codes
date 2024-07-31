// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : countSubstrings()
Description : Computes the number of substrings with all three characters in it
Arguments   : The string s
Return      : The number of substrings with all three characters in it
*/
int countSubstrings(string str) {
    
    // Handle the base case of null string
    if(str.size() == 0)
        return 0;
    
    // Initialize the required local variables
    int a = 0, b = 0, c = 0, i = 0, j = 0, count = 0;
    
    // Initialize the window with one character
    if(str[0] == 'a')
        a++;
    else if(str[0] == 'b')
        b++;
    else
        c++;
    
    // Slide the window to count the number of substrings 
    while(j + 1 < str.size()) {

        // Increment the counter according to next incoming character
        if(str[j + 1] == 'a')
            a++;
        else if(str[j + 1] == 'b')
            b++;
        else
            c++;
        j++;

        // Count all substrings and shrink the window until one is missing
        while(a > 0 && b > 0 && c > 0) {
            count += (str.size() - j);
            if(str[i] == 'a')
                a--;
            else if(str[i] == 'b')
                b--;
            else
                c--;
            i++;
        }
    }

    // Return the count
    return count;
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
    string str;
    getline(input, str);

    // Close the input file
    input.close();

    // Call the subroutine to find the number of substrings
    int result = countSubstrings(str);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}