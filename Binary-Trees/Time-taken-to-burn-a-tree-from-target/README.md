# Time taken to burn a tree from target
## Description:
### Given a binary tree of n nodes with distinct values, the program finds the minimum time taken to burn the tree if the fire was set on a given target node at t = 0 and the fire spreads to every neighboring node per unit time
## Input Format:
* The first line should contain a stream of space separated inputs where each input is either a number denoting a node or 'null' denoting a null node
The second line should contain a single integer denoting the the target node value which is set on fire
* The first input in the stream should be the root node value and every pair of next inputs should be the left and right child node values (in that order) of the leftmost non-null node whose child values are not specified yet
* For example, the below binary tree is represented as
                                                      8
                                              5               2
                                          1       7       n       3
                                        n   6   9   n           4   n
8 5 2 1 7 null 3 null 6 9 null 4 null
* Note that the children of null nodes need not be specified as anything
* For a null tree with 0 nodes, the first line should only contain 'null'
## Output Format:
* The first and the only line will contain a single integer denoting the time taken to burn the tree
## Time Complexity: 
* O(n)
## Space Complexity: 
* O(n)