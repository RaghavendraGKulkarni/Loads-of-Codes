/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Previous Greater Element in an Array
Problem Statement :- Given a positive integer N and an array of N integers, find the previous
                     immediate greater element of every element.
Problem Category :-  Stack
Program Input Format :- N, denoting the number elements in the array.
                        N integers denoting the array.
Program Output Format :- N integers denoting the corresponding previous greater element of every element.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> solve(vector<ll> A)
{
    ll i,x,n=A.size();
    stack<ll> st;
    vector<ll> result(n);
    for(i=0;i<n;i++)
    {
        while(!st.empty() && A[st.top()]<A[i])
			st.pop();
		if(st.empty())
            result[i]=-1;
        else
            result[i]=A[st.top()];
		st.push(i);
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
    fin>>n;
    vector<ll> A(n),result;
    for(i=0;i<n;i++)
        fin>>A[i];
    result=solve(A);
    for(i=0;i<n;i++)
        fout<<A[i]<<" --> "<<result[i]<<endl;
    fin.close();
    fout.close();
    return 0;
}
