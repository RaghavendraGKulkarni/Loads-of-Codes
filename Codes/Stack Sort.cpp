/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Stack Sort
Problem Statement :- Given a positive integer N and a sequence of N integers, sort the integers using
                     the Stack Sort technique.
Problem Category :-  Sorting and Stack
Program Input Format :- N, denoting the number of integers in the sequence.
                        N integers denoting the sequence
Program Output Format :- The resulting sorted sequence.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void push(vector<int> &A,int x)
{
	if(A.size()==0 || x>*A.rbegin())
		A.push_back(x);
	else
	{
		int temp=*A.rbegin();
		A.pop_back();
		push(A,x);
		A.push_back(temp);
	}
	return;
}
void solve(vector<int> &A)
{
    if(A.size()>0)
	{
		int temp=*A.rbegin();
		A.pop_back();
		solve(A);
		push(A,temp);
	}
	return;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    int i,j,n,ele;
    vector<int> A;
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>ele;
        A.push_back(ele);
    }
    solve(A);
    for(i=0;i<n;i++)
        fout<<A[i]<<' ';
    fin.close();
    fout.close();
    return 0;
}
