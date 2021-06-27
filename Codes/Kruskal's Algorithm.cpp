/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Kruskal's Algorithm
Problem Statement :- Given a graph with N vertices and M weighted edges, find the weight of the Minimum
                     Spanning Tree using the Kruskal's Algorithm.
Problem Category :-  Graph Theory
Program Input Format :- N, denoting the number of vertices, M denoting the number of edges and type
                        denoting whether the graph is directed('D') or undirected('U').
                        M triplets (u,v,w) denoting the edge from vertex u to vertex v with weight w.
Program Output Format :- The total weight of the Minimum Spanning Tree.
**/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll findParent(vector<ll> par,ll x)
{
    while(par[x]!=x)
    {
        par[x]=par[par[x]];
        x=par[x];
    }
    return x;
}
void Union(vector<ll> par,vector<ll> ran,ll x,ll y)
{
    x=findParent(par,x);
    y=findParent(par,y);
    if(ran[x]>ran[y])
        par[y]=x;
    else if(ran[y]>ran[x])
        par[x]=y;
    else
    {
        par[x]=y;
        ran[y]+=1;
    }
    return;
}
ll solve(ll n,vector<pair<ll,pair<ll,ll>>> edges)
{
    ll i,sum=0;
    vector<ll> par(n+1),ran(n+1,0);
    for(i=1;i<=n;i++)
        par[i]=i;
    sort(edges.begin(),edges.end());
    for(auto &edge:edges)
    {
        if(findParent(par,edge.second.first)!=findParent(par,edge.second.second))
        {
            sum+=edge.first;
            Union(par,ran,edge.second.first,edge.second.second);
        }
    }
    return sum;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    vector<pair<ll,pair<ll,ll>>> edges;
    ll t,n,m,u,v,w,i;
    char type;
    fin>>n>>m>>type;
    for(i=0;i<m;i++)
    {
        fin>>u>>v>>w;
        edges.push_back({w,{u,v}});
        if(type=='U')
            edges.push_back({w,{u,v}});
    }
    fout<<solve(n,edges)<<endl;
    fin.close();
    fout.close();
    return 0;
}
