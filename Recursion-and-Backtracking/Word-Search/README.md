# Word Search
## Description:
### Given a nxn square grid of uppercase English letters, the program searches for a word in the grid where a valid word can be formed by moving along any one of the eight directions starting from any one letter, using Backtracking paradigm
## Input Format:
* The first line should contain a positive integer n (not greater than 10) and a string of uppercase English letters, denoting the size of the grid and the word to be searched respectively
* The next n lines should contain n space separated uppercase English letters denoting the row
## Output Format:
* The n lines of output will contain all the letters except the word replaced by '*' in the grid highlighting the position of the word in the grid, if the word is found
* If not, all the letters in the grid will be replaced by '*'
## Time Complexity: 
* O(n^2)
## Space Complexity: 
* O(n)