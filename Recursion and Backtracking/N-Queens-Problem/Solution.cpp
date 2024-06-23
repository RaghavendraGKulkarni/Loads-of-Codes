// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : safe()
Description : Checks if two queens at given positions is a safe arrangement or not
Arguments   : Two integers denoting the position of first queen,
                and two integers denoting the position of second queen,
                in that order
Return      : None
*/
bool safe(int x1, int y1, int x2, int y2) {

    // Check for same column
    if(y1 == y2)
        return false;
    
    // Check for diagonal
    if(abs(x1 - x2) == abs(y1 - y2))
        return false;
    
    // Return true on safe arrangement
    return true;
}

/*
Name        : generate()
Description : Builds different arrangements of n Queens such that no two Queens attack each other
Arguments   : An integer denoting the total number of queens,
                an integer denoting the current row to place the queen,
                a vector of size 10 denoting the current arrangement,
                and a vector of vectors to store all the arrangements 
                in that order
Return      : None
*/
void generate(int n, int row, vector<int> &arrangement, vector<vector<int>> &arrangements) {
    
    // Handle the base case
    if(row == n) {
        arrangements.push_back(arrangement);
        return;
    }

    // Check at each place in the current row
    bool place;
    for(int i = 0; i < n; i++) {
        place = true;
        for(int j = 0; j < row; j++)
            if(!safe(row, i, j, arrangement[j]))
                place = false;
        if(place) {
            arrangement.push_back(i);
            generate(n, row + 1, arrangement, arrangements);
            arrangement.pop_back();
        }
    }

    // Return
    return;
}

/*
Name        : generateArrangements()
Description : Computes all possible valid arrangements of the Queens
Arguments   : The positive integer n, denoting the number of queens
Return      : A vector of vectors denoting the arrangements
*/
vector<vector<int>> generateArrangements(int n) {
    
    // Initiliaze the required local variables
    vector<vector<int>> arrangements;
    vector<int> arrangement;

    // Recursive sub-routine to try all possible arrangements
    generate(n, 0, arrangement, arrangements);

    // Return the arrangements
    return arrangements;
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

    // Declare the required local variables and read the input
    int n;
    input >> n;

    // Close the input file
    input.close();

    // Call the subroutine to generate all the valid arrangements
    vector<vector<int>> result = generateArrangements(n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the result to the output file
    if(result.size() == 0)
        output << "There are no arrangements possible";
    else
        output << "There are " << result.size() << " arrangements possible";
    for(int i = 0; i < result.size(); i++) {
        output << endl << endl;
        for(int j = 0; j < n; j++) {
            if(j > 0)
                output << endl;
            for(int k = 0; k < n; k++) {
                char ch;
                ch = (result[i][j] == k) ? 'Q' : '*';
                (k == 0) ? (output << ch) : (output << ' ' << ch);
            }
        }
    }
    
    // Close the output file and return
    output.close();
    return 0;
}