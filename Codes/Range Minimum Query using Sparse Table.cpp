/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Range Minimum Query using Sparse Table
Problem Statement :- Given two positive integers N,Q, a sequence of N integers and
                     Q queries in the form of two integers L and R, find the minimum
                     of the sub-array from index L to index R using Sparse Table.
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
#define MAX 900
vector<vector<ll>> preprocess(ll n,vector<ll> A)
{
    vector<vector<ll>> sparse(MAX,vector<ll> (MAX));
    ll i,j;
    for(i=0;i<n;i++)
        sparse[i][0] = i;
    for(j=1;(1<<j)<=n;j++)
    {
        for(i=0;(i+(1<<j)-1)<n;i++)
        {
            if(A[sparse[i][j-1]]<A[sparse[i+(1<<(j-1))][j-1]])
                sparse[i][j]=sparse[i][j-1];
            else
                sparse[i][j]=sparse[i+(1<<(j-1))][j-1];
        }
    }
    return sparse;
}
ll solve(vector<vector<ll>> sparse,ll L,ll R)
{
    ll j=(ll)log2(R-L+1);
    if(sparse[L][j]<=sparse[R-(1<<j)+1][j])
        return sparse[L][j];
    else
        return sparse[R-(1<<j)+1][j];
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,q,i,l,r,ele;
    vector<ll> A;
    vector<vector<ll>> sparse;
    fin>>n>>q;
    for(i=0;i<n;i++)
    {
        fin>>ele;
        A.push_back(ele);
    }
    sparse=preprocess(n,A);
    while(q--)
    {
        fin>>l>>r;
        fout<<A[solve(sparse,l-1,r-1)]<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
