/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Count of subsets with given sum
Problem Statement :- Given a positive integer N and a set of N integers, find the number of
                     subsets of the set which sum to K.
Problem Category :-  Dynamic Programming
Program Input Format :- N, denoting the number of elements in the set.
                        N integers denoting the set.
                        K, denoting the sum to be summed up.
Program Output Format :- Number of subsets of the set with the given sum.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll n,vector<ll> A,ll sum)
{
    ll i,j;
    vector<vector<ll>> arr(n+1,vector<ll> (sum+1));
    for(i=0;i<=n;i++)
    {
        arr[i][0]=1;
        if(i>0)
            arr[0][i]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=sum;j++)
        {
            if(j<A[i-1])
                arr[i][j]=arr[i-1][j];
            else
                arr[i][j]=arr[i-1][j]+arr[i-1][j-A[i-1]];
        }
    }
    return arr[n][sum];
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
    for(i=0;i<n;i++)
        fin>>A[i];
    fin>>sum;
    fout<<solve(n,A,sum);
    fin.close();
    fout.close();
    return 0;
}
