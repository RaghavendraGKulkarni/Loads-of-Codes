/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Knuth-Morris-Pratt Searching Algorithm
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
vector<ll> preprocess(string s)
{
    ll len=0,i=1,m=s.length();
    vector<ll> lps(m);
    lps[0]=0;
    while(i<m)
    {
        if(s[i]==s[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
                len=lps[len-1];
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
vector<ll> solve(string s1,string s2)
{
    ll i=0,j=0,n=s1.length(),m=s2.length();
    vector<ll> result={-1},lps=preprocess(s2);
    while(i<n)
    {
        if(s2[j]==s1[i])
        {
            j++;
            i++;
        }
        if(j==m)
        {
            if(result[0]==-1)
                result[0]=i-j;
            else
                result.push_back(i-j);
            j=lps[j-1];
        }
        else if(i<n && s2[j]!=s1[i])
        {
            if(j!=0)
                j=lps[j-1];
            else
                i++;
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
