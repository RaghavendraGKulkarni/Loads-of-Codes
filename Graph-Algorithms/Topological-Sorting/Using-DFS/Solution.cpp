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
Description : Performs Depth First traversal to compute the topological sort
Arguments   : The graph, the source vertex, a vector to store topological sort, and visited array, in that order
Return      : None
*/
void dfs(graph g, int src, vector<int> &order, vector<bool> &visited) {
    
    // Mark vertex as visited
    visited[src] = true;

    // Continue DFS on neighbors
	for(auto &neighbor : g.vertices[src].neighbors)
        if(!visited[neighbor])
	        dfs(g, neighbor, order, visited);
        
    // Add this vertex to the topological sort
	order.insert(order.begin(), src);

    // Return
    return;
}

/*
Name        : topologicalSortUsingDFS()
Description : Computes a topological sort of the graph using DFS
Arguments   : The graph
Return      : A vector denoting the topological sorting
*/
vector<int> topologicalSortUsingDFS(graph g) {

    // Declare the required local variables
    vector<bool> visited(g.v + 1, false);
    vector<int> order;

    // Start the DFS from every unvisited vertex
    for(int i = 1; i <= g.v; i++) {
        if(!visited[i])
            dfs(g, i, order, visited);
    }

    // Return the topological sort
    return order;
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
    }

    // Close the input file
    input.close();

    // Call the subroutine to compute Topological Sort
    vector<int> result = topologicalSortUsingDFS(g);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    if(result.size() < g.v)
        output << "None";
    else {
        for(int i = 0; i < result.size(); i++)
            (i == 0) ? (output << result[i]) : (output << ' ' << result[i]);
    }

    // Close the output file and return
    output.close();
    return 0;
}