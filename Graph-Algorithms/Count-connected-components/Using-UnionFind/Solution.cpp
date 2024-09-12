// Include the required header files
#include<iostream>
#include<fstream>
#include<array>
#include<vector>
using namespace std;

// Declare the required data types
typedef struct graph {
    int v;
    vector<array<int, 2>> edges;
} graph;
class unionFind {

    // Declare the private variables
    private:
        vector<int> parent;
        vector<int> size;
    
    // Define the public methods
    public:

        // Define the class constructor
        unionFind(int n) {
            parent.resize(n);
            size.resize(n);
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
        bool merge(int u, int v) {
            int u1 = find(u), v1 = find(v);
            if(u1 == v1)
                return false;
            if(size[u1] > size[v1]) {
                parent[v1] = u1;
                size[u1] += size[v1];
            }
            else {
                parent[u1] = v1;
                size[v1] += size[u1];
            }
            return true;
        }
};

/*
Name        : countComponentsUsingUnionFind()
Description : Computes the number of components in the graph using union find
Arguments   : The graph
Return      : The total number of connected components
*/
int countComponentsUsingUnionFind(graph g) {
    
    // Declare and initialize the required local variables
    unionFind uf(g.v + 1);
    int components = g.v;

    // For each edge in the graph
    for(auto &edge : g.edges) {

        // Check if the edge points belong to the same component
        if(uf.merge(edge[0], edge[1]))
            components--;
    }

    // Return the number of connected components
    return components;
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

    // Declare the required local variables
    int e, u, v;
    char type;
    graph g;
    
    // Read the graph vertices and edges
    input >> g.v >> e >> type;
    for(int i = 0; i < e; i++) {
        input >> u >> v;
        g.edges.push_back({u, v});
        if(type == 'U')
            g.edges.push_back({v, u});
    }

    // Close the input file
    input.close();

    // Call the subroutine to compute the number of components
    int components = countComponentsUsingUnionFind(g);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << components;

    // Close the output file and return
    output.close();
    return 0;
}