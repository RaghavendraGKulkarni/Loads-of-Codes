/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Check if a number is an ArmStrong Number
Problem Statement :- Given a positive integer N, check whether it is a ArmStrong Number,
                     i.e. sum of cubes of digits is equal to the number or not.
Problem Category :-  Mathematics
Program Input Format :- N, denoting the number to be checked.
Program Output Format :- Yes, if the number is an ArmStrong Number and No if they aren't.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string solve(ll n)
{
    ll temp=n,dig,sum=0;
    while(temp)
    {
        dig=temp%10;
        sum+=(dig*dig*dig);
        temp/=10;
    }
    if(sum==n)
        return "Yes";
    return "No";
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    ll n;
    fin>>n;
    fout<<solve(n);
    fin.close();
    fout.close();
    return 0;
}
