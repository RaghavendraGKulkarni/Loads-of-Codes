/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- All Combinations of balanced brackets
Problem Statement :- Given a non-negative integer N, generate all the possible
                     combinations of balanced brackets using N pairs of brackets '()'
Problem Category :-  Recursion and Backtracking
Program Input Format :- N, denoting the number of pairs of brackets available
Program Output Format :- All possible combinations of bracket sequences, one per line
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve(ll n,string combination,vector<string> &combinations,ll open,ll close)
{
    if(open==n && close==n)
    {
        combinations.push_back(combination);
        return;
    }
    if(open>close)
        solve(n,combination+")",combinations,open,close+1);
    if(open<n)
        solve(n,combination+"(",combinations,open+1,close);
    return;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    vector<string> combinations;
    ll n;
    fin>>n;
    solve(n,"",combinations,0,0);
    for(auto &it:combinations)
        fout<<it<<endl;
    fin.close();
    fout.close();
    return 0;
}
