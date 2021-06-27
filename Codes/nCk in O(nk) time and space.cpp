/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- nCk in O(nk) time and space
Problem Statement :- Given two non-negative integers N and K, find the number of ways to
                     choose K items from a set of N items.
Problem Category :-  Dynamic Programming
Program Input Format :- N, denoting the total number of items.
                        K, denoting the number of items to be chosen.
Program Output Format :- The total number of ways to choose K items from a set of N items.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll n,ll k)
{
    ll i,j;
    vector<vector<ll>> dp(n+1,vector<ll> (k+1));
    for(i=0;i<=n;i++)
        for(j=0;j<=min(i,k);j++)
            dp[i][j]= (j==0 || j==i) ? 1 : (dp[i-1][j-1]+dp[i-1][j]);
    return dp[n][k];
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,k;
    fin>>n>>k;
    fout<<solve(n,k);
    fin.close();
    fout.close();
    return 0;
}
