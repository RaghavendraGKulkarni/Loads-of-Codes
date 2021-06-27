/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- N Queen Problem
Problem Statement :- Given a positive integer N, find the number of ways of placing N queens on a
                     NxN chess board such that no queen can attack the each other.
Problem Category :-  Recursion and Backtracking.
Program Input Format :- N, the size of the board and the number of queens.
Program Output Format :- The number of possible arrangements and the arrangements.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool attack(ll x1,ll y1,ll x2,ll y2)
{
    if(x1==x2 || y1==y2 || abs(x1-x2)==abs(y1-y2))
        return true;
    return false;
}
void place(ll n,vector<vector<char>> &board,vector<vector<vector<char>>> &result,set<pair<ll,ll>> &occupied,ll x)
{
    ll i;
    bool safe;
    if(x==n)
    {
        result.push_back(board);
        return;
    }
    for(i=0;i<n;i++)
    {
        safe=true;
        for(auto &it:occupied)
            if(attack(x,i,it.first,it.second))
            {
                safe=false;
                break;
            }
        if(safe)
        {
            board[x][i]='Q';
            occupied.insert({x,i});
            place(n,board,result,occupied,x+1);
            board[x][i]='-';
            occupied.erase({x,i});
        }
    }
    return;
}
vector<vector<vector<char>>> solve(ll n)
{
    vector<vector<char>> board(n,vector<char> (n,'-'));
    vector<vector<vector<char>>> result;
    set<pair<ll,ll>> occupied;
    place(n,board,result,occupied,0);
    return result;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,i,j;
    vector<vector<vector<char>>> result;
    fin>>n;
    result=solve(n);
    fout<<"There are "<<result.size()<<" solutions for the "<<n<<"-Queen Problem."<<endl<<endl;
    for(auto &it:result)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                fout<<it[i][j]<<' ';
            fout<<endl;
        }
        fout<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
