/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Modular Multiplicative Inverse in O(log(n)) time
Problem Statement :- Given two integers A and P, find the modular multiplicative inverse of A
                     with respect to P.
Problem Category :-  Number Theory
Program Input Format :- A, the base value
                        P, the modular value
Program Output Format :- The modular multiplicative inverse of A with respect to P.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll a,ll b,ll m)
{
    if(b==0)
        return 1;
    if(b==1)
        return a%m;
    ll temp=solve(a,b/2,m);
    temp=(temp*temp)%m;
    if(b%2==1)
        temp=(temp*a)%m;
    return temp;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll a,p;
    fin>>a>>p;
    fout<<solve(a,p-2,p);
    fin.close();
    fout.close();
    return 0;
}
