# Search an element in a Sorted Matrix
## Description:
### Given a matrix of m rows with each row sorted in non-decreasing order of n elements and first element of every row greater than last element of previous row, the program finds the index of a given element (1 - indexed) using the Divide and Conquer (Binary Search) paradigm
## Input Format:
* The first line should contain two positive integer m and n denoting the number of rows and columns in the matrix respectively and an integer k denoting the element to be found
* The next m lines each should contain n space separated integers denoting one row
## Output Format:
* The first and the only line will contain two space separated integers denoting the index of the element
* If the element is not found, -1 is printed
## Time Complexity: 
* O(log m*n)
## Space Complexity: 
* O(1)