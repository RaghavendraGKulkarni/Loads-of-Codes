/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- BFS Traversal
Problem Statement :- Given a graph with N vertices and M edges, perform Breadth First Search Traversal
                     on the graph and print the vertices starting from a given source S.
Problem Category :-  Graph Theory
Program Input Format :- N, denoting the number of vertices, M denoting the number of edges and type
                        denoting whether the graph is directed('D') or undirected('U').
                        M pairs (u,v) denoting the edge from vertex u to vertex v.
                        S, the source to start the BFS traversal with.
Program Output Format :- The sequence of vertices representing the BFS Traversal.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> solve(ll n,vector<ll> adj[],ll s)
{
    ll k;
    queue<ll> next;
    vector<ll> result;
    vector<bool> visited(n+1,false);
    visited[s]=true;
    next.push(s);
    while(next.empty()==false)
    {
        k=next.front();
        result.push_back(k);
        next.pop();
        for(auto it:adj[k])
            if(visited[it]==false)
            {
                visited[it]=true;
                next.push(it);
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
    ll i,n,m,u,v,s;
    char type;
    fin>>n>>m>>type;
    vector<ll> adj[n+1],result;
    for(i=0;i<m;i++)
    {
        fin>>u>>v;
        adj[u].push_back(v);
        if(type=='U')
            adj[v].push_back(u);
    }
    fin>>s;
    result=solve(n,adj,s);
    for(auto &it:result)
        fout<<it<<' ';
    fin.close();
    fout.close();
    return 0;
}
