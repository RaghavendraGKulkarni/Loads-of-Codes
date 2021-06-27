/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Car Train Problem
Problem Statement :- Given a graph with N cities and M routes connecting the cities, where each route
                     is associated with two costs, i.e. cost of traveling by car and cost of traveling
                     by train between those two cities, find the optimal path from a given source city
                     to a destination city under the constraint that exactly one train route must be used.
Problem Category :-  Graph Theory
Program Input Format :- N, denoting the number of cities and M denoting the number of routes.
                        M quadruples (u,v,c,t) denoting a car cost c and a train cost t between the cities
                        u and v.
                        S, the source city.
                        D, the destination city.
Program Output Format :- The optimal path from source city to destination city under the given constraint.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF LLONG_MAX
pair<vector<ll>,vector<ll>> Dijkstra(ll n,vector<map<ll,ll>> adj,ll s)
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
    return {dist,pred};
}
pair<ll,string> solve(ll n,vector<map<ll,ll>> car,vector<map<ll,ll>> train,ll s,ll d)
{
    ll i,j,ans=INF;
    string path;
    vector<ll> distS,predS,distD,predD;
    pair<vector<ll>,vector<ll>> result;
    result=Dijkstra(n,car,s);
    distS=result.first;
    predS=result.second;
    result=Dijkstra(n,car,d);
    distD=result.first;
    predD=result.second;
    for(i=1;i<=n;i++)
        for(auto &it:train[i])
            if(distS[i]+it.second+distD[it.first]<ans)
            {
                ans=distS[i]+it.second+distD[it.first];
                path=Path(predD,it.first);
                reverse(path.begin(),path.end());
                path=Path(predS,i)+" "+path;
            }
    return {ans,path};
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll i,n,m,u,v,c,t,s,d,length;
    string path;
    fin>>n>>m;
    vector<map<ll,ll>> car(n+1),train(n+1);
    for(i=0;i<m;i++)
    {
        fin>>u>>v>>c>>t;
        car[u][v]=c;
        car[v][u]=c;
        train[u][v]=t;
        train[v][u]=t;
    }
    fin>>s>>d;
    auto result=solve(n,car,train,s,d);
    length=result.first;
    path=result.second;
    fout<<length;
    fin.close();
    fout.close();
    return 0;
}
