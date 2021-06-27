/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Catalan's Number using Dynamic Programming
Problem Statement :- Given a non-negative integer N, find the Nth Catalan number using
                     dynamic programming.
Problem Category :-  Dynamic Programming
Program Input Format :- N, denoting the index of the Catalan number to be found.
Program Output Format :- Nth Catalan Number
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll n)
{
    ll i,j;
    vector<ll> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(i=2;i<=n;i++)
        for(j=0;j<i;j++)
            dp[i]+=dp[j]*dp[i-j-1];
    return dp[n];
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n;
    fin>>n;
    fout<<solve(n);
    fin.close();
    fout.close();
    return 0;
}
