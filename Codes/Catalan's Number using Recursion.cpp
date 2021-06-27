/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Catalan's Number using Recursion
Problem Statement :- Given a non-negative integer N, find the Nth Catalan number using recursion
Problem Category :-  Recursion
Program Input Format :- N, denoting the index of the Catalan number to be found.
Program Output Format :- Nth Catalan Number
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll n)
{
    if(n<=1)
        return 1;
    ll i,ans=0;
    for(i=0;i<n;i++)
        ans+=(solve(i)*solve(n-i-1));
    return ans;
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

