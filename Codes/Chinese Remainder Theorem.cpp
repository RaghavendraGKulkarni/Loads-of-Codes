/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Chinese Remainder Theorem
Problem Statement :- Given a positive integer N and two lists A and B, of N non-negative integers,
                     find a least positive integer X such that X%A[i]=B[i] for all 1<=i<=N.
Problem Category :-  Number Theory
Program Input Format :- N, denoting the size of each list.
                        N pairs (a,b) each denoting the elements of lists A and B.
Program Output Format :- The minimum positive integer X such that X%A[i]=B[i] for all 1<=i<=N.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll modularInverse(ll a,ll m)
{
    ll m0=m,t,q,x0=0,x1=1;
    if(m==1)
        return 0;
    while(a>1)
    {
        q=a/m;
        t=m;
        m=a%m;
        a=t;
        t=x0;
        x0=x1-q*x0;
        x1=t;
    }
    if(x1<0)
        x1+=m0;
    return x1;
}
ll solve(vector<ll> A,vector<ll> B)
{
    ll prod=1,n=A.size(),result=0,i,temp;
    for(i=0;i<n;i++)
        prod*=A[i];
    for(i=0;i<n;i++)
    {
        temp=prod/A[i];
        result+=B[i]*modularInverse(temp,A[i])*temp;
    }
    return result%prod;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ll n,i;
    fin>>n;
    vector<ll> A(n),B(n);
    for(i=0;i<n;i++)
        fin>>A[i]>>B[i];
    fout<<solve(A,B);
    fin.close();
    fout.close();
    return 0;
}
