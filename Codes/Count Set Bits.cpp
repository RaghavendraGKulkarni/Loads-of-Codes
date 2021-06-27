/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Count Set Bits
Problem Statement :- Given an integer N, count the numbers set bits in the binary
                     representation of N.
Problem Category :-  Bit Magic
Program Input Format :- N, denoting the number in which set bits are to be counted.
Program Output Format :- The number of set bits in binary representation of N.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll n)
{
    ll bits=0;
    while(n)
    {
        if((n&1)==1)
            bits++;
        n>>=1;
    }
    return bits;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n;
    fin>>n;
    fout<<solve(n)<<endl;
    fin.close();
    fout.close();
    return 0;
}
