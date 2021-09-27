/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Binary Search Insertion Sort
Problem Statement :- Given a positive integer N and a sequence of N integers, sort the integers
                     in non-decreasing order using the Binary Search Insertion Sort technique.
Problem Category :-  Sorting
Program Input Format :- N, denoting the number of integers in the sequence.
                        N integers denoting the sequence
Program Output Format :- The resulting sorted sequence.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void insert(vector<ll> &A,ll i)
{
    int low=0,mid,high=i-1,temp,k;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(A[mid]<=A[high+1])
            low=mid+1;
        else
        {
            k=high+1;
            temp=A[high+1];
            while(k>mid)
            {
                A[k]=A[k-1];
                k--;
            }
            A[mid]=temp;
            high=mid-1;
        }
    }
    return;
}
void solve(vector<ll> &A)
{
    int i,n=A.size();
    for(i=1;i<n;i++)
        insert(A,i);
    return;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,i,ele;
    fin>>n;
    vector<ll> A(n);
    for(i=0;i<n;i++)
        fin>>A[i];
    solve(A);
    for(i=0;i<n;i++)
        fout<<A[i]<<' ';
    fin.close();
    fout.close();
    return 0;
}
