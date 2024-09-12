# Count connected components
## Description:
### Given an unweighted graph of n vertices and e edges, the program finds the number of connected components in the graph using Depth First Search
## Input Format:
* The first line should contain two positive integers n and e denoting the number of vertices and edges in the graph followed a character 'D' or 'U' denoting whether the graph is Directed or Undirected
* The next e lines each should contain two space separated positive integers denoting the from and to of the edge. The vertices from and to must be in the range [1, n]
## Output Format:
* The first and the only line will contain the number of connected components
## Time Complexity: 
* O(e)
## Space Complexity: 
* O(n)