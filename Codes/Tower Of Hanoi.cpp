/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Tower of Hanoi
Problem Statement :- Given three towers A,B and C of equal heights and N disks of distinct sizes on tower
                     A arranged in increasing order of size, move them to tower C in the same order using
                     minimum number of moves, such that only one disk can be moved from the top of one
                     tower to other in a move and no larger disk can be placed on a smaller disk.
Problem Category :- Recursion
Program Input Format :- N, the number of disks on tower A.
Program Output Format :- The moves to be made, one per line.
**/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve(ll n,char from,char to,char aux,vector<string> &moves)
{
    string str;
    if(n==1)
    {
        str="Move disk 1 from ";
        str.push_back(from);
        str+=" to ";
        str.push_back(to);
        moves.push_back(str);
        return;
    }
    solve(n-1,from,aux,to,moves);
    str="Move disk "+to_string(n)+" from ";
    str.push_back(from);
    str+=" to ";
    str.push_back(to);
    moves.push_back(str);
    solve(n-1,aux,to,from,moves);
    return;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    vector<string> moves;
    ll n;
    fin>>n;
    solve(n,'A','C','B',moves);
    for(auto &str:moves)
        fout<<str<<endl;
    fin.close();
    fout.close();
    return 0;
}
