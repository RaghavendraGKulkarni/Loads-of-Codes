/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Check if ith bit in a number is set
Problem Statement :- Given an integer N and a non-negative integer i, check if the ith bit in the
                     binary representation of N is set or not.
Problem Category :-  Bit Magic
Program Input Format :- N, denoting the number in which bit is to be checked.
                        i, the bit number to be checked.
Program Output Format :- Yes if the bit is set and No otherwise.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string solve(ll n,ll i)
{
    if((n&(1<<i))==0)
        return "No";
    return "Yes";
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
