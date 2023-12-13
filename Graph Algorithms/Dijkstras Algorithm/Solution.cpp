// Include the required header files
#include<iostream>
#include<fstream>
#include<limits.h>
#include<stdbool.h>
#include<array>
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
typedef struct path {
    int distance;
    string path;
} path;

/*
Name        : push()
Description : Pushes an element into a min-heap and heapifies it
Arguments   : The heap, the size of the heap and the element to be pushed, in that order
Return      : None
*/
void push(array<int, 3> next[], int *size, array<int, 3> node) {
    
    // Declare the required local variables
    int j = (*size) - 1, k;
    array<int, 3> temp;

    // Append the new element to the heap
    next = (array<int, 3>*)realloc(next, ((*size) + 1)*sizeof(array<int, 3>));
    next[(*size)] = node;
    (*size)++;

    // Push the element upwards to its appropriate position
    while(j > 0) {
        k = (j - 1)/2;
        if(next[j][0] < next[k][0]) {
            temp = next[j];
            next[j] = next[k];
            next[k] = temp;
        }
        else
            break;
    }
    return;
}

/*
Name        : pop()
Description : Pops the minimum element from min-heap and heapifies it
Arguments   : The heap and the size of the heap, in that order
Return      : The minimum element
*/
array<int, 3> pop(array<int, 3> next[], int *size) {
    
    // Declare the required local variables
    int j = 0, k;
    array<int, 3> top = next[0], temp;
    
    // Swap root with last element and delete it
    temp = next[0];
    next[0] = next[(*size) - 1];
    next[(*size) - 1] = temp;
    (*size)--;

    // Push the new root downwards to its appropriate position
    while(2*j + 1 < (*size)) {
        k = 2*j + 1;
        if(k + 1 < (*size) && next[k][0] > next[k + 1][0])
            k++;
        if(next[j][0] < next[k][0])
            break;
        temp = next[j];
        next[j] = next[k];
        next[k] = temp;
        j = k;
    }

    // Return the minimum element
    return top;
}

/*
Name        : trace()
Description : Traces the path from the source to any destination vertex, recursively backwards
Arguments   : The predecessor array and the destination vertex
Return      : The path in a string
*/
string trace(int pred[], int k) {

    // Check for the base case
    if(pred[k] == k)
        return to_string(k);
    
    // Construct the path and return it
    return trace(pred, pred[k]) + " -> " + to_string(k);
}

/*
Name        : dijkstra()
Description : Computes the shortest path from the source to every vertex of the graph
Arguments   : The graph, the source vertex and the array to store the paths
Return      : None
*/
void dijkstra(graph g, int s, path result[]) {
    
    // Declare and initialize the required local variables
    int size = 0, *dist = new int[g.v + 1], *pred = new int[g.v + 1];
    bool *visited = new bool[g.v + 1];
    array<int, 3> *next, node;
    next = (array<int, 3>*)calloc(1, sizeof(array<int, 3>));
    for(int i = 1; i <= g.v; i++) {
        dist[i] = INT_MAX;
        pred[i] = s;
        visited[i] = false;
    }

    // Initialize the priority queue
    push(next, &size, {0, s, s});

    // Loop while queue has elements
    while(size > 0) {

        // Pop the next nearest vertex and relax the edge
        node = pop(next, &size);
        if(visited[node[1]])
            continue;
        visited[node[1]] = true;
        dist[node[1]] = node[0];
        pred[node[1]] = node[2];

        // Update the distance to neighbors of this vertex
        for(int i = 0; i < g.vertices[node[1]].degree; i++)
            if(!visited[g.vertices[node[1]].neighbors[i][0]])
                push(next, &size, {node[0] + g.vertices[node[1]].neighbors[i][1], g.vertices[node[1]].neighbors[i][0], node[1]});
    }

    // Compute the path to every vertex using the predecessor array
    for(int i = 1; i <= g.v; i++) {
        result[i].distance = (dist[i] == INT_MAX) ? -1 : dist[i];
        result[i].path = (dist[i] == INT_MAX) ? "" : trace(pred, i);
    }

    // Free the arrays and return
    delete[] dist;
    delete[] pred;
    delete[] visited;
    return;
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
    int e, u, v, w, s;
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

    path *result = new path[g.v + 1];

    // Call the subroutine to compute the shortest path from source to every vertex
    dijkstra(g, s, result);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the file
    for(int i = 1; i <= g.v; i++) {
        if(i == s)
            continue;
        if(i > 1)
            output << endl;
        if(result[i].distance == -1)
            output << "No path to " << i;
        else
            output << "Shortest distance to " << i << " is " << result[i].distance << " via " << result[i].path;
    }

    // Delete the array and close the file
    for(int i = 1; i <= g.v; i++)
        free(g.vertices[i].neighbors);
    delete[] g.vertices;
    delete[] result;
    output.close();
    return 0;
}