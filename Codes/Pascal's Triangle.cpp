/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Pascal's Triangle
Problem Statement :- Given a positive integer N, print the first N rows of the pascal triangle.
Problem Category :-  Dynamic Programming
Program Input Format :- N, denoting the number of rows to be printed.
Program Output Format :- First N rows of Pascal's Triangle, each in one line.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> solve(ll n)
{
    ll i,j;
    vector<vector<ll>> result;
    vector<ll> row;
    row.push_back(1);
    result.push_back(row);
    for(i=1;i<=n;i++)
    {
        row.push_back(0);
        for(j=i;j>0;j--)
            row[j]=row[j]+row[j-1];
        result.push_back(row);
    }
    return result;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll i,n,j;
    vector<vector<ll>> result;
    fin>>n;
    result=solve(n);
    for(i=0;i<result.size();i++)
    {
        for(j=0;j<result[i].size();j++)
        {
            fout<<result[i][j];
            if(j<result[i].size()-1)
                fout<<' ';
        }
        if(i<result.size()-1)
            fout<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
