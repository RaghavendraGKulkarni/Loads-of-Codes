/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Range Minimum Query using LookUp Table
Problem Statement :- Given two positive integers N,Q, a sequence of N integers and
                     Q queries in the form of two integers L and R, find the minimum
                     of the sub-array from index L to index R using LookUp Table.
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
vector<vector<ll>> preprocess(ll n,vector<ll> A)
{
    ll i,j;
    vector<vector<ll>> lookUp(n,vector<ll> (n));
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(i==j || A[j]<A[lookUp[i][j-1]])
                lookUp[i][j]=j;
            else
                lookUp[i][j]=lookUp[i][j-1];
        }
    }
    return lookUp;
}
ll solve(vector<vector<ll>> lookUp,ll l,ll r)
{
    return lookUp[l][r];
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,q,i,l,r,ele;
    vector<ll> A;
    vector<vector<ll>> lookUp;
    fin>>n>>q;
    for(i=0;i<n;i++)
    {
        fin>>ele;
        A.push_back(ele);
    }
    lookUp=preprocess(n,A);
    while(q--)
    {
        fin>>l>>r;
        fout<<A[solve(lookUp,l,r)]<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}


