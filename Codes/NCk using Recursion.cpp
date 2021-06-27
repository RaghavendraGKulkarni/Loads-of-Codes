/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Recursive nCk
Problem Statement :- Find the number of ways to choose k items from a set of n items.
Problem Category :-  Recursion
Program Input Format :- N, denoting the total number of items.
                        K, denoting the number of items to be chosen.
Program Output Format :- The total number of ways to choose k items from a set of n items.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll n,ll k)
{
    if(k==0 || k==n)
        return 0;
    return solve(n-1,k-1)+solve(n-1,k);
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,k;
    fin>>n>>k;
    fout<<solve(n,k);
    fin.close();
    fout.close();
    return 0;
}
