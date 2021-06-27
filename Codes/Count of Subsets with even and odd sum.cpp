/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Count of subsets with even and odd sum
Problem Statement :- Given a positive integer N and a set of N integers, find the number of
                     subsets of the set which have an even sum and number of subsets which
                     have an odd sum.
Problem Category :-  Dynamic Programming
Program Input Format :- N, denoting the number of elements in the set.
                        N integers denoting the set.
Program Output Format :- Number of subsets of the set with even sum and number of subsets with
                         odd sum.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
pair<ll,ll> solve(ll n,vector<ll> A)
{
    ll i,even=0,odd=0,temp;
    for(i=0;i<n;i++)
    {
        if(A[i]%2==0)
        {
            even+=(even+1);
            odd*=2;
        }
        else
        {
            temp=even;
            even+=odd;
            odd+=(temp+1);
        }
    }
    return {even,odd};
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll i,n,sum;
    fin>>n;
    vector<ll> A(n);
    pair<ll,ll> result;
    for(i=0;i<n;i++)
        fin>>A[i];
    fin>>sum;
    result=solve(n,A,sum);
    fout<<result.first<<" subsets with even sum"<<endl;
    fout<<result.second<<" subsets with odd sum";
    fin.close();
    fout.close();
    return 0;
}

