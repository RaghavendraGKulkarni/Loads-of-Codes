/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Solving ax+by=gcd(a,b)
Problem Statement :- Given two positive integers a and b, find two positive integers
                     x and y satisfying the equation ax+by=gcd(a,b).
Problem Category :-  Number Theory
Program Input Format :- a, denoting the first number
                        b, denoting the second number
Program Output Format :- The x and y values satisfying ax+by=gcd(a,b)
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll a,ll b,ll& x,ll& y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll z=solve(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return z;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    ll ans,a,b,x,y;
    fin>>a>>b;
    ans=solve(a,b,x,y);
    fout<<"x="<<x<<" and y="<<y;
    fin.close();
    fout.close();
    return 0;
}

