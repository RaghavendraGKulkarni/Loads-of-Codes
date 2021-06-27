/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Fibonacci nth term in O(2^n) time
Problem Statement :- Given a non-negative integer N and two integers A and B,
                     find the Nth term of the Fibonacci sequence A,A+B,2A+B,3A+2B,5A+3B,...
                     modular 1000000007.
Problem Category :- Recursion
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
ll solve(ll a,ll b,ll n)
{
    if(n==0)
        return a%val;
    if(n==1)
        return b%val;
    return (solve(a,b,n-1)+solve(a,b,n-2))%val;
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

