// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : checkAnagram()
Description : Checks if two strings are Anagram of each other
Arguments   : The strings to be checked
Return      : "Yes" if the strings are Anagram and "No" otherwise
*/
string checkAnagram(string a, string b) {
    
    // Initialize the required local variables
    int frequencyA[26] = {0}, frequencyB[26] = {0};

    // Count for occurrence of each letter in the both the strings
    for(auto &ch : a)
        frequencyA[ch - 'a']++;
    for(auto &ch : b)
        frequencyB[ch - 'a']++;

    // Compare the occurrences of each letter in the English alphabet
    for(int i = 0; i < 26; i++)
        if(frequencyA[i] != frequencyB[i])
            return "No";
    
    // Return Yes if strings are Anagram of each other
    return "Yes";
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
    string a, b;
    input >> a >> b;

    // Close the input file
    input.close();

    // Call the subroutine to check if the string is a Pangram
    string result = checkAnagram(a, b);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}