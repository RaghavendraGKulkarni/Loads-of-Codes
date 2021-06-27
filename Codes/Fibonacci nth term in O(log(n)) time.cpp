/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Fibonacci nth term in O(log(n)) time
Problem Statement :- Given a non-negative integer N and two integers A and B,
                     find the Nth term of the Fibonacci sequence A,A+B,2A+B,3A+2B,5A+3B,...
                     modular 1000000007.
Problem Category :- Dynamic Programming
Program Input Format :- N, the required term number.
                        A, denoting the 0th term of the sequence
                        B, denoting the 1st term of the sequence
Program Output Format :- The Nth term of the Fibonacci sequence, modular 1000000007.
**/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define val 1000000007
#define ll long long int
void Multiply(ll A[2][2],ll B[2][2])
{
    ll C[2][2];
    C[0][0]=((A[0][0]%val * B[0][0]%val)%val + (A[0][1]%val * B[1][0]%val)%val)%val;
    C[0][1]=((A[0][0]%val * B[0][1]%val)%val + (A[0][1]%val * B[1][1]%val)%val)%val;
    C[1][0]=((A[1][0]%val * B[0][0]%val)%val + (A[1][1]%val * B[1][0]%val)%val)%val;
    C[1][1]=((A[1][0]%val * B[0][1]%val)%val + (A[1][1]%val * B[1][1]%val)%val)%val;
    A[0][0]=C[0][0];
    A[0][1]=C[0][1];
    A[1][0]=C[1][0];
    A[1][1]=C[1][1];
    return;
}
void Exponent(ll M[2][2],ll n)
{
    if(n<=1)
        return;
    ll A[2][2];
    A[0][0]=M[0][0];
    A[0][1]=M[0][1];
    A[1][0]=M[1][0];
    A[1][1]=M[1][1];
    Exponent(M,n/2);
    Multiply(M,M);
    if(n%2==1)
        Multiply(M,A);
    return;
}
ll solve(ll a,ll b,ll n)
{
    ll M[2][2]={{0,1},{1,1}};
    if(n==0)
        return a%val;
    if(n==1)
        return b%val;
    Exponent(M,n);
    return ((a%val * M[0][0]%val)%val + (b%val * M[1][0]%val)%val)%val;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,a,b;
    fin>>a>>b>>n;
    fout<<solve(a,b,n);
    fin.close();
    fout.close();
    return 0;
}
