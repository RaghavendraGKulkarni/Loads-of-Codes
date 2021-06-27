/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Triplet Sum
Problem Statement :- Given a positive integer N and a sequence of N integers, find all unique
                     triplets of the array which sum up to a given value K.
Problem Category :-  Arrays
Program Input Format :- N, denoting the number of elements in the array.
                        N integers denoting the array elements
                        K, denoting the target sum
Program Output Format :- The triplets, each in one line.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> solve(vector<ll> A,ll k)
{
    ll i,l,r;
    vector<vector<ll>> result;
	sort(A.begin(),A.end());
	for(i=0;i<A.size()-2;i++)
	{
		l=i+1;
		r=A.size()-1;
		while(l<r)
		{
			if(A[i]+A[l]+A[r]==k)
			{
				result.push_back({A[i],A[l],A[r]});
				l++;
				r--;
			}
			else if(A[i]+A[l]+A[r]<k)
				l++;
			else
				r--;
		}
	}
	return result;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ll n,i,k;
    vector<vector<ll>> result;
    fin>>n;
    vector<ll> A(n);
    for(i=0;i<n;i++)
        fin>>A[i];
    fin>>k;
    result=solve(A,k);
    for(auto &it:result)
        fout<<it[0]<<' '<<it[1]<<' '<<it[2]<<endl;
    fin.close();
    fout.close();
    return 0;
}
