/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Gaming Array
Problem Statement :- There is an unsorted array of integers and the game starts with player 1.
                     Each player alternatively gets a turn in which he/she selects the largest element
                     from the array and erases all the elements to the right side of it, along with
                     the largest element. The player who makes the last move, i.e. after whose turn
                     the array becomes empty, wins the game. Given a positive integer N and an unsorted
                     array of N integers, determine the winner of the game.
Problem Category :-  Stack
Program Input Format :- N, denoting the number of elements in the array.
                        N integers denoting the array elements
Program Output Format :- The number of the winning player.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(vector<ll> A)
{
    stack<ll> st;
    ll i,n=A.size();
    for(i=0;i<n;i++)
        if(st.empty() || A[i]>st.top())
            st.push(A[i]);
    if((st.size())%2==0)
        return 2;
    return 1;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,i;
    fin>>n;
    vector<ll> A(n);
    for(i=0;i<n;i++)
        fin>>A[i];
    fout<<solve(A);
    fin.close();
    fout.close();
    return 0;
}
