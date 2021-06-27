/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Elements greater than given element in a Sorted Array
Problem Statement :- Given a positive integer N, a sorted sequence of N integers and an integer K,
                     find the number of integers in the sequence strictly greater than K.
Problem Category :-  Divide and Conquer
Program Input Format :- N, denoting the number of integers in the sequence.
                        N integers denoting the sorted sequence
                        K, denoting the lower bound
Program Output Format :- The number of integers in the sequence strictly greater than K.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(vector<ll> A,ll k)
{
    ll n=A.size(),l=0,h=n-1,m,ans=0;
    while(l<=h)
    {
        m=(l+h)/2;
        if(A[m]<k)
            l=m+1;
        else if(A[m]==k)
        {
            while(m<n && A[m]==k)
                m++;
            ans+=(h-m+1);
            break;
        }
        else
        {
            ans+=(h-m+1);
            h=m-1;
        }
    }
    return ans;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll i,n,k,ele;
    vector<ll> A;
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>ele;
        A.push_back(ele);
    }
    fin>>k;
    fout<<solve(A,k);
    fin.close();
    fout.close();
    return 0;
}
