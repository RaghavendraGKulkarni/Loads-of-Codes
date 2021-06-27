/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Bubble Sort
Problem Statement :- Given a positive integer N and a sequence of N integers, sort the integers in
                     non-decreasing order using the Bubble Sort technique.
Problem Category :-  Sorting
Program Input Format :- N, denoting the number of integers in the sequence.
                        N integers denoting the sequence
Program Output Format :- The resulting sorted sequence.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve(vector<ll> &A)
{
    ll i,j,n=A.size();
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(A[j]>A[j+1])
                swap(A[j],A[j+1]);
    return;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll i,j,n,ele;
    vector<ll> A;
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>ele;
        A.push_back(ele);
    }
    solve(A);
    for(i=0;i<n;i++)
        fout<<A[i]<<' ';
    fin.close();
    fout.close();
    return 0;
}

