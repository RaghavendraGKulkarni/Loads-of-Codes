/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Sum vs XOR
Problem Statement :- Given an integer N, find the number of solutions X, for the equation,
                     N+X=N^X in the range [0,N].
Problem Category :-  Bit Magic
Program Input Format :- N, denoting the right limit of the range.
Program Output Format :- The number of solutions to the equation.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll n)
{
    ll count=0;
    while(n)
    {
        if((n&1)==0)
            count++;
        n>>=1;
    }
    return (1<<count);
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,i;
    fin>>n;
    fout<<solve(n)<<endl;
    fin.close();
    fout.close();
    return 0;
}

