/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Radix Sort
Problem Statement :- Given a positive integer N and a sequence of N positive integers, sort the integers in
                     non-decreasing order using the Radix Sort technique.
Problem Category :-  Sorting
Program Input Format :- N, denoting the number of integers in the sequence.
                        N integers denoting the sequence
Program Output Format :- The resulting sorted sequence.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll getMax(vector<ll> A)
{
    ll mx=A[0],n=A.size(),i;
    for(i=1;i<n;i++)
        if(A[i]>mx)
            mx=A[i];
    return mx;
}
void countSort(vector<ll> &A,ll exp)
{
    ll i,n=A.size();
    vector<ll> output(n),count(10,0);
    for(i=0;i<n;i++)
        count[(A[i]/exp)%10]++;
    for(i=1;i<10;i++)
        count[i]+=count[i-1];
    for(i=n-1;i>=0;i--)
    {
        output[count[(A[i]/exp)%10]-1]=A[i];
        count[(A[i]/exp)%10]--;
    }
    for(i=0;i<n;i++)
        A[i]=output[i];
    return;
}
void solve(vector<ll> &A)
{
    ll exp,n=A.size(),m;
    m=getMax(A);
    for(exp=1;m/exp>0;exp*=10)
        countSort(A,exp);
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
