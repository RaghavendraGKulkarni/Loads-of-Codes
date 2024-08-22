# Breadth First Traversal
## Description:
### Given an unweighted graph of n vertices and e edges, the program prints the Breadth First Traversal of the graph from a given source vertex
## Input Format:
* The first line should contain two positive integers n and e denoting the number of vertices and edges in the graph followed a character 'D' or 'U' denoting whether the graph is Directed or Undirected
* The next e lines each should contain two space separated positive integers denoting the from and to of the edge. The vertices from and to must be in the inclusive range [1, n]
* The last line should contain a single integer in the inclusive range [1, n] denoting the source vertex
## Output Format:
* The first and only output line will contain the n space separated integers denoting the traversal from the source vertex
* Note: The neighbors of a vertex are stored in the order of their appearance in the input and the same will be reflected in the traversal
## Time Complexity: 
* O(n)
## Space Complexity: 
* O(n)