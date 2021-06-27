/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Queue using two Stacks
Problem Statement :- Given a positive integer t, implement a queue using two stacks in the form of
                     t queries, where each query is of the form:-
                     01) 01 x :- enqueue x into the queue
                     02) 02 :- dequeue an element from the queue
                     03) 03 :- print the front element
Problem Category :-  Queue and Stack
Program Input Format :- T, denoting the number of queries
                        T queries in the format described above
Program Output Format :- Front element of all the type 03 queries.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> solve(vector<pair<ll,ll>> queries)
{
    ll t=queries.size(),i;
    stack<ll> s1,s2;
    vector<ll> result;
    for(i=0;i<t;i++)
    {
        if(queries[i].first==1)
            s2.push(queries[i].second);
        else
        {
            if(s1.empty())
            {
                while(!s2.empty())
                {
                    s1.push(s2.top());
                    s2.pop();
                }
            }
            if(queries[i].first==2)
                s1.pop();
            else
                result.push_back(s1.top());
        }
    }
    return result;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll t,i;
    vector<ll> result;
    fin>>t;
    vector<pair<ll,ll>> queries(t);
    for(i=0;i<t;i++)
    {
        fin>>queries[i].first;
        if(queries[i].first==1)
            fin>>queries[i].second;
        else
            queries[i].second=-1;
    }
    result=solve(queries);
    for(auto &it:result)
        fout<<it<<' ';
    fin.close();
    fout.close();
    return 0;
}
