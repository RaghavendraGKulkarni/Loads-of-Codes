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
    vector<array<int, 3>> edges;
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
Name        : kruskals()
Description : Computes the minimum spanning tree of the graph
Arguments   : The graph and the array to store the tree edges, in that order
Return      : The total weight of the minimum spanning tree
*/
int kruskals(graph g, array<int, 3> result[]) {
    
    // Declare and initialize the required local variables
    int mst = 0, top = 0, edges = 0, index = 0;
    unionFind uf(g.v + 1);

    // Sort the edges according to weight
    sort(g.edges.begin(), g.edges.end(), [](const array<int, 3>& a, const array<int, 3>& b) {
        if(a[2] < b[2])
            return true;
        if(a[2] > b[2])
            return false;
        if(a[0] < b[0])
            return true;
        if(a[0] > b[0])
            return false;
        return a[1] < b[1];
    });

    // Loop while tree has less than n - 1 edges
    while(edges < g.v - 1) {

        // Take the next smallest edge
        auto &edge = g.edges[index];

        // Check if the edge points belong to the same component
        if(uf.merge(edge[0], edge[1])) {
            result[top++] = edge;
            mst += edge[2];
            edges++;
        }

        // Increment index
        index++;
    }

    // Return the total weight
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
    int e, u, v, w, mst;
    char type;
    graph g;
    
    // Read the graph vertices and edges
    input >> g.v >> e >> type;
    for(int i = 0; i < e; i++) {
        input >> u >> v >> w;
        g.edges.push_back({u, v, w});
        if(type == 'U')
            g.edges.push_back({v, u, w});
    }

    // Close the input file
    input.close();

    array<int, 3> *result = new array<int, 3>[g.v - 1];

    // Call the subroutine to compute the minimum spanning tree
    mst = kruskals(g, result);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < g.v - 1; i++)
        output << "Edge (" << result[i][0] << ", " << result[i][1] << ") of weight " << result[i][2] << endl; 
    output << mst;

    // Delete the arrays, close the output file and return
    delete[] result;
    output.close();
    return 0;
}