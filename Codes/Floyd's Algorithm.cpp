/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Floyd's Algorithm
Problem Statement :- Given a graph with N vertices and M edges, perform Floyd's Algorithm to
                     find the shortest distance between every pair of vertices given that there
                     exists no cycle with negative weight sum.
Problem Category :-  Graph Theory
Program Input Format :- N, denoting the number of vertices, M denoting the number of edges and type
                        denoting whether the graph is directed('D') or undirected('U').
                        M triplets (u,v,w) denoting the edge from vertex u to vertex v with weight w.
Program Output Format :- The matrix denoting shortest distance between every pair of vertices.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF LLONG_MAX
void solve(ll n,vector<vector<ll>> &A)
{
    int k,i,j;
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if (A[i][j]>(A[i][k]+A[k][j]) && A[k][j]!=INF && A[i][k]!=INF)
                    A[i][j]=A[i][k]+A[k][j];
    return;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll i,j,n,m,u,v,w;
    char type;
    fin>>n>>m>>type;
    vector<vector<ll>> A(n,vector<ll> (m,INF));
    for(i=0;i<n;i++)
        A[i][i]=0;
    for(i=0;i<m;i++)
    {
        fin>>u>>v>>w;
        A[u][v]=min(A[u][v],w);
        if(type=='U')
            A[v][u]=min(A[v][u],w);
    }
    solve(n,A);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            fout<<A[i][j]<<' ';
        fout<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
