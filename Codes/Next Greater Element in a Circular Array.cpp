/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Next Greater Element in a Circular Array
Problem Statement :- Given a positive integer N and a circular array of N integers, find the next
                     immediate larger element of every element.
Problem Category :-  Stack
Program Input Format :- N, denoting the number of elements in the circular array.
                        N integers denoting the circular array.
Program Output Format :- N integers denoting the corresponding next larger element of every element.
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
		{
			result[st.top()]=A[i];
			st.pop();
		}
		st.push(i);
    }
    for(i=0;i<n;i++)
    {
        while(!st.empty() && A[st.top()]<A[i])
		{
			result[st.top()]=A[i];
			st.pop();
		}
    }
    while(!st.empty())
    {
        result[st.top()]=-1;
        st.pop();
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

