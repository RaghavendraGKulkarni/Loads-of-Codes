/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Inversions in an Array
Problem Statement :- Given a positive integer N and a sequence of N integers, count the number
                     of inversions in the sequence, i.e. the number of pairs (i,j) such that
                     i<j and sequence[i]>sequence[j].
Problem Category :-  Divide and Conquer
Program Input Format :- N, denoting the number integers in the sequence.
                        N integers denoting the sequence
Program Output Format :- The number of inversions in the array.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll Merge(vector<ll> &A,vector<ll> &temp,ll left,ll mid,ll right)
{
    ll i=left,j=mid,k=left,inv=0;
    while(i<=mid-1 && j<=right)
    {
        if(A[i]<=A[j])
            temp[k++]=A[i++];
        else
        {
            temp[k++]=A[j++];
            inv+=(mid-i);
        }
    }
    while(i<=mid-1)
        temp[k++]=A[i++];
    while(j<=right)
        temp[k++]=A[j++];
    for(i=left;i<=right;i++)
        A[i]=temp[i];
    return inv;
}
ll MergeSort(vector<ll> &A,vector<ll> &temp,ll left,ll right)
{
    ll mid,inv=0;
    if(left<right)
    {
        mid=(left+right)/2;
        inv+=MergeSort(A,temp,left,mid);
        inv+=MergeSort(A,temp,mid+1,right);
        inv+=Merge(A,temp,left,mid+1,right);
    }
    return inv;
}
ll solve(ll n,vector<ll> A)
{
    ll result;
    vector<ll> temp(n);
    result=MergeSort(A,temp,0,n-1);
    return result;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll i,n;
    fin>>n;
    vector<ll> A(n);
    for(i=0;i<n;i++)
        fin>>A[i];
    fout<<solve(n,A);
    fin.close();
    fout.close();
    return 0;
}
