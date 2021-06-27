/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Permutations of an Array using Johnson-Trotter
Problem Statement :- Given a positive integer N and a sequence of N integers, print all
                     the N! permutations of the sequence using Johnson-Trotter Algorithm.
Problem Category :-  Arrays
Program Input Format :- N, denoting the number of integers.
                        N integers denoting the sequence of integers
Program Output Format :- All the possible N! permutations each in one line
**/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll getMobile(ll n,vector<ll> A,map<ll,ll> dir)
{
    ll i,mobile=-1;
    for(i=0;i<n;i++)
        if(i+dir[A[i]]>=0 && i+dir[A[i]]<n && A[i+dir[A[i]]]<A[i] && (mobile==-1 || A[mobile]<A[i]))
            mobile=i;
    return mobile;
}
vector<vector<ll>> solve(ll n,vector<ll> A)
{
    ll mobile,maxElement;
    map<ll,ll> dir;
    vector<vector<ll>> result;
    sort(A.begin(),A.end());
    maxElement=A[n-1];
    for(auto &it:A)
        dir[it]=-1;
    result.push_back(A);
    mobile=getMobile(n,A,dir);
    while(mobile!=-1)
    {
        swap(A[mobile],A[mobile+dir[A[mobile]]]);
        result.push_back(A);
        mobile=getMobile(n,A,dir);
        if(mobile!=-1 && A[mobile]<maxElement)
            for(auto &it:A)
                if(it>A[mobile])
                    dir[it]*=-1;
    }
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
    result=solve(n,A);
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

