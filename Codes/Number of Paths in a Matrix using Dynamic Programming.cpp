/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Number of Paths in a Matrix using Dynamic Programming
Problem Statement :- Given two positive integers N and M, find the number of paths
                     from the left top corner to right bottom corner of the matrix
                     using only right and down moves.
Problem Category :- Dynamic Programming
Program Input Format :- N, denoting the number of rows in the matrix.
                        M, denoting the number of columns in the matrix.
Program Output Format :- The number of paths from the left top corner to right bottom corner of the matrix
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll n,ll m)
{
    ll i,j;
    vector<ll> dp(m,0);
    dp[0]=1;
    for(i=0;i<n;i++)
        for(j=1;j<m;j++)
            dp[j]+=dp[j-1];
    return dp[m-1];
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    ll n,m;
    fin>>n>>m;
    fout<<solve(n,m);
    fin.close();
    fout.close();
    return 0;
}

