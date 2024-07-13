// Include the required header files
#include<iostream>
#include<fstream>
#include<array>
#include<vector>
#include<algorithm>
using namespace std;

// Declare the required data types
typedef struct graph {
    int v;
    vector<array<int, 2>> edges;
} graph;

/*
Name        : find()
Description : Computes the root of the component to which the given node belongs
Arguments   : The array of the root nodes and the vertex whose root is to be found, in that order
Return      : The root of the component to which the node belongs to
*/
int find(int root[], int u) {
    if(root[u] != u)
        root[u] = find(root, root[u]);
    return root[u];
}

/*
Name        : merge()
Description : Merges the components of two given nodes
Arguments   : The array of the root nodes, the array of size nodes and the vertices to be merged, in that order
Return      : True if they are successfully merged and False if they were already merged
*/
bool merge(int root[], int size[], int u, int v) {
    
    // Find the root nodes of the given nodes
    int u1 = find(root, u), v1 = find(root, v);

    // Check if they belong to the same component
    if(u1 == v1)
        return false;
    
    // Combine the smaller component into the larger component
    if(size[u1] < size[v1])
        swap(u1, v1);
    root[v1] = u1;
    size[u1] += size[v1];
    return true;
}

/*
Name        : countComponents()
Description : Computes the number of components in the graph
Arguments   : The graph and the array to store the tree edges, in that order
Return      : The total weight of the minimum spanning tree
*/
int countComponents(graph g) {
    
    // Declare and initialize the required local variables
    int components = g.v;
    int *root = new int[g.v + 1], *size = new int[g.v + 1];

    // Initialize the Union Find
    for(int i = 1; i <= g.v; i++) {
        root[i] = i;
        size[i] = 1;
    }

    // For each edge in the graph
    for(auto &edge : g.edges) {

        // Check if the edge points belong to the same component
        if(merge(root, size, edge[0], edge[1]))
            components--;
    }

    // Free the arrays and return the total weight
    delete[] root;
    delete[] size;
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
    int components = countComponents(g);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << components;

    // Close the output file and return
    output.close();
    return 0;
}