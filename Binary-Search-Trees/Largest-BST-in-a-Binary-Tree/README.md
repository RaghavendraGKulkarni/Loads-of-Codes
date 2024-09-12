# Largest BST in a Binary Tree
## Description:
### Given a binary tree of n nodes, the program finds the size of the largest BST in the binary tree
## Input Format:
* The first and the only line should contain a stream of space separated inputs where each input is either a number denoting a node or 'null' denoting a null node
* The first input in the stream should be the root node value and every pair of next inputs should be the left and right child node values (in that order) of the leftmost non-null node whose child values are not specified yet
* For example, the below binary tree is represented as
                                                      6
                                              3               7
                                          1       5       n       9
                                        n   2   4   n           8   n
6 3 7 1 5 null 9 null 2 4 null 8 null
* Note that the children of null nodes need not be specified as anything
* For a null tree with 0 nodes, the first line should only contain 'null'
## Output Format:
* The first and only output line will contain an integer denoting the size of the largest BST in the binary tree
## Time Complexity: 
* O(n)
## Space Complexity: 
* O(n)