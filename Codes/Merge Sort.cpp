/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Merge Sort
Problem Statement :- Given a positive integer N and a sequence of N integers, sort the integers
                     in non-decreasing order using the Merge Sort technique.
Problem Category :-  Sorting
Program Input Format :- N, denoting the number of integers in the sequence.
                        N integers denoting the sequence
Program Output Format :- The resulting sorted sequence.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void Merge(vector<ll> &A,vector<ll> &temp,ll left,ll mid,ll right)
{
    ll i=left,j=mid,k=left;
    while(i<=mid-1 && j<=right)
    {
        if(A[i]<=A[j])
            temp[k++]=A[i++];
        else
            temp[k++]=A[j++];
    }
    while(i<=mid-1)
        temp[k++]=A[i++];
    while(j<=right)
        temp[k++]=A[j++];
    for(i=left;i<=right;i++)
        A[i]=temp[i];
    return;
}
void MergeSort(vector<ll> &A,vector<ll> &temp,ll left,ll right)
{
    ll mid;
    if(left<right)
    {
        mid=(left+right)/2;
        MergeSort(A,temp,left,mid);
        MergeSort(A,temp,mid+1,right);
        Merge(A,temp,left,mid+1,right);
    }
    return;
}

void solve(vector<int> &A)
{
    ll n=A.size();
    vector<ll> temp(n);
    MergeSort(A,temp,0,n-1);
    return;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll i,n,ele;
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
