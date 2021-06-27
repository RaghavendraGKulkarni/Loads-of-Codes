/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Element with single occurrence in an Array
Problem Statement :- Given an positive integer N and a sequence of N integers where all but one
                     repeat twice, find the element which occurs only once.
Problem Category :-  Bit Magic
Program Input Format :- N, denoting the number of integers in the sequence.
                        N integers denoting the sequence.
Program Output Format :- The element occurring only once.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll n,vector<ll> A)
{
    ll i,ans=0;
    for(i=0;i<n;i++)
        ans^=A[i];
    return ans;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,i;
    fin>>n;
    vector<ll> A(n);
    for(i=0;i<n;i++)
        fin>>A[i];
    fout<<solve(n,A);
    fin.close();
    fout.close();
    return 0;
}
