/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Long Factorials
Problem Statement :- Given a non-negative integer N<=600, find the factorial of N.
Problem Category :-  Arrays
Program Input Format :- N, denoting the number whose factorial is to be found.
Program Output Format :- The factorial of the number.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> solve(ll n)
{
    ll i,j,carry,temp;
    vector<ll> result;
    result.push_back(1);
    for(i=1;i<=n;i++)
    {
        carry=0;
        for(j=result.size()-1;j>=0;j--)
        {
            temp=(result[j]*i+carry)%10;
            carry=(result[j]*i+carry)/10;
            result[j]=temp;
        }
        if(carry>0)
            result.insert(result.begin(),carry);
    }
    return result;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,i;
    vector<ll> fact;
    fin>>n;
    fact=solve(n);
    for(i=0;i<fact.size();i++)
    {
        if(i>0 && i%100==0)
            fout<<"\n";
        fout<<fact[i];
    }
    fin.close();
    fout.close();
    return 0;
}
