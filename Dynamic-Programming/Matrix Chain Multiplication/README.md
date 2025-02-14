# Matrix Chain Multiplication
## Description:
### Given the orders of n matrices to be multiplied in that order, the program computes the minimum number of scalar multiplications required to calculate the product and the optimal combination of multiplication required to achieve this using Dynamic Programming paradigm
## Input Format:
* The first line should contain a positive integer n, greater than 1, denoting the number of matrices to be multiplied
* The second line should contain n + 1 space separated positive integers where the pair of ith and (i+1)th integers denote the order of the ith matrix
## Output Format:
* The first line will contain an integer denoting the minimum number of scalar multiplications required to calculate the product of the matrices
* The second line will contain the optimal combination of the matrices using parentheses, required to achieve this
## Time Complexity:
* O(n^3)
## Space Complexity:
* O(n^2)