# Dijkstra's Algorithm
## Description:
### Given a weighted graph of n vertices and e edges, the program finds the shortest path from a source s to every other vertex using the Dijkstra's Algorithm
## Input Format:
* The first line should contain two positive integers n and e denoting the number of vertices and edges in the graph followed a character 'D' or 'U' denoting whether the graph is Directed or Undirected
* The next e lines each should contain three space separated positive integers denoting the from, to and weight of the edge. The vertices from and to must be in the inclusive range [1, n]
* The last line should contain a single integer in the inclusive range [1, n] denoting the source vertex
## Output Format:
* The n - 1 output lines each, will contain the shortest distance to every other vertex followed by the path
* The hops in the path are separated by " -> "
## Time Complexity: 
* O(n log n)
## Space Complexity: 
* O(n)