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
Name        : topologicalSortUsingKahn()
Description : Computes a topological sort of the graph using Kahn's Algorithm
Arguments   : The graph
Return      : A vector denoting the topological sorting
*/
vector<int> topologicalSortUsingKahn(graph g) {

    // Declare the required local variables
    vector<int> indegree(g.v + 1, 0);
    queue<int> q;
    vector<int> order;

    // Initialize the queue
    for(int i = 1; i <= g.v; i++)
        for(auto it : g.vertices[i].neighbors)
            indegree[it]++;
    for(int i = 1; i <= g.v; i++)
        if(indegree[i] == 0)
            q.push(i);
    
    // Loop till the queue is empty
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);
        for (auto it : g.vertices[node].neighbors) {
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
        }
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
    vector<int> result = topologicalSortUsingKahn(g);

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