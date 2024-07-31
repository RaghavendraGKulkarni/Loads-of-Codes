# Design an LRU Cache
## Description:
### Design an LRU Cache data structure of given capacity that supports the following operations in constant average time complexity
1) LRUCache(capacity): Initiates an LRU Cache of given maximum capacity
2) put(k, v): Maps the key k to the value v  
3) get(k): Returns the value mapped to the key k if it exists and -1 otherwise
4) If the Cache is full while a put() operation, the least recently accessed (key, value) pair should be overwritten
## Input Format:
* The first line should contain two positive integers n and q denoting the capacity of the cache and number of operations to be performed, respectively
* The next q lines should contain one of the following operation inputs:    
a) 1 k v, denoting to put (k, v) into the Cache
b) 2 k, denoting to get the value mapped to key k in the cache   
## Output Format:
* The number of output lines is decided by the number of get(k) operations in the input
* Each get(k) operation output will be printed in a separate line
## Time Complexity: 
* O(n)
## Space Complexity: 
* O(n)