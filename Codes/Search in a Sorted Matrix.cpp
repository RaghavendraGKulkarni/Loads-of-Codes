/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Search in a Sorted Matrix
Problem Statement :- Given two non-negative integers N and M and a sorted matrix of size NxM,
                     where every row and every column in sorted, search an element in the matrix
                     and return it's index if present and [-1,-1] otherwise.
Problem Category :-  Searching
Program Input Format :- N and M, denoting the number of rows and columns respectively.
                        A NxM matrix to search the element in.
                        K, the element to be searched.
Program Output Format :- The pair of integers denoting the search result.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
pair<ll,ll> solve(vector<vector<ll>> A,ll k)
{
    ll n=A.size(),m=A[0].size(),i=0,j=m-1;
    while(i<n && j>=0)
    {
        if(A[i][j]==k)
            break;
        else if(A[i][j]<k)
            i++;
        else
            j--;
    }
    if(i<n && j>=0 && A[i][j]==k)
        return {i,j};
    return {-1,-1};
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,m,i,j,k;
    fin>>n>>m;
    vector<vector<ll>> A(n,vector<ll> (m));
    pair<ll,ll> result;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            fin>>A[i][j];
    fin>>k;
    result=solve(A,k);
    fout<<result.first<<' '<<result.second;
    fin.close();
    fout.close();
    return 0;
}

