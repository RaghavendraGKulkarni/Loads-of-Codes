// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : vertical()
Description : Checks if a number can be placed in the column
Arguments   : The sudoku board as 9x9 integer array, and the row and column number of the target cell, in that order
Return      : True if the number can be placed and false otherwise
*/
bool vertical(int board[9][9], int l, int m) {
    for(int i = 0; i < 9; i++)
        if(board[i][l] == m)
            return false;
    return true;
}

/*
Name        : horizontal()
Description : Checks if a number can be placed in the row
Arguments   : The sudoku board as 9x9 integer array, and the row and column number of the target cell, in that order
Return      : True if the number can be placed and false otherwise
*/
bool horizontal(int board[9][9], int k, int m) {
    for(int i = 0; i < 9; i++)
        if(board[k][i] == m)
            return false;
    return true;
}

/*
Name        : block()
Description : Checks if a number can be placed in the block
Arguments   : The sudoku board as 9x9 integer array, and the row and column number of the target cell, in that order
Return      : True if the number can be placed and false otherwise
*/
bool block(int board[9][9], int k, int l, int m) {
    int p = 3 * (k / 3), q = 3 * (l / 3);
    for(int i = p; i < p + 3; i++)
        for(int j = q; j < q + 3; j++)
            if(board[i][j] == m)
                return false;
    return true;
}

/*
Name        : place()
Description : Tries placing every possible number at given cell
Arguments   : The sudoku board as 9x9 integer array, and the row and column number of the target cell, in that order
Return      : True if the cell is filled and false otherwise
*/
bool place(int board[9][9], int row, int col) {
    
    // Detect end of the board
    if(row == 8 && col == 9)
        return true;
    
    // Detect end of the row
    if(col == 9) {
        row++;
        col = 0;
    }

    // Check if the cell is already occupied
    if(board[row][col] != 0)
        return place(board,row,col+1);
    
    // Try every number at the cell and proceed
    for(int num = 1; num <= 9; num++) {
        if(horizontal(board, row, num) && vertical(board, col, num) && block(board, row, col, num)) {
            board[row][col] = num;
            if(place(board, row, col+1))
                return true;
        }
        board[row][col] = 0;
    }

    // Return false on unsuccessful attempt
    return false;
}

/*
Name        : solveSudoku()
Description : Solves a 9x9 sudoku using Backtracking
Arguments   : The Sudoku board as 9x9 integer array
Return      : True if the sudoku is solved and false otherwise
*/
bool solveSudoku(int board[9][9]) {
    
    // Try different numbers starting in place of zeros from the first cell
    return place(board, 0, 0);
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
    int board[9][9];
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            input >> board[i][j];

    // Close the input file
    input.close();

    // Call the subroutine to solve the sudoku
    bool result = solveSudoku(board);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the result to the output file
    if(result) {
        for(int i = 0; i < 9; i++) {
            if(i > 0)
                output << endl;
            for(int j = 0; j < 9; j++)
                (j == 0) ? output << board[i][j] : output << ' ' << board[i][j];
        }
    }
    else
        output << "No Solution";
    
    // Close the output file and return
    output.close();
    return 0;
}