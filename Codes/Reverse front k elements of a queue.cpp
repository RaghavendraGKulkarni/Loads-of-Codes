/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Reverse front k elements of a queue
Problem Statement :- Given a positive integer N and a queue of N integers, reverse the order of
                     first K elements at the front.
Problem Category :-  Queues and Stacks
Program Input Format :- N, denoting the number of integers in the sequence.
                        K, denoting the number of elements to be reversed
                        N integers denoting the queue, from front to rear.
Program Output Format :- The resulting queue from front to rear.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve(queue<ll> &q,ll k)
{
    ll i,rem=q.size()-k,var;
    stack<ll> temp;
    for(i=0;i<k;i++)
    {
        temp.push(q.front());
        q.pop();
    }
    while(!temp.empty())
    {
        q.push(temp.top());
        temp.pop();
    }
    for(i=0;i<rem;i++)
    {
        var=q.front();
        q.pop();
        q.push(var);
    }
    return;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll i,k,n,ele;
    queue<ll> q;
    fin>>n>>k;
    for(i=0;i<n;i++)
    {
        fin>>ele;
        q.push(ele);
    }
    solve(q,k);
    while(!q.empty())
    {
        fout<<q.front()<<' ';
        q.pop();
    }
    fin.close();
    fout.close();
    return 0;
}
