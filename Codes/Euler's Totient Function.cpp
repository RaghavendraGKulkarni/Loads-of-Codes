/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Euler's Totient Function
Problem Statement :- Given a positive integer N, compute the Euler's Totient Function for N,
                     i.e. the number of integers in the range (1,N) which are co-prime to N.
Problem Category :-  Number Theory
Program Input Format :- N, denoting the number whose Euler's Totient Function is to be computed.
Program Output Format :- Number of integers in the range (1,N) which are co-prime to N.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll n)
{
    ll p,result=n;
    for(p=2;p*p<=n;p++)
    {
        if(n%p==0)
        {
            while(n%p==0)
                n/=p;
            result-=result/p;
        }
    }
    if(n>1)
        result-=result/n;
    return result;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n;
    fin>>n;
    fout<<solve(n);
    fin.close();
    fout.close();
    return 0;
}
