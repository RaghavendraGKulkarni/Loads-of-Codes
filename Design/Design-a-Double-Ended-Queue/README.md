# Design a Double Ended Queue
## Description:
### Design a double ended queue data structure that supports the following operations in constant average time complexity
1) dequeue(): Initiates a dequeue object
2) pushFront(x): Pushes an element x to the front of the queue
3) pushRear(x): Pushes an element x to the rear of the queue 
4) popFront(): Pops an element from the front of the queue    
5) popRear(): Pops an element from the front of the queue  
6) getFront(): Returns the front element from the queue
7) getRear(): Returns the rear element from the queue
## Input Format:
* The first line should contain a positive integer n denoting the number of operations to be performed
* The next n lines should contain one of the following operation inputs:    
a) 1 x, denoting to push an element x to the front of the queue    
b) 2 x, denoting to push an element x to the rear of the queue    
c) 3, denoting to pop an element from the front of the queue    
d) 4, denoting to pop an element from the rear of the queue
e) 5, denoting to get the element from the front of the queue
f) 6, denoting to get the element from the rear of the queue
## Output Format:
* The number of output lines is decided by the number of getFront() and getRear() operations in the input
* Each getFront() and getRear() operation output will be printed in a separate line
## Time Complexity: 
* O(n)
## Space Complexity: 
* O(n)