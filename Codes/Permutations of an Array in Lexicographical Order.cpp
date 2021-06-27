/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Permutations in Lexicographical Order
Problem Statement :- Given a positive integer N and a sequence of N integers, print all
                     the N! permutations of the sequence in Lexicographical Order
Problem Category :-  Sorting
Program Input Format :- N, denoting the number of integers.
                        N integers denoting the sequence of integers
Program Output Format :- All N! permutations possible in lexicographical order each in one line
**/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include <iostream>
ll closest(vector<ll> &A,ll l,ll r,ll key)
{
    ll mid,index=-1;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(A[mid]<=key)
            r=mid-1;
        else
        {
            l=mid+1;
            if(index==-1 || A[index]>=A[mid])
                index=mid;
        }
    }
    return index;
}
bool next(ll n,vector<ll> &A)
{
    ll i=n-2,j;
    while(i>=0 && A[i]>=A[i+1])
        i--;
    if(i<0)
        return false;
    else
    {
        j=closest(A,i+1,n-1,A[i]);
        swap(A[i],A[j]);
        reverse(A.begin()+i+1,A.end());
        return true;
    }
}
vector<vector<ll>> solve(vector<ll> A)
{
    ll n=A.size();
    vector<vector<ll>> result;
    sort(A.begin(),A.end());
    do
    {
        result.push_back(A);
    }while(next(n,A));
    return result;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll i,n,j,ele;
    vector<ll> A;
    vector<vector<ll>> result;
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>ele;
        A.push_back(ele);
    }
    result=solve(A);
    for(i=0;i<result.size();i++)
    {
        for(j=0;j<n;j++)
            fout<<result[i][j]<<' ';
        fout<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
