/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Naive Pattern Searching Algorithm
Problem Statement :- Given a text and a pattern in the form of strings, find the index/indices at which
                     the pattern is present in the text, or print -1 if not found.
Problem Category :-  Substring search Algorithms
Program Input Format :- Text, denoting the text to search in.
                        Pattern, denoting the pattern to search.
Program Output Format :- The index/indices of the pattern in the text if present, else -1.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> solve(string s1,string s2)
{
    ll i,j,n=s1.length(),m=s2.length();
    vector<ll> result={-1};
    if(n<m)
        return result;
    for(i=0;i<=n-m;i++)
    {
        for(j=0;j<m;j++)
            if(s1[i+j]!=s2[j])
                break;
        if(j==m)
        {
            if(result[0]==-1)
                result[0]=i;
            else
                result.push_back(i);
        }
    }
    return result;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    string s1,s2;
    vector<ll> result;
    getline(fin,s1);
    getline(fin,s2);
    result=solve(s1,s2);
    for(auto &it:result)
        fout<<it<<' ';
    fin.close();
    fout.close();
    return 0;
}
