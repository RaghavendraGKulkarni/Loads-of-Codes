/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Non Constructible Change
Problem Statement :- Given a positive integer N and a sequence of N integers denoting the
                     denominations available, find the minimum amount that cannot be created
                     using these denominations.
Problem Category :-  Dynamic Programming
Program Input Format :- N, denoting the number of coins.
                        N integers denoting the coin values.
Program Output Format :- Minimum sum amount that cannot be created.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(vector<ll> A)
{
    ll result=0;
    sort(A.begin(),A.end());
	for(auto &it:A)
	{
		if(it>result+1)
			return result+1;
		result+=it;
	}
    return result+1;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
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
