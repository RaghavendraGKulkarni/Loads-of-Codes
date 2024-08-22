// Include the required header files
#include<iostream>
#include<fstream>
#include<unordered_map>
using namespace std;

/*
Name        : convert()
Description : Recursively converts a number to its word form
Arguments   : An integer denoting the number to be converted and the mapping, in that order
Return      : A string denoting the word form of the integer
*/
string convert(int num, unordered_map<int, string> mp) {

    // Handle the base case of number below 20
    if(num < 20)
        return mp[num];

    // Handle the numbers in the range [20, 99]
    if(num < 100) {

        // Handle the multiples of 10
        if(num % 10 == 0)
            return mp[num];
        
        // Handle the non-multiples of 10
        else
            return mp[(num / 10) * 10] + " " +  mp[num % 10];
    }

    // Handle the numbers in the range [100, 999]
    if(num < 1000) {
        string a = mp[num/100] + " Hundred";
        string b = convert(num % 100, mp);
        if(b != "")
            a += (" " + b);
        return a;
    }

    // Handle the numbers in the range [1000, 999999]
    if(num < 1000000) {
        string a = convert(num/1000, mp) + " Thousand";
        string b = convert(num % 1000, mp);
        if(b != "")
            a += (" " + b);
        return a;
    }

    // Handle the numbers in the range [1000000, 999999999]
    if(num < 1000000000) {
        string a = convert(num/1000000, mp) + " Million";
        string b = convert(num % 1000000, mp);
        if(b != "")
            a += (" " + b);
        return a;
    }

    // Handle the numbers above 1000000000
    string a = convert(num/1000000000, mp) + " Billion";
    string b = convert(num % 1000000000, mp);
    if(b != "")
        a += (" " + b);
    return a;
}

/*
Name        : toWords()
Description : Converts a number to its word form
Arguments   : An integer denoting the number to be converted
Return      : A string denoting the word form of the integer
*/
string toWords(int num) {
    
    // Handle the base case of zero
    if(num == 0)
        return "Zero";
    
    // Initialize the mapping
    unordered_map<int, string> mp = {{0, ""}, {1, "One"}, {2, "Two"}, {3, "Three"},
    {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"},
    {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"},
    {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"},
    {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"},
    {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}};
    
    // Convert and return the number
    return convert(num, mp);
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
    int number;
    input >> number;

    // Close the input file
    input.close();

    // Call the subroutine to convert the integer to words
    string result = toWords(number);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}