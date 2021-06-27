/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- nCk in O(nk) time and O(k) space
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
    vector<ll> dp(k+1,0);
    dp[0]=1;
    for(i=1;i<=n;i++)
        for(j=min(i,k);j>0;j--)
            dp[[j]=dp[j]+dp[j-1];
    return dp[k];
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

