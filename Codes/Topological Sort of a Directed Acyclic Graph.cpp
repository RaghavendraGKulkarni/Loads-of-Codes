/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Topological SOrt of a Direct Acyclic Graph
Problem Statement :- Given a Directed Acyclic Graph (DAG) with N vertices and M edges,
                     perform traversal to print the topological order of the vertices.
Problem Category :-  Graph Theory
Program Input Format :- N, denoting the number of vertices, M denoting the number of edges
                        M pairs (u,v) denoting the edge from vertex u to vertex v.
Program Output Format :- The sequence of vertices representing the Topological Sort.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void topologicalSort(vector<ll> adj[],vector<bool> &visited,stack<ll> &next,ll v)
{
    visited[v]=true;
    for(auto &it:adj[v])
        if(!visited[it])
            topologicalSort(adj,visited,next,it);
    next.push(v);
    return;
}
vector<ll> solve(ll n,vector<ll> adj[])
{
    ll i;
    stack<ll> next;
    vector<ll> result;
    vector<bool> visited(n+1,false);
    for(i=1;i<=n;i++)
        if(visited[i]==false)
            topologicalSort(adj,visited,next,i);
    while(!next.empty())
    {
        result.push_back(next.top());
        next.pop();
    }
    return result;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll i,n,m,u,v,s;
    fin>>n>>m;
    vector<ll> adj[n+1],result;
    for(i=0;i<m;i++)
    {
        fin>>u>>v;
        adj[u].push_back(v);
    }
    result=solve(n,adj);
    for(auto &it:result)
        fout<<it<<' ';
    fin.close();
    fout.close();
    return 0;
}
