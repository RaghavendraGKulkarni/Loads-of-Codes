// Include the required header files
#include<iostream>
#include<fstream>
#include<array>
#include<vector>
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
Name        : countComponentsUsingBFS()
Description : Computes the number of components in the graph using Breadth First Search
Arguments   : The graph
Return      : The total number of connected components
*/
int countComponentsUsingBFS(graph g) {
    
    // Declare and initialize the required local variables
    queue<int> next;
    vector<bool> visited(g.v + 1, false);
    int components = 0;

    // Start the BFS from vertex 1
    for(int i = 1; i <= g.v; i++) {
        
        // Skip visited vertex
        if(visited[i])
            continue;
        
        // Count a component
        components++;

        // Start traversal from unvisited vertex
        next.push(i);
        while(!next.empty()) {
            auto node = next.front();
            next.pop();
            if(visited[node])
                continue;
            visited[node] = true;
            for(auto &neighbor : g.vertices[node].neighbors)
                if(!visited[neighbor])
                    next.push(neighbor);
        }
    }

    // Return the number of components
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
    g.vertices.resize(g.v + 1);
    for(int i = 1; i <= g.v; i++)
        g.vertices[i].degree = 0;
    for(int i = 0; i < e; i++) {
        input >> u >> v;
        g.vertices[u].neighbors.push_back(v);
        g.vertices[u].degree++;
        if(type == 'U') {
            g.vertices[v].neighbors.push_back(u);
            g.vertices[v].degree++;
        }
    }

    // Close the input file
    input.close();

    // Call the subroutine to compute the number of components
    int components = countComponentsUsingBFS(g);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << components;

    // Close the output file and return
    output.close();
    return 0;
}