# Infix to Postfix Conversion
## Description:
### Given a valid infix expression consisting of operators ^, /, *, + and -, parentheses ( and ), and the variables represented using single lowercase English letters, the program converts the infix expression to postfix expression 
### The precedence of operators are 
* ^ --> Highest Priority with R -> L associativity
* \* --> Second Highest Priority with L -> R associativity
* \\ --> Second Highest Priority with L -> R associativity
* \+ --> Least Priority with L -> R associativity
* \- --> Least Priority with L -> R associativity
## Input Format:
* The first and only line should contain the valid Infix expression
## Output Format:
* The only output line will contain the postfix expression
## Time Complexity: 
* O(n)
## Space Complexity: 
* O(n)