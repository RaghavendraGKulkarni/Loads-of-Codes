/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Sort a Matrix Row-wise and Column-wise
Problem Statement :- Given a positive integer N and a square matrix of size NxN, perform
                     sort the matrix row-wise and column-wise.
Problem Category :-  Arrays
Program Input Format :- N, denoting the size of the square matrix.
                        A NxN matrix to perform spiral traversal on.
Program Output Format :- The resulting spiral traversal on the matrix.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void sortRow(vector<vector<ll>> &A,ll n)
{
    ll i;
    for(i=0;i<n;i++)
        sort(A[i].begin(),A[i].end());
    return;
}
void transpose(vector<vector<ll>> &A,ll n)
{
    ll i,j;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            swap(A[i][j],A[j][i]);
    return;
}
void solve(vector<vector<ll>> &A,ll n)
{
    sortRow(A,n);
    transpose(A,n);
    sortRow(A,n);
    transpose(A,n);
    return;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    ll t,n,i,j;
    fin>>n;
    vector<vector<ll>> A(n,vector<ll> (n));
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            fin>>A[i][j];
    solve(A,n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            fout<<A[i][j]<<' ';
        fout<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
