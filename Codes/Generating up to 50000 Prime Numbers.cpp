/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Generating up to 50000 Prime Numbers
Problem Statement :- Given a positive integer T and T queries each in the form an integer 1<=N<=50000
                     print the Nth prime number.
Problem Category :-  Number Theory
Program Input Format :- T, denoting the number of queries.
                        T integers denoting the queries.
Program Output Format :- The list of prime numbers answering each query.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define BUFSIZE 1000000
vector<ll> sieve()
{
    ll i,j;
    vector<ll> primes;
    vector<bool> isPrime(BUFSIZE,true);
    isPrime[0]=false;
    isPrime[1]=false;
    for(i=2;i<BUFSIZE;i++)
        if(isPrime[i])
        {
            for(j=i*i;j<BUFSIZE;j+=i)
                isPrime[j]=false;
            primes.push_back(i);
        }
    return primes;
}
vector<ll> solve(vector<ll> queries)
{
    vector<ll> result,primes;
    primes=sieve();
    for(auto &it:queries)
        result.push_back(primes[it-1]);
    return result;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll t,i;
    fin>>t;
    vector<ll> queries(t),result;
    for(i=0;i<t;i++)
        fin>>queries[i];
    result=solve(queries);
    for(auto &it:result)
        fout<<it<<endl;
    fin.close();
    fout.close();
    return 0;
}
