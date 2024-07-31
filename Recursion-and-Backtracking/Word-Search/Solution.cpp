// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
#include<array>
using namespace std;

/*
Name        : search()
Description : Searches for a letter in the current position recursively
Arguments   : The square grid, the word to be searched, the index of the current letter in search
                the indices of the current position of search, a vector of pairs to store the indices
                and an integer denoting the direction, in that order
Return      : True, if the word is found and False otherwise
*/
bool search(vector<vector<char>>& grid, string word, int index, int i, int j, vector<array<int, 2>> &indices, int dir) {
    
    // Detect if the word is fully found
    if(index == word.size())
        return true;
    
    // Detect the grid end
    if(i < 0 || i == grid.size())
        return false;
    if(j < 0 || j == grid[i].size())
        return false;
    
    // Look for the current letter at the current position
    if(grid[i][j] != word[index])
        return false;
    
    // Look for next letter in the intended direction
    indices.push_back({i, j});
    bool result;
    switch(dir) {
        case 1:result = search(grid, word, index + 1, i - 1, j, indices, dir);
                break;
        case 2:result = search(grid, word, index + 1, i - 1, j + 1, indices, dir);
                break;
        case 3:result = search(grid, word, index + 1, i, j + 1, indices, dir);
                break;
        case 4:result = search(grid, word, index + 1, i + 1, j + 1, indices, dir);
                break;
        case 5:result = search(grid, word, index + 1, i + 1, j, indices, dir);
                break;
        case 6:result = search(grid, word, index + 1, i + 1, j - 1, indices, dir);
                break;
        case 7:result = search(grid, word, index + 1, i, j - 1, indices, dir);
                break;
        case 8:result = search(grid, word, index + 1, i - 1, j - 1, indices, dir);
                break;
        default:
                break;
    }
    return result;
}

/*
Name        : wordSearch()
Description : Searches for a word in the square grid
Arguments   : The square grid and the word to be searched, in that order
Return      : A vector of pairs denoting the indices of the letters of the word
*/
vector<array<int, 2>> wordSearch(vector<vector<char>> grid, string word) {
    
    // Initialize the required local variables
    vector<array<int, 2>> indices;

    // Loop the grid to search for the word
    for(int i = 0; i < grid.size(); i++)
        for(int j = 0; j < grid[i].size(); j++)
            for(int k = 1; k <= 8; k++) {
                indices.resize(0);
                if(search(grid, word, 0, i, j, indices, k))
                    return indices;
            }
    return indices;
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
    string word;
    bool change;
    input >> n >> word;
    vector<vector<char>> grid(n, vector<char> (n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            input >> grid[i][j];

    // Close the input file
    input.close();

    // Call the subroutine to search for the word
    vector<array<int, 2>> indices = wordSearch(grid, word);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the result to the output file
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            change = true;
            for(auto &index : indices)
                if(index[0] == i && index[1] == j)
                    change = false;
            if(change)
                grid[i][j] = '*';
        }
    }
    for(int i = 0; i < n; i++) {
        if(i > 0)
            output << endl;
        for(int j = 0; j < n; j++)
            (j == 0) ? (output << grid[i][j]) : (output << ' ' << grid[i][j]);
    }
    
    // Close the output file and return
    output.close();
    return 0;
}