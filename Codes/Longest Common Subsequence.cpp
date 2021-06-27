/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Longest Common Subsequence
Problem Statement :- Given two strings, not necessarily of equal length, find the length of
                     the longest common subsequence among the strings.
Problem Category :-  Dynamic Programming
Program Input Format :- s1, the first string
                        s2, the second string
Program Output Format :- The length of the longest common subsequence.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(string s1,string s2)
{
    ll i,j,l1=s1.length(),l2=s2.length();
    vector<vector<ll>> LCS(l1+1,vector<ll> (l2+1,0));
    for(i=1;i<=l1;i++)
        for(j=1;j<=l2;j++)
            LCS[i][j]=(s1[i-1]==s2[j-1] ? LCS[i-1][j-1]+1 : max(LCS[i-1][j],LCS[i][j-1])) ;
    return LCS[l1][l2];
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    string s1,s2;
    fin>>s1>>s2;
    fout<<solve(s1,s2);
    fin.close();
    fout.close();
    return 0;
}

