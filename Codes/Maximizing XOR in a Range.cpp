/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Maximizing XOR in a Range
Problem Statement :- Given two integers L and R, find the maximum value of XOR of any two integers
                     in the range [L,R].
Problem Category :-  Bit Magic
Program Input Format :- L and R denoting the left and right limits of the range.
Program Output Format :- The maximized XOR value.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
pair<pair<ll,ll>,ll> solve(ll left,ll right)
{
    ll result=1,temp,common,bits=0,first=0,second=0;
    temp=left^right;
    while(temp)
    {
        temp>>=1;
        result<<=1;
        bits++;
    }
    result-=1;
    common=(left&(~result));
    if(bits>0)
    {
        first=(1<<(bits-1));
        second=first-1;
    }
    first+=common;
    second+=common;
    return {{first,second},result};
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll l,r;
    pair<pair<ll,ll>,ll> result;
    fin>>l>>r;
    result=solve(l,r);
    fout<<result.first.first<<" ^ "<<result.first.second<<" = "<<result.second;
    fin.close();
    fout.close();
    return 0;
}
