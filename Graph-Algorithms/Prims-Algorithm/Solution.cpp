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
    array<int, 2> *neighbors;
} vertex;
typedef struct graph {
    int v;
    vertex *vertices;
} graph;

/*
Name        : prims()
Description : Computes the minimum spanning tree from the source vertex of the graph
Arguments   : The graph, the source vertex and the array to store the tree edges
Return      : The total weight of the minimum spanning tree
*/
int prims(graph g, int s, array<int, 3> result[]) {
    
    // Declare and initialize the required local variables
    int mst = 0, top = 0;
    bool *visited = new bool[g.v + 1];
    array<int, 3> node;
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> next;
    for(int i = 1; i <= g.v; i++)
        visited[i] = false;

    // Initialize the priority queue
    next.push({0, s, s});

    // Loop while queue has elements
    while(!next.empty()) {

        // Pop the next nearest vertex and relax the edge
        node = next.top();
        next.pop();
        if(visited[node[1]])
            continue;
        visited[node[1]] = true;
        if(node[1] != node[2]) {
            result[top++] = {node[2], node[1], node[0]};
            mst += node[0];
        }

        // Update the distance to neighbors of this vertex
        for(int i = 0; i < g.vertices[node[1]].degree; i++)
            if(!visited[g.vertices[node[1]].neighbors[i][0]])
                next.push({g.vertices[node[1]].neighbors[i][1], g.vertices[node[1]].neighbors[i][0], node[1]});
    }

    // Free the arrays and return the total weight
    delete[] visited;
    return mst;
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
    int e, u, v, w, s, mst;
    char type;
    graph g;
    
    // Read the graph vertices, edges and the source vertex
    input >> g.v >> e >> type;
    g.vertices = new vertex[g.v + 1];
    for(int i = 1; i <= g.v; i++) {
        g.vertices[i].degree = 0;
        g.vertices[i].neighbors = (array<int, 2>*)calloc(1, sizeof(array<int, 2>));
    }
    for(int i = 0; i < e; i++) {
        input >> u >> v >> w;
        g.vertices[u].neighbors = (array<int, 2>*)realloc(g.vertices[u].neighbors, (g.vertices[u].degree + 1)*sizeof(array<int, 2>));
        g.vertices[u].neighbors[g.vertices[u].degree] = {v, w};
        g.vertices[u].degree++;
        if(type == 'U') {
            g.vertices[v].neighbors = (array<int, 2>*)realloc(g.vertices[v].neighbors, (g.vertices[v].degree + 1)*sizeof(array<int, 2>));
            g.vertices[v].neighbors[g.vertices[v].degree] = {u, w};
            g.vertices[v].degree++;
        }
    }
    input >> s;

    // Close the input file
    input.close();

    array<int, 3> *result = new array<int, 3>[g.v - 1];

    // Call the subroutine to compute the minimum spanning tree from the source vertex
    mst = prims(g, s, result);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < g.v - 1; i++)
        output << "Edge (" << result[i][0] << ", " << result[i][1] << ") of weight " << result[i][2] << endl; 
    output << mst;

    // Delete the arrays, close the output file and return
    for(int i = 1; i <= g.v; i++)
        free(g.vertices[i].neighbors);
    delete[] g.vertices;
    delete[] result;
    output.close();
    return 0;
}