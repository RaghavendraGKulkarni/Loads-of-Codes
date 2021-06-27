/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Check if two strings are anagrams are not
Problem Statement :- Given two strings, check whether they are anagrams or not, i.e. one
                     of them can be rearranged into another.
Problem Category :-  Strings
Program Input Format :- s1, the first string
                        s2, the second string
Program Output Format :- Yes, if they are anagram and No if they aren't.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string solve(string s1,string s2)
{
    if(s1.length()!=s2.length())
        return "No";
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if(s1==s2)
        return "Yes";
    return "No";
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    string s1,s2;
    fin>>s1>>s2;
    fout<<solve(s1,s2);
    fin.close();
    fout.close();
    return 0;
}
