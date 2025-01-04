# All Paths from Root to Leaves
## Description:
### Given a binary tree of n nodes, the program prints all the paths from root to leaves, recursively
## Input Format:
* The first and the only line should contain a stream of space separated inputs where each input is either a number denoting a node or 'null' denoting a null node
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
* The number of output lines is decided by the number of leaves in the binary tree
* Each line will have space separated integers denoting a path from the root to a leaf
## Time Complexity: 
* O(n)
## Space Complexity: 
* O(n)