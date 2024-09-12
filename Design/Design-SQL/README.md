# Design SQL
## Description:
### Design an SQL system that supports the following operations
1) sql(): Initiates an SQL system
2) createTable(name, c): Creates a table name with c columns  
3) insertRow(name, r): Inserts the row r into the table name
4) deleteRow(name, r): Delete rth row (1-indexed) from the table name
5) selectRow(name, r): Prints the rth row (1-indexed) from table name
6) selectCell(name, r, c): Prints the cell at rth row and cth column (1-indexed) from table name
## Input Format:
* The first line should contain a positive integer n denoting the number of operations to be performed
* The next n lines should contain one of the following operation inputs:    
a) 1 name c, denoting createTable(name, c) where name is a string and c is a positive integer
b) 2 name r, denoting insertRow(name, r) where name is a string and r is a vector of strings
c) 3 name r, denoting deleteRow(name, r) where name is a string and r is a positive integer
d) 4 name r, denoting selectRow(name, r) where name is a string and r is a positive integer
e) 5 name r c, denoting selectCell(name, r, c) where name is a string and r and c are positive integers
## Output Format:
* Each of the n lines of output represent the result of an input operation, in that order of the input
* The operations createTable(name, c), insertRow(name, r) and deleteRow(name, r) print a description of the output status
* The operation selectRow(name, r) prints the row with space separated strings denoting the cells, if the rth row exists and "None" otherwise
* The operation selectRow(name, r, c) prints a single string denoting the output, if the rth row and cth column exists and "None" otherwise
## Time Complexity: 
* O(n)
## Space Complexity: 
* O(n)