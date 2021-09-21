/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Prim's Algorithm
Problem Statement :- Given a graph with N vertices and M weighted edges, find the total weight of
                     the Minimum Spanning Tree using Prim's Algorithm.
Problem Category :-  Graph Theory
Program Input Format :- N, denoting the number of vertices, M denoting the number of edges and type
                        denoting whether the graph is directed('D') or undirected('U').
                        M triplets (u,v,w) denoting the edge from vertex u to vertex v with weight w.
Program Output Format :- The total weight of the Minimum Spanning Tree.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF LLONG_MAX
ll solve(ll n,vector<map<ll,ll>> adj,ll s)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    vector<ll> dist(n+1,INF),pred(n+1,s);
    vector<bool> visited(n+1,false);
    ll next,MST=0,count=n;
    pq.push({0,s});
    dist[s]=0;
    while(n>0 && !pq.empty())
    {
        next=pq.top().second;
        MST+=pq.top().first;
        visited[next]=true;
        n--;
        pq.pop();
        for(auto &it:adj[next])
            if(visited[it.first]==false && dist[it.first]>it.second)
            {
                dist[it.first]=it.second;
                pred[it.first]=next;
                pq.push(make_pair(dist[it.first],it.first));
            }
    }
    for(int i=1;i<=n;i++)
        if(dist[i]==LLONG_MAX)
            dist[i]=-1;
    return MST;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll i,n,m,u,v,w,s;
    char type;
    fin>>n>>m>>type;
    vector<map<ll,ll>> adj(n+1);
    vector<ll> dist,pred;
    for(i=0;i<m;i++)
    {
        fin>>u>>v>>w;
        if(adj[u][v]==0)
            adj[u][v]=w;
        else
            adj[u][v]=min(adj[u][v],w);
        if(type=='U')
        {
            if(adj[v][u]==0)
                adj[v][u]=w;
            else
                adj[v][u]=min(adj[v][u],w);
        }
    }
    fin>>s;
    fout<<solve(n,adj,s);
    fin.close();
    fout.close();
    return 0;
}
