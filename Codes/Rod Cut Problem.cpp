/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Rod Cut Problem
Problem Statement :- Given a positive integer N, find the maximum product of the lengths of
                     the pieces into which the rod can be cut.
Problem Category :-  Dynamic Programming
Program Input Format :- N, denoting the length of the rod.
Program Output Format :- The maximum product of the lengths of the pieces into which the rod can be cut.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll length)
{
    ll i,j,res;
    vector<ll> dp(length+1,0);
    for(i=2;i<=length;i++)
        for(j=1;j<=i/2;j++)
            dp[i]=max(dp[i],max(j*(i-j),j*dp[i-j]));
    res=dp[length];
    return res;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll length;
    fin>>length;
    fout<<solve(length);
    fin.close();
    fout.close();
    return 0;
}
