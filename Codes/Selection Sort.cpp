/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Selection Sort
Problem Statement :- Given a positive integer N and a sequence of N integers, sort the integers
                     in non-decreasing order using the Selection Sort technique.
Problem Category :-  Sorting
Program Input Format :- N, denoting the number integers in the sequence.
                        N integers denoting the sequence
Program Output Format :- The resulting sorted sequence.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll Min(vector<ll> &A,ll k)
{
    ll m=INT_MAX,i,ans;
    for(i=k;i<A.size();i++)
    {
        if(A[i]<m)
        {
            m=A[i];
            ans=i;
        }
    }
    return ans;
}
void solve(vector<ll> &A)
{
    ll i,j,n=A.size();
    for(i=0;i<n-1;i++)
    {
        j=Min(A,i);
        swap(A[i],A[j]);
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
