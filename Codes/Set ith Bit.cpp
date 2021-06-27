/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Set ith bit
Problem Statement :- Given an integer N and a non-negative integer i, set the ith bit
                     in the binary representation of N to 1.
Problem Category :-  Bit Magic
Program Input Format :- N, denoting the number in which bit is to be set.
                        i, the bit number to be set.
Program Output Format :- The resulting number after setting the ith bit.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll n,ll i)
{
    n=(n|(1<<i));
    return n;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,i;
    fin>>n>>i;
    fout<<solve(n,i)<<endl;
    fin.close();
    fout.close();
    return 0;
}
