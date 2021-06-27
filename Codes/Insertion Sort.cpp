/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Insertion Sort
Problem Statement :- Given a positive integer N and a sequence of N integers, sort the integers
                     in non-decreasing order using the Insertion Sort technique.
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
    ll i,j,n=A.size(),v;
    for(i=1;i<n;i++)
    {
        v=A[i];
        j=i-1;
        while(j>=0 && A[j]>v)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
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
