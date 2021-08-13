/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Sliding Window Maximum of given size
Problem Statement :- Given a positive integer N and a sequence of N integers, find the
                     maximums of all possible sub-arrays of given size K.
Problem Category :-  Queue
Program Input Format :- N and K, denoting the number of elements in the sequence and window size
                        N integers denoting the sequence
Program Output Format :- N integers denoting the maximum of each sub-array of size K.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> solve(vector<ll> A,ll k)
{
    ll i,n=A.size();
    deque<ll> dq(k);
    vector<ll> result;
    for(i=0;i<k;i++)
    {
        while((!dq.empty()) && A[i]>=A[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    for(i=k;i<n;i++)
    {
        result.push_back(A[dq.front()]);
        while((!dq.empty()) && dq.front()<=i-k)
            dq.pop_front();
        while((!dq.empty()) && A[i]>=A[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    result.push_back(A[dq.front()]);
    return result;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,k,i;
    fin>>n>>k;
    vector<ll> A(n),result;
    for(i=0;i<n;i++)
        fin>>A[i];
    result=solve(A,k);
    for(auto &it:result)
        fout<<it<<' ';
    fin.close();
    fout.close();
    return 0;
}
