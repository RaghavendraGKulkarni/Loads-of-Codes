/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Coin Change Problem
Problem Statement :- Given a positive integer N and N coins of different values, find the
                     different number of ways in which an amount K can be made using the coins.
Problem Category :-  Dynamic Programming
Program Input Format :- N, denoting the number of coins.
                        N integers denoting the coin values.
                        K, denoting the amount to be summed up.
Program Output Format :- Number of ways in which the amount can be made using the coins.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(vector<ll> coins,ll n,ll k)
{
    ll i,j,ans;
    vector<ll> res(k+1,0);
    res[0]=1;
    for(i=0;i<n;i++)
        for(j=coins[i];j<=k;j++)
            res[j]+=res[j-coins[i]];
    return res[k];
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll i,k,n;
    fin>>n;
    vector<ll> coins(n);
    for(i=0;i<n;i++)
        fin>>coins[i];
    fin>>k;
    fout<<solve(coins,n,k);
    fin.close();
    fout.close();
    return 0;
}
