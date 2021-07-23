/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Minimum coins for an amount using given denominations
Problem Statement :- Given a positive integer N and N coins of different values, find the
                     minimum number of coins to sum an amount K.
Problem Category :-  Dynamic Programming
Program Input Format :- N, denoting the number of coins.
                        N integers denoting the coin values.
                        K, denoting the amount to be summed up.
Program Output Format :- Minimum number of coins to sum an amount K.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll coins,vector<ll> denominations,ll amount)
{
    ll i,j;
    vector<vector<ll>> dp(coins+1,vector<ll> (amount+1));
    for(i=0;i<=coins;i++)
        dp[i][0]=0;
    for(i=1;i<=amount;i++)
        dp[0][i]=-1;
    for(i=1;i<=coins;i++)
        for(j=1;j<=amount;j++)
        {
            if(j<denominations[i-1])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=1+min(dp[i-1][j-denominations[i-1]],dp[i][j-denominations[i-1]]);
        }
    return dp[coins][amount];
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll coins,amount,i;
    fin>>coins;
    vector<ll> denominations(coins);
    for(i=0;i<coins;i++)
        fin>>denominations[i];
    fin>>amount;
    fout<<solve(coins,denominations,amount);
    fin.close();
    fout.close();
    return 0;
}
