/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Recursive Reversing of a String
Problem Statement :- Given a string, reverse the string using a recursive function
Problem Category :-  Recursion
Program Input Format :- String to be reversed
Program Output Format :- Reversed String
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve(string &s,ll k,ll l)
{
    if(k<l)
    {
        swap(s[k],s[l]);
        solve(s,k+1,l-1);
    }
    return;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    string s;
    ll n;
    fin>>s;
    n=s.length();
    solve(s,0,n-1);
    fout<<s;
    fin.close();
    fout.close();
    return 0;
}
