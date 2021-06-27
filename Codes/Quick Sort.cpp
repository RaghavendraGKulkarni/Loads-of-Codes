/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Quick Sort
Problem Statement :- Given a positive integer N and a sequence of N integers, sort the integers
                     in non-decreasing order using the Quick Sort technique.
Problem Category :-  Sorting
Program Input Format :- N, denoting the number of integers in the sequence.
                        N integers denoting the sequence
Program Output Format :- The resulting sorted sequence.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll Partition(vector<ll> &A,ll k,ll l)
{
    ll i,j,p;
    i=k+1;j=l;p=k;
    do
    {
        while(i<l && A[i]<=A[p])
            i++;
        while(j>k && A[j]>=A[p])
            j--;
        swap(A[i],A[j]);
    }while(i<j);
    swap(A[i],A[j]);
    swap(A[p],A[j]);
    return j;
}
void Quicksort(vector<ll> &A,ll k,ll l)
{
    ll s;
    if(k<l)
    {
        s=Partition(A,k,l);
        Quicksort(A,k,s-1);
        Quicksort(A,s+1,l);
    }
}
void solve(vector<ll> &A)
{
    ll n=A.size();
    Quicksort(A,0,n-1);
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
