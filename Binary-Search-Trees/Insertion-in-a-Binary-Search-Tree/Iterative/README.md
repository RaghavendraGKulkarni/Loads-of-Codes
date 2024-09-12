# Insertion in a Binary Search Tree
## Description:
### Given a binary search tree of n nodes, the program inserts a new node with a given value in the Binary Search Tree iteratively, if it does not exist
## Input Format:
* The first and the only line should contain a stream of space separated inputs where each input is either a number denoting a node or 'null' denoting a null node
* The second line should contain an integer denoting the value of node to be inserted
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
* The first and only output line will contain space separated integers denoting the Inorder traversal of the modified tree
## Time Complexity: 
* O(n)
## Space Complexity: 
* O(1)