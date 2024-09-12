// Include the required header files
#include<iostream>
#include<fstream>
#include<limits.h>
#include<stdbool.h>
#include<array>
#include<queue>
using namespace std;

// Declare the required data types
typedef struct vertex {
    int degree;
    vector<int> neighbors;
} vertex;
typedef struct graph {
    int v;
    vector<vertex> vertices;
} graph;

/*
Name        : dfs()
Description : Performs Depth First traversal to partition vertex set into two groups
Arguments   : The graph, the source vertex and the calling vertex, the group id and visited array, in that order
Return      : True if partition is possible and False, otherwise
*/
bool dfs(graph g, int src, int parent, int group, vector<int> &visited) {
    
    // Check if vertex is already visited
    if(visited[src] >= 0) {
        if(visited[src] == visited[parent])
            return false;
        return true;
    }

    // Assign group id to vertex and continue DFS to neighbors
    visited[src] = group;
    for(auto &neighbor : g.vertices[src].neighbors) {
        if(neighbor == parent)
            continue;
        if(!dfs(g, neighbor, src, 1 - group, visited))
            return false;
    }

    // Return true
    return true;
}

/*
Name        : isBipartite()
Description : Checks whether the graph is Bipartite or not
Arguments   : The graph
Return      : "Yes" if the graph is bipartite and "No" otherwise
*/
string isBipartite(graph g) {

    // Declare the required local variables
    vector<int> visited(g.v + 1, -1);

    // Start the DFS from every unvisited vertex
    for(int i = 1; i <= g.v; i++) {
        if(visited[i] >= 0)
            continue;
        if(!dfs(g, i, -1, 0, visited))
            return "No";
    }

    // Return Yes
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

    // Declare the required local variables
    int e, u, v;
    graph g;
    
    // Read the graph vertices and edges
    input >> g.v >> e;
    g.vertices.resize(g.v + 1);
    for(int i = 1; i <= g.v; i++)
        g.vertices[i].degree = 0;
    for(int i = 0; i < e; i++) {
        input >> u >> v;
        g.vertices[u].neighbors.push_back(v);
        g.vertices[u].degree++;
        g.vertices[v].neighbors.push_back(u);
        g.vertices[v].degree++;
    }

    // Close the input file
    input.close();

    // Call the subroutine to check for bipartitie
    string result = isBipartite(g);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;

    // Close the output file and return
    output.close();
    return 0;
}