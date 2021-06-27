/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Determinant of a Matrix in O(n^3) time and O(n) space
Problem Statement :- Given two integers N and M, and a matrix of size NxM, calculate the determinant
                     of the matrix.
Problem Category :-  Arrays
Program Input Format :- N, denoting the number of rows.
                        M, denoting the number of columns.
                        An NxM matrix whose determinant is to be calculated.
Program Output Format :- The determinant of the matrix.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll n,vector<vector<ll>> A)
{
    ll num1,num2,det=1,index,i,j,k,total=1;
    vector<ll> temp(n+1);
    for(i=0;i<n;i++)
    {
        index=i;
        while(index<n && A[index][i]==0)
            index++;
        if(index==n)
            continue;
        if(index!=i)
        {
            for(j=0;j<n;j++)
                swap(A[index][j],A[i][j]);
            det=det*pow(-1,index-i);
        }
        for(j=0;j<n;j++)
            temp[j]=A[i][j];
        for(j=i+1;j<n;j++)
        {
            num1=temp[i];
            num2=A[j][i];
            for(k=0;k<n;k++)
                A[j][k]=(num1*A[j][k])-(num2*temp[k]);
            total=total*num1;
        }
    }
    for(i=0;i<n;i++)
        det=det*A[i][i];
    return (det/total);
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,m,i,j;
    fin>>n>>m;
    if(n!=m)
        fout<<"Determinant does not exist for non-square matrix";
    else
    {
        vector<vector<ll>> A(n,vector<ll> (m));
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                fin>>A[i][j];
        fout<<solve(n,A);
    }
    fin.close();
    fout.close();
    return 0;
}
