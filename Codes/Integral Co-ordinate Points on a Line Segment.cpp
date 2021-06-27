/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Integral Co-ordinate Points on a Line Segment
Problem Statement :- Given two points with integral co-ordinates on a 2D plane denoting a line segment,
                     count the number of points with integral co-ordinates on the line segment.
Problem Category :-  Number Theory
Program Input Format :- x1, denoting the x-coordinate of the first point
                        y1, denoting the y-coordinate of the first point
                        x2, denoting the x-coordinate of the second point
                        y2, denoting the y-coordinate of the second point
Program Output Format :- The number of points with integral co-ordinates on the line segment.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
ll solve(ll n)
{
    if(x1==x2)
        return abs(y1-y2)-1;
    if(y1==y2)
        return abs(x1-x2)-1;
    return gcd(abs(x1-x2),abs(y1-y2))-1;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll x1,y1,x2,y2;
    fin>>x1>>y1>>x2>>y2;
    fout<<solve(x1,y1,x2,y2);
    fin.close();
    fout.close();
    return 0;
}
