/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Three Number Sort
Problem Statement :- Given a positive integer N>=3, and unsorted array of N integers,
                     containing exactly 3 distinct integers, sort the array in the given order of those
                     three distinct integers.
Problem Category :-  Two Pointer Algorithm
Program Input Format :- N, denoting the number of integers in the sequence.
                        N integers denoting the sequence
                        3 integers denoting the order.
Program Output Format :- The resulting sorted sequence.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve(vector<ll> &A,vector<ll> order)
{
    int n=A.size(),l=0,m=0,r=n-1;
    while(m<=r)
    {
        if(A[m]==order[0])
            swap(A[l++],A[m++]);
        else if(A[m]==order[1])
            m++;
        else
            swap(A[m],A[r--]);
    }
    return;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,i;
    fin>>n;
    vector<ll> A(n),order(3);
    for(i=0;i<n;i++)
        fin>>A[i];
    fin>>order[0]>>order[1]>>order[2];
    solve(A,order);
    for(auto &it:A)
        fout<<it<<' ';
    fin.close();
    fout.close();
    return 0;
}
