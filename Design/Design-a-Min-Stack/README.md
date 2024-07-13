# Design a Min Stack
## Description:
### Design a stack data structure that supports the following operations in constant average time complexity
1) push(x): Pushes an element x into the stack  
2) pop(): Popes an element from the top of the stack    
3) top(): Returns the top element of the stack  
4) getMin(): Returns the minimum element from the stack
## Input Format:
* The first line should contain a positive integer n denoting the number of operations to be performed
* The next n lines should contain one of the following operation inputs:    
a) 1 x, denoting to push an element x into the stack    
b) 2, denoting to pop an element x from the top of the stack    
c) 3, denoting to print the top element of the stack    
d) 4, denoting to print the minimum element from the stack
## Output Format:
* The number of output lines is decided by the number of top() and getMin() operations in the input
* Each top() and getMin() operation output will be printed in a separate line
## Time Complexity: 
* O(n)
## Space Complexity: 
* O(n)