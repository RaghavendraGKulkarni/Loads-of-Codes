/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Degree of Nodes in a graph
Problem Statement :- Given a graph with N vertices and M edges, find the degree of all the nodes
                     with respect to a given source S.
Problem Category :-  Graph Theory
Program Input Format :- N, denoting the number of vertices, M denoting the number of edges and type
                        denoting whether the graph is directed('D') or undirected('U').
                        M pairs (u,v) denoting the edge from vertex u to vertex v.
                        S, the source with respect to which the degree of all the nodes is to be found.
Program Output Format :- A sequence of pairs where the vertices map to the degree.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<pair<ll,ll>> solve(ll n,vector<ll> adj[],ll s)
{
    ll level,node;
    queue<pair<ll,ll>> next;
    vector<pair<ll,ll>> result;
    vector<bool> visited(n+1,false);
    visited[s]=true;
    next.push({s,0});
    while(next.empty()==false)
    {
        auto &it=next.front();
        node=it.first;
        level=it.second;
        result.push_back({node,level});
        next.pop();
        for(auto &it:adj[node])
            if(visited[it]==false)
            {
                visited[it]=true;
                next.push({it,level+1});
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
    vector<pair<ll,ll>> result;
    fin>>n>>m>>type;
    vector<ll> adj[n+1];
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
        fout<<it.first<<' '<<it.second<<endl;
    fin.close();
    fout.close();
    return 0;
}
