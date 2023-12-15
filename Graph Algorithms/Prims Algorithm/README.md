# Prims Algorithm
## Description:
### Given a graph of n vertices and e edges, the program finds the minimum spanning tree from a source s using the Prim's Algorithm.
## Input Format:
* The first line should contain two positive integers n and e denoting the number of vertices and edges in the graph followed a character 'D' or 'U' denoting whether the graph is Directed or Undirected.
* The next e lines each should contain three space separated positive integers denoting the from, to and weight of the edge. The vertices from and to must be in the range [1, n].
## Output Format:
* The first n - 1 output lines each, will contain the edges of the graph used in the tree in the form of two separated integers, from and to.
* The last line will contain a single integer denoting the total weight of the minimum spanning tree.
## Time Complexity: 
* O(n log n)
## Space Complexity: 
* O(n)