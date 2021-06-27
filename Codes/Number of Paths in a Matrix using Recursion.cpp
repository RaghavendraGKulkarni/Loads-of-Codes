/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Number of Paths in a Matrix using Recursion
Problem Statement :- Given two positive integers N and M, find the number of paths
                     from the left top corner to right bottom corner of the matrix
                     using only right and down moves.
Problem Category :- Recursion
Program Input Format :- N, denoting the number of rows in the matrix.
                        M, denoting the number of columns in the matrix.
Program Output Format :- The number of paths from the left top corner to right bottom corner of the matrix
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll n,ll m)
{
    if(n==1 || m==1)
        return 1;
    return solve(n,m-1)+solve(n-1,m);
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    ll n,m;
    fin>>n>>m;
    fout<<solve(n,m);
    fin.close();
    fout.close();
    return 0;
}
