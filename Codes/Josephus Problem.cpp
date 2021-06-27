/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Josephus Problem
Problem Statement :- N persons, numbered from 1 to N, are standing in a circle. Starting from person 1, each person
                     is selected for the next iteration, at a jump K. This is continued until only one person remains.
                     Find the number of the person who remains.
Problem Category :-  Recursion
Program Input Format :- N, denoting the number of people standing in the circle.
                        K, denoting the number of jumps taken.
Program Output Format :- The number of the person left at the end of the game.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll n,ll k)
{
    if(n==1)
        return 1;
    return (solve(n-1,k)+k-1)%n+1;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,k;
    fin>>n>>k;
    fout<<solve(n,k)<<endl;
    fin.close();
    fout.close();
    return 0;
}
