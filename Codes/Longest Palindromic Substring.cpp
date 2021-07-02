/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Longest Palindromic Substring
Problem Statement :- Given a string, find the longest substring of the string which is
                     a palindrome
Problem Category :-  Dynamic Programming
Program Input Format :- The string whose longest palindromic substring is to be searched
Program Output Format :- Longest palindromic substring of the string
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string solve(string s)
{
    ll n=s.length(),i,j,k,st=-1,maxLength=-1;
    vector<vector<bool>> isPalindrome(n,vector<bool> (n,false));
    for(i=0;i<n;i++)
    {
        isPalindrome[i][i]=true;
        if(i<n-1 && s[i]==s[i+1])
        {
            isPalindrome[i][i+1]=true;
            st=i;
            maxLength=2;
        }
    }
    if(maxLength==-1)
    {
        maxLength=1;
        st=n-1;
    }
    for(k=3;k<=n;k++)
    {
        for(i=0;i<n-k+1;i++)
        {
            j=i+k-1;
            if(isPalindrome[i+1][j-1] && s[i]==s[j])
            {
                isPalindrome[i][j]=true;
                if(k>maxLength)
                {
                    st=i;
                    maxLength=k;
                }
            }
        }
    }
    return s.substr(st,maxLength);
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    string s;
    fin>>s;
    fout<<solve(s);
    fin.close();
    fout.close();
    return 0;
}
