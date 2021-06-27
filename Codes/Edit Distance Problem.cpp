/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Edit Distance Problem
Problem Statement :- Given two strings of lowercase letters, find the minimum number of operations needed
                     to convert the first string to the second, where each operation denotes either deleting
                     a character, or adding a character or replacing one character with the other in string one.
Problem Category :-  Dynamic Programming
Program Input Format :- s1, denoting the first string
                        s2, denoting the second string
Program Output Format :- The minimum number of operations to convert the first string to second.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(string s1,string s2)
{
    ll n=s1.length(),m=s2.length(),i,j;
    vector<vector<ll>> dp(n+1,vector<ll> (m+1));
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=min(min(dp[i-1][j-1]+1,dp[i-1][j]+1),dp[i][j-1]+1);
        }
    }
    return dp[n][m];
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    string s1,s2;
    fin>>s1>>s2;
    fout<<solve(s1,s2)<<endl;
    fin.close();
    fout.close();
    return 0;
}
