/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Largest Area in an Histogram
Problem Statement :- Given an Histogram in the form of a sequence of integers which are the heights
                     of the Histogram bars, find the area of the largest rectangle that would fit
                     in the Histogram.
Problem Category :-  Stack
Program Input Format :- N, denoting the number of bars in the Histogram
                        N integers denoting the height of the bars
Program Output Format :- Area of the largest rectangle that would fit in the Histogram.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(vector<ll> A)
{
    stack<ll> st;
    ll i=0,maxArea=0,top,areaTop,n=A.size();
    while(i<n)
    {
        if(st.empty() || A[st.top()]<=A[i])
            st.push(i++);
        else
        {
            top=st.top();
            st.pop();
            areaTop=A[top]*(st.empty() ? i : i-st.top()-1);
            if(maxArea<areaTop)
                maxArea=areaTop;
        }
    }
    while(!st.empty())
    {
        top=st.top();
        st.p0op();
        areaTop=A[top]*(st.empty() ? i : i-st.top()-1);
        if(maxArea<areaTop)
            maxArea=areaTop;
    }
    return maxArea;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,i;
    fin>>n;
    vector<ll> A(n);
    for(i=0;i<n;i++)
        fin>>A[i];
    fout<<solve(A);
    fin.close();
    fout.close();
    return 0;
}
