/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Dijkstra's Algorithm
Problem Statement :- Given a graph with N vertices and M weighted edges, find the shortest path from a given
                     source S to all other vertices of the graph using Dijkstra's Algorithm.
Problem Category :-  Graph Theory
Program Input Format :- N, denoting the number of vertices and M denoting the number of edges.
                        M triplets (u,v,w) denoting the edge from vertex u to vertex v with weight w.
                        S, the source to find the shortest path from.
Program Output Format :- The shortest distance to every vertex from the source along with the path.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF LLONG_MAX
pair<vector<ll>,vector<ll>> solve(ll n,vector<map<ll,ll>> adj,ll s)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    vector<ll> dist(n+1,INF),pred(n+1,s);
    vector<bool> visited(n+1,false);
    ll next;
    pq.push(make_pair(0,s));
    dist[s]=0;
    while(!pq.empty())
    {
        next=pq.top().second;
        pq.pop();
        visited[next]=true;
        for(auto &it:adj[next])
            if(visited[it.first]==false && dist[it.first]>dist[next]+it.second)
            {
                dist[it.first]=dist[next]+it.second;
                pred[it.first]=next;
                pq.push(make_pair(dist[it.first],it.first));
            }
    }
    for(int i=1;i<=n;i++)
        if(dist[i]==LLONG_MAX)
            dist[i]=-1;
    return {dist,pred};
}
string Path(vector<ll> pred,ll node)
{
    if(pred[node]!=node)
        return Path(pred,pred[node])+"->"+to_string(node);
    return to_string(node);
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll i,n,m,u,v,w,s;
    fin>>n>>m;
    vector<map<ll,ll>> adj(n+1);
    vector<ll> dist,pred;
    pair<vector<ll>,vector<ll>> result;
    for(i=0;i<m;i++)
    {
        fin>>u>>v>>w;
        if(adj[u][v]==0)
            adj[u][v]=w;
        else
            adj[u][v]=min(adj[u][v],w);
        if(adj[v][u]==0)
            adj[v][u]=w;
        else
            adj[v][u]=min(adj[v][u],w);
    }
    fin>>s;
    result=solve(n,adj,s);
    dist=result.first;
    pred=result.second;
    for(i=1;i<=n;i++)
    {
        if(dist[i]!=-1)
            fout<<"Shortest Distance from "<<s<<" to "<<i<<" is "<<dist[i]<<" through the path "<<Path(pred,i)<<endl;
        else
            fout<<"No path from "<<s<<" to "<<i<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
