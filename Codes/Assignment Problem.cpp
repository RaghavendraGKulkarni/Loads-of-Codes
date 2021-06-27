/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Assignment Problem
Problem Statement :- N different tasks are to be assigned to N different workers such that each worker gets, exactly one task.
                     Given, the cost each worker charges to each task as a NxN matrix, find the optimal assignment of tasks
                     among the workers so that the total cost is minimized.
Problem Category :-  Dynamic Programming and Bit Magic
Program Input Format :- N, denoting the number of workers and the tasks.
                        An NxN 2D array denoting the cost matrix
Program Output Format :- The minimum cost possible by the optimal assignment of tasks among the workers.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll setBits(ll mask)
{
    ll bits=0;
    while(mask)
    {
        if((mask&1)==1)
            bits++;
        mask>>=1;
    }
    return bits;
}
ll solve(ll n,vector<vector<ll>> cost)
{
    ll mask,j,x;
    vector<ll> dp(1<<n);
    dp[0]=0;
    for(j=1;j<(1<<n);j++)
        dp[j]=LLONG_MAX;
    for(mask=0;mask<(1<<n);mask++)
    {
        x=setBits(mask);
        for(j=0;j<n;j++)
            if(((mask>>j)&1)==0)
                dp[mask|(1<<j)]=min(dp[mask|(1<<j)],cost[x][j]+dp[mask]);
    }
    return dp[(1<<n)-1];
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll i,n,j;
    fin>>n;
    vector<vector<ll>> cost(n,vector<ll> (n));
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            fin>>cost[i][j];
    fout<<solve(n,cost)<<endl;
    fin.close();
    fout.close();
    return 0;
}
