/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Permutations of an Array using Backtracking
Problem Statement :- Given a positive integer N and a sequence of N integers, print all
                     the N! permutations of the sequence using Backtracking
Problem Category :-  Recursion and Backtracking
Program Input Format :- N, denoting the number of integers.
                        N integers denoting the sequence of integers
Program Output Format :- All N! permutations possible each in one line
**/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve(vector<ll> A,ll l,ll r,vector<vector<ll>> &result)
{
    ll i;
    if(l==r)
        result.push_back(A);
    else
    {
        for(i=l;i<=r;i++)
        {
            swap(A[l],A[i]);
            solve(A,l+1,r,result);
            swap(A[l],A[i]);
        }
    }
    return;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll i,n,j,ele;
    vector<ll> A;
    vector<vector<ll>> result;
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>ele;
        A.push_back(ele);
    }
    solve(A,0,n-1,result);
    for(i=0;i<result.size();i++)
    {
        for(j=0;j<n;j++)
            fout<<result[i][j]<<' ';
        fout<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
