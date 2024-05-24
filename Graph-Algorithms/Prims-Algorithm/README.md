# Prim's Algorithm
## Description:
### Given a graph of n vertices and e edges, the program finds a minimum spanning tree from a source vertex s to using the Prim's Algorithm.
## Input Format:
* The first line should contain two positive integers n and e denoting the number of vertices and edges in the graph followed a character 'D' or 'U' denoting whether the graph is Directed or Undirected.
* The next e lines each should contain three space separated positive integers denoting the from, to and weight of the edge. The vertices from and to must be in the range [1, n].
* The last line should contain a single integer in the inclusive range [1, n] denoting the source vertex
## Output Format:
* The first n - 1 output lines will contain one tree edge each added to the minimum spanning tree.
* The last line will contain the total weight of the minimum spanning tree.
## Time Complexity: 
* O(n log n)
## Space Complexity: 
* O(n)