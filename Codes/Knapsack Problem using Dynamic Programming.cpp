/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Knapsack Problem using Dynamic Programming
Problem Statement :- Given N items, each with a particular weight and cost, find the maximum
                     profit that can be gained by selling items that can hold in a bag of
                     maximum capacity W.
Problem Category :-  Dynamic Programming
Program Input Format :- N, denoting the number of items
                        N pairs (w,c) denoting the weight and cost of each item
                        W, the total weight capacity of the bag
Program Output Format :- The maximum profit that can be gained by selling items.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll n,vector<ll> wt,vector<ll> val,ll w)
{
    ll i,j;
    ll dp[n+1][w+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=w;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(wt[i-1]<=j)
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][w];
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll i,n,w;
    fin>>n;
    vector<ll> cost(n),weight(n);
    for(i=0;i<n;i++)
        fin>>weight[i]>>cost[i];
    fin>>w;
    fout<<solve(n,weight,cost,w)<<endl;
    fin.close();
    fout.close();
    return 0;
}
