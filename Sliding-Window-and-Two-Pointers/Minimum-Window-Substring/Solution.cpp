// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : contains()
Description : Checks whether the window contains all the characters of the target string t
Arguments   : The frequency arrays of window and t, in that order
Return      : True, if the window contains all the characters of the target string t and false otherwise
*/
bool contains(int window[26][2], int target[26][2]) {
    
    // Loop through the array to compare the frequencies
    for(int i = 0; i < 26; i++) {
        if(window[i][0] < target[i][0])
            return false;
        if(window[i][1] < target[i][1])
            return false;
    }

    // Return true
    return true;
}

/*
Name        : minWindowSubstring()
Description : Computes the smallest substring of s that contains all the characters of t
Arguments   : The string s and the string t, in that order
Return      : The smallest substring of s
*/
string minWindowSubstring(string s, string t) {
    
    // Declare and initialize the required local variables
    int window[26][2], target[26][2];
    int i = 0, j = -1, length, left, right, minLength = s.size() + 1;
    for(int i = 0; i < 26; i++) {
        target[i][0] = 0;
        target[i][1] = 0;
        window[i][0] = 0;
        window[i][1] = 0;
    }

    // Compute the frequency array for target string t
    for(auto &ch : t) {
        if('A' <= ch && ch <= 'Z')
            target[ch - 'A'][0]++;
        else
            target[ch - 'a'][1]++;
    }

    // Slide the window through s to find the minimum window substring
    while(j + 1 < s.size()) {

        // Add the next letter to the right of the window
        j++;
        if('A' <= s[j] && s[j] <= 'Z')
            window[s[j] - 'A'][0]++;
        else
            window[s[j] - 'a'][1]++;
        
        // Remove letters from left of the window until condition satisfied
        while(contains(window, target)) {
            length = j - i + 1;
            if(length < minLength) {
                left = i;
                right = j;
                minLength = length;
            }
            if('A' <= s[i] && s[i] <= 'Z')
                window[s[i] - 'A'][0]--;
            else
                window[s[i] - 'a'][1]--;
            i++;
        }
    }

    // Return the substring based on the minLength value
    if(minLength == s.size() + 1)
        return "-1";
    return s.substr(left, minLength);
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
    string s, t;
    input >> s >> t;

    // Close the input file
    input.close();

    // Call the subroutine to find the minimum window substring
    string result = minWindowSubstring(s, t);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}