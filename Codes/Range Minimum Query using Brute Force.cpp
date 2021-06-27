/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Range Minimum Query using Brute Force Method
Problem Statement :- Given two positive integers N,Q, a sequence of N integers and
                     Q queries in the form of two integers L and R, find the minimum
                     of the sub-array from index L to index R using Brute Force Method.
Problem Category :-  Array Query
Program Input Format :- N, denoting the number of integers and Q, denoting the number of queries
                        N integers denoting sequence of the numbers.
                        Q pairs (L,R) denoting the range boundaries
Program Output Format :- Q integers denoting the answer to each query.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(vector<ll> A,ll l,ll r)
{
    ll i,ans=LLONG_MAX;
    for(i=l;i<=r;i++)
        ans=min(ans,A[i]);
    return ans;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,q,i,l,r,ele;
    vector<ll> A;
    fin>>n>>q;
    for(i=0;i<n;i++)
    {
        fin>>ele;
        A.push_back(ele);
    }
    while(q--)
    {
        fin>>l>>r;
        fout<<solve(n,A,l,r)<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
