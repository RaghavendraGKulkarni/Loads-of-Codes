/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Determinant of a Matrix using Recursion
Problem Statement :- Given two integers N and M, and a matrix of size NxM, calculate the determinant
                     of the matrix.
Problem Category :-  Recursion
Program Input Format :- N, denoting the number of rows.
                        M, denoting the number of columns.
                        An NxM matrix whose determinant is to be calculated.
Program Output Format :- The determinant of the matrix.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> coFactor(ll n,vector<vector<ll>> A,ll p,ll q)
{
    ll i,j;
    vector<vector<ll>> result;
    for(i=0;i<n;i++)
    {
        if(i!=p)
        {
            vector<ll> temp;
            for(j=0;j<n;j++)
            {
                if(j!=q)
                {
                    temp.push_back(A[i][j]);
                }
            }
            result.push_back(temp);
        }
    }
    return result;
}
ll solve(ll n,vector<vector<ll>> A)
{
    if(n==1)
        return A[0][0];
    ll j,sign=1,result=0;
    vector<vector<ll>> temp;
    for(j=0;j<n;j++)
    {
        temp=coFactor(n,A,0,j);
        result+=(A[0][j]*sign*solve(n-1,temp));
        sign*=-1;
    }
    return result;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,m,i,j;
    fin>>n>>m;
    if(n!=m)
        fout<<"Determinant does not exist for non-square matrix";
    else
    {
        vector<vector<ll>> A(n,vector<ll> (m));
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                fin>>A[i][j];
        fout<<solve(n,A);
    }
    fin.close();
    fout.close();
    return 0;
}
