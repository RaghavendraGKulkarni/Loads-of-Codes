/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Knapsack Problem using Recursion
Problem Statement :- Given N items, each with a particular weight and cost, find the maximum
                     profit that can be gained by selling items that can hold in a bag of
                     maximum capacity W.
Problem Category :-  Recursion
Program Input Format :- N, denoting the number of items
                        N pairs (w,c) denoting the weight and cost of each item
                        W, the total weight capacity of the bag
Program Output Format :- The maximum profit that can be gained by selling items.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll n,vector<ll> wt,vector<ll> val,ll w)
{
    if(n==0 || w==0)
        return 0;
    if(wt[n-1]>w)
        return solve(n-1,wt,val,w);
    else
        return max(val[n-1]+solve(n-1,wt,val,w-wt[n-1]),solve(n-1,wt,val,w));
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll i,n,w;
    fin>>n;
    vector<ll> cost(n),weight(n);
    for(i=0;i<n;i++)
        fin>>weight[i]>>cost[i];
    fin>>w;
    fout<<solve(n,weight,cost,w)<<endl;
    fin.close();
    fout.close();
    return 0;
}
