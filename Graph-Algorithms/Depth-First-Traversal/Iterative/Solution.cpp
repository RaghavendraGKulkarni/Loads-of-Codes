// Include the required header files
#include<iostream>
#include<fstream>
#include<stdbool.h>
#include<vector>
#include<stack>
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
Name        : iterativeDFS()
Description : Performs Depth First Traversal on a graph from a source vertex iteratively
Arguments   : The graph and the source vertex, in that order
Return      : A vector denoting the traversal
*/
vector<int> iterativeDFS(graph g, int s) {
    
    // Declare and initialize the required local variables
    vector<int> traversal;
    bool *visited = new bool[g.v + 1];
    for(int i = 1; i <= g.v; i++)
        visited[i] = false;
    stack<int> next;
    next.push(s);

    // Perform DFS until the stack is empty
    while(!next.empty()) {
        auto node = next.top();
        next.pop();
        if(visited[node])
            continue;
        visited[node] = true;
        traversal.push_back(node);
        for(int i = g.vertices[node].degree - 1; i >= 0; i--)
            if(!visited[g.vertices[node].neighbors[i]])
                next.push(g.vertices[node].neighbors[i]);
    }

    // Delete the array and return the traversal
    delete[] visited;
    return traversal;
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
    int e, u, v, s;
    char type;
    graph g;
    
    // Read the graph vertices, edges and the source vertex
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
    input >> s;

    // Close the input file
    input.close();

    // Call the subroutine to compute the depth first traversal from source vertex
    vector<int> result = iterativeDFS(g, s);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < result.size(); i++)
        (i == 0) ? (output << result[i]) : (output << ' ' << result[i]);

    // Close the output file and return
    output.close();
    return 0;
}