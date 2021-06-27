/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Spiral Traverse of a Matrix
Problem Statement :- Given two non-negative integers N and M and a matrix of size NxM, perform
                     spiral traversal through the matrix and print the output.
Problem Category :-  Arrays
Program Input Format :- N and M, denoting the number of rows and columns respectively.
                        A NxM matrix to perform spiral traversal on.
Program Output Format :- The resulting spiral traversal on the matrix.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void turn(ll &x,ll &y)
{
    if(x==0 && y==1)
    {
        x=1;
        y=0;
    }
    else if(x==1 && y==0)
    {
        x=0;
        y=-1;
    }
    else if(x==0 && y==-1)
    {
        x=-1;
        y=0;
    }
    else
    {
        x=0;
        y=1;
    }
    return;
}
vector<ll> solve(vector<vector<ll>> A)
{
    ll n=A.size(),m=A[0].size(),i=0,j=0,x=0,y=1;
    vector<ll> result;
    vector<vector<bool>> visited(n,vector<bool> (m,false));
    while(result.size()<(n*m))
    {
        result.push_back(A[i][j]);
        visited[i][j]=true;
        if(i+x<0 || i+x>=n || j+y<0 || j+y>=m || visited[i+x][j+y]==true)
            turn(x,y);
        i+=x;
        j+=y;
    }
    return result;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,m,i,j;
    fin>>n>>m;
    vector<vector<ll>> A(n,vector<ll> (m));
    vector<ll> result;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            fin>>A[i][j];
    result=solve(A);
    for(auto &it:result)
        fout<<it<<' ';
    fin.close();
    fout.close();
    return 0;
}
