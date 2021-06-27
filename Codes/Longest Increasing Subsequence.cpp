/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Longest Increasing Subsequence
Problem Statement :- Given a positive integer N and a sequence of N integers, find the
                     length of the longest increasing subsequence of the sequence.
Problem Category :-  Dynamic Programming
Program Input Format :- N, the number of elements in the sequence
                        A, the sequence of the elements
Program Output Format :- The length of the longest increasing subsequence.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll n,vector<ll> A)
{
    ll i,j;
    vector<ll> dp(n,1);
    for(i=1;i<n;i++)
        for(j=0;j<i;j++)
            if(A[i]>A[j])
                dp[i]=max(dp[i],dp[j]+1);
    return dp[n-1];
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,i,ele;
    vector<ll> A;
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>ele;
        A.push_back(ele);
    }
    fout<<solve(n,A);
    fin.close();
    fout.close();
    return 0;
}
