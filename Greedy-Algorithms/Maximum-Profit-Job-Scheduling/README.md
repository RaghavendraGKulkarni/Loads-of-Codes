# Maximum Profit Job Scheduling
## Description:
### Given an array of n jobs, each with an id, a deadline and a profit where each job takes 1 day to complete, the program finds a scheduling of the jobs such that the profit of completing a job within its deadline is maximized
## Input Format:
* The first line should contain a positive integer n denoting the number of jobs
* The next n lines should contain three space separated integers denoting the id, deadline and profit of a job
## Output Format:
* The first line will contain two integers d and p denoting the number of days of work done and the attained profit
* The second line each will contain d space separated integers denoting ids of the job completed in order of the schedule
* Days with no work done is denoted by -1
## Time Complexity: 
* O(n log n)
## Space Complexity: 
* O(n)