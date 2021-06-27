/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Heap Sort
Problem Statement :- Given a positive integer N and a sequence of N integers, sort the integers
                     in non-decreasing order using the Heap Sort technique.
Problem Category :-  Sorting
Program Input Format :- N, denoting the number of integers in the sequence.
                        N integers denoting the sequence
Program Output Format :- The resulting sorted sequence.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void heapify(vector<ll> &A,ll n,ll i)
{
    ll large=i,l=2*i+1,r=2*i+2;
    if(l<n && A[l]>A[large])
        large=l;
    if(r<n && A[r]>A[large])
        large=r;
    if(large!=i)
    {
        swap(A[i],A[large]);
        heapify(A,n,large);
    }
    return;
}
void solve(vector<ll> &A)
{
    ll n=A.size(),i;
    for(i=n/2-1;i>=0;i--)
        heapify(A,n,i);
    for(i=n-1;i>0;i--)
    {
        swap(A[0],A[i]);
        heapify(A,i,0);
    }
    return;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll i,j,n,ele;
    vector<int> A;
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
