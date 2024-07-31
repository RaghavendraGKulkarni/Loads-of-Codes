# Design Twitter
## Description:
### Design a Twitter system that supports the following operations
1) twitter(): Initiates a twitter system
2) postTweet(u, t): Posts a tweet t by a user u  
3) getFeed(u): Extracts top 10 recent tweets by user u and users whom u follows
4) follow(u, v): Adds user v to the following list of user u
5) unfollow(u, v): Removes user v from the following list of user u
## Input Format:
* The first line should contain a positive integer n denoting the number of operations to be performed
* The next n lines should contain one of the following operation inputs:    
a) 1 u t, denoting postTweet(u, t)
b) 2 u, denoting getFeed(u)
c) 3 u v, denoting follow(u, v)
d) 4 u v, denoting unfollow(u, v)
## Output Format:
* The number of output lines is decided by the number of getFeed(u) operations in the input
* Each getFeed(u) operation output will be printed in a separate line
## Time Complexity: 
* O(n)
## Space Complexity: 
* O(n)