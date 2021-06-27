/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Rabin-Karp Searching Algorithm
Problem Statement :- Given a text and a pattern in the form of strings, find the indices at which
                     the pattern is present in the text, or print [-1,-1] if not found.
Problem Category :-  String Search Algorithms
Program Input Format :- N1, denoting number of rows and M1 denoting the number of columns in the text grid
                        N2, denoting number of rows and M2 denoting the number of columns in the pattern grid
Program Output Format :- The indices at which the pattern is present in the text and [-1,-1] if not found.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll Search(ll n1,vector<string> g1,ll n2,vector<string> g2,ll k,ll l)
{
    int i,j,a,b;
    a=n2;
    for(i=0;i<a;i++)
    {
        b=g2[i].length();
        for(j=0;j<b;j++)
            if(g2[i][j]!=g1[i+k][j+l])
                return false;
    }
    return true;
}
vector<pair<ll,ll>> solve(vector<string> g1,vector<string> g2)
{
    ll i,j,k,l,n1=g1.size(),n2=g2.size();
    k=n1-n2;
    vector<pair<ll,ll>> result={{-1,-1}};
    l=g1[0].length()-g2[0].length();
    for(i=0;i<=k;i++)
        for(j=0;j<=l;j++)
            if(g1[i][j]==g2[0][0] && Search(n1,g1,n2,g2,i,j))
            {
                if(result[0].first==-1)
                    result[0]={i,j};
                else
                result.push_back({i,j});
            }
    return result;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    ll i,n1,m1,n2,m2;
    fin>>n1>>m1;
    vector<string> g1(n1);
    for(i=0;i<n1;i++)
        fin>>g1[i];
    fin>>n2>>m2;
    vector<string> g2(n2);
    for(i=0;i<n2;i++)
        fin>>g2[i];
    vector<pair<ll,ll>> result;
    result=solve(g1,g2);
    for(auto &it:result)
        fout<<it.first<<' '<<it.second<<endl;
    fin.close();
    fout.close();
    return 0;
}
