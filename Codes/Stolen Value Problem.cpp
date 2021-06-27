/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Stolen Value Problem
Problem Statement :- Given a non-negative integer N and a sequence of N integers denoting the
                     profit a robber earns by robbing each of the given N houses on a line find
                     the maximum profit the robber can earn by robbing no two adjacent houses.
Problem Category :-  Dynamic Programming
Program Input Format :- N, denoting the number of houses in a line.
                        N integers denoting profit earned by robbing each house
Program Output Format :- The maximum profit robber can earn by robbing no two adjacent houses.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(vector<ll> &A)
{
    ll i,j,n=A.size();
    vector<ll> dp(n+1,0);
    dp[0]=0;
    dp[1]=A[0];
    for(i=2;i<=n;i++)
        dp[i]=max(dp[i-1],dp[i-2]+A[i-1]);
    return dp[n];
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
    fout<<solve(A);
    fin.close();
    fout.close();
    return 0;
}
