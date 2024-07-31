// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : move()
Description : Moves a part of disks from source tower to destination tower
Arguments   : A vector of pairs to store the moves, 
                an integer denoting number of disks, 
                three integers denoting the source tower, destination tower and the auxiliary tower,
                in that order
Return      : None
*/
void move(vector<pair<int, int>>& moves, int n, int left, int right, int mid) {
    
    // Handle the base case of one disk
    if(n == 1) {
        moves.push_back({left, right});
        return;
    }

    // Move n - 1 disks from left to mid
    move(moves, n - 1, left, mid, right);

    // Move the nth disk from left to right
    moves.push_back({left, right});

    // Move n - 1 disks from mid to right
    move(moves, n - 1, mid, right, left);

    // Return
    return;
}

/*
Name        : generateMoves()
Description : Lists all the moves required to shift the disks
Arguments   : The positive integer n, denoting the number of disks
Return      : A vector of pairs to denoting the moves
*/
vector<pair<int, int>> generateMoves(int n) {
    
    // Declare a vector to store the combinations
    vector<pair<int, int>> moves;

    // Call the recursive subroutine to generate the combinations
    move(moves, n, 1, 3, 2);

    // Return the combinations
    return moves;
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

    // Call the subroutine to generate all combinations of valid parentheses
    vector<pair<int, int>> result = generateMoves(n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the result to the output file
    for(int i = 0; i < result.size(); i++)
        (i == 0) ? (output << result[i].first << ' ' << result[i].second) : (output << '\n' << result[i].first << ' ' << result[i].second);
    
    // Close the output file and return
    output.close();
    return 0;
}