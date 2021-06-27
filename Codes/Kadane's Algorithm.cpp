/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Kadane's Algorithm
Problem Statement :- Given a positive integer N and a sequence of N integers, find the sub-array with
                     the maximum sum.
Problem Category :-  Arrays
Program Input Format :- N, denoting the number of elements.
                        N integers denoting the array of elements
Program Output Format :-The maximum sub-array sum
                        The sub-array with the maximum sum
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> solve(ll n,vector<ll> A)
{
    ll tmax=0,res=LLONG_MIN,i,start=0,end=-1,s=0;
    for(i=0;i<n;i++)
    {
        tmax+=A[i];
        if(res<tmax)
        {
            res=tmax;
            start=s;
            end=i;
        }
        if(tmax<0)
        {
            tmax=0;
            s=i+1;
        }
    }
    if(end==-1)
    {
        res=LLONG_MIN;
        for(i=0;i<n;i++)
            if(res<A[i])
            {
                res=A[i];
                start=i;
                end=i;
            }
    }
    return {start,end,res};
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,i,ele;
    vector<ll> A,result;
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>ele;
        A.push_back(ele);
    }
    result=solve(n,A);
    for(i=result[0];i<=result[1];i++)
        fout<<A[i]<<' ';
    fout<<endl<<result[2];
    fin.close();
    fout.close();
    return 0;
}
