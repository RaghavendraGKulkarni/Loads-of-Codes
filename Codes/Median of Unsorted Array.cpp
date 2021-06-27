/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Median of Unsorted Array
Problem Statement :- Given a positive integer N and a sequence of N integers, find the median of the
                     sequence without sorting the sequence.
Problem Category :-  Queue(Priority Queue)
Program Input Format :- N, denoting the number integers in the sequence
                        N integers denoting the sequence
Program Output Format :- The median of the sequence.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
float solve(vector<ll> &A)
{
    float median;
    priority_queue<ll> left;
    priority_queue<ll,vector<ll>,greater<ll>> right;
    int i;
    for(i=0;i<A.size();i++)
    {
        if(i==0)
            median=A[i];
        else if(i%2==1)
        {
            if(A[i]<median)
            {
                left.push(A[i]);
                right.push(median);
            }
            else
            {
                right.push(A[i]);
                left.push(median);
            }
            median=(left.top()+right.top())/2.0;
        }
        else
        {
            if(A[i]<median)
            {
                left.push(A[i]);
                median=left.top();
                left.pop();
            }
            else
            {
                right.push(A[i]);
                median=right.top();
                right.pop();
            }
        }
    }
    return median;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll i,j,n,ele;
    vector<ll> A;
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>ele;
        A.push_back(ele);
    }
    fout<<solve(A);
    fin.close();
    fout.close();
    return 0;
}
