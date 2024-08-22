// Include the required header files
#include<iostream>
#include<fstream>
#include<stdbool.h>
#include<vector>
#include<stack>
using namespace std;

// Declare the required union find data structure
class unionFind {

    // Declare the private variables
    private:
        vector<int> parent;
        vector<int> size;
        int components;
    
    // Define the public methods
    public:

        // Define the class constructor
        unionFind(int n) {
            parent.resize(n);
            size.resize(n);
            components = n;
            for(int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        // Define the find method
        int find(int u) {
            if(parent[u] != u)
                parent[u] = find(parent[u]);
            return parent[u];
        }

        // Define the merge method
        void merge(int u, int v) {
            int u1 = find(u), v1 = find(v);
            if(u1 == v1)
                return;
            if(size[u1] > size[v1]) {
                parent[v1] = u1;
                size[u1] += size[v1];
            }
            else {
                parent[u1] = v1;
                size[v1] += size[u1];
            }
            components--;
            return;
        }

        // Define the count components method
        int countComp() {
            return components;
        }
};

/*
Name        : countIslands()
Description : Counts the number of islands in a binary grid
Arguments   : A 2d vector denoting the binary grid
Return      : An integer denoting the number of islands in the grid
*/
int countIslands(vector<vector<int>> grid) {
    
    // Declare and initialize the required local variables
    int m = grid.size(), n = grid[0].size(), zeros = 0;
    unionFind uf(m*n);

    // Traverse through the grid to merge the lands into islands
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 0)
                zeros++;
            else {
                if(j + 1 < n && grid[i][j + 1] == 1)
                    uf.merge(i*n + j, i*n + j + 1);
                if(i + 1 < m && grid[i + 1][j] == 1)
                    uf.merge(i*n + j, (i + 1)*n + j);
            }
        }
    }

    // Return the number of islands
    return uf.countComp() - zeros;
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
    int m, n;
    input >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            input >> grid[i][j];

    // Close the input file
    input.close();

    // Call the subroutine to compute the number of islands
    int result = countIslands(grid);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;

    // Close the output file and return
    output.close();
    return 0;
}