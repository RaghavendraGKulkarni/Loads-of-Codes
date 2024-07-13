# Tower of Hanoi
## Description:
### Given three towers numbered 1, 2 and 3 from left and n disks of unique sizes on tower 1, sorted in increasing order of size from the top, the program lists all the moves required to shift the disks from tower 1 to tower 3 in the same final order, always popping only the top-most disk from a tower and not placing a larger disk on top of a smaller disk
## Input Format:
* The first and the only line should contain a positive integer n (not greater than 16) denoting the number of disks on tower 1
## Output Format:
* The first line will contain a single integer k denoting the number of moves
* The next k line will contain all the moves, each in a new line in the form of two integers, with first integer denoting the source tower and second integer denoting the destination tower
## Time Complexity: 
* O(2^n)
## Space Complexity:
* O(2^n)