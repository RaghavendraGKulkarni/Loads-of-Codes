/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- MinMax Stack
Problem Statement :- Given a positive integer T and T queries, where each query can be among
                     the following :-
                     a) push() x :- Push element x into the stack.
                     b) pop() :- Pop an element from the top of the stack.
                     c) peek() :- Get the top element of the stack.
                     d) getMin() :- Get the minimum among all the elements in the stack.
                     e) getMax() :- Get the maximum among all the elements in the stack.
                     design a stack which answers each query in constant time and space complexity.
Problem Category :-  Stack
Program Input Format :- T, denoting the number of queries
                        T queries to be answered.
Program Output Format :- The results of all the peek(), getMin() and getMax() queries.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class MinMaxStack
{
    private:
        stack<ll> st;
        ll minElement;
        ll maxElement;
    public:
        void push(ll element)
        {
            if(st.size()==0)
            {
                st.push(element);
                minElement=element;
                maxElement=element;
            }
            else
            {
                if(element<minElement)
                {
                    st.push(2*element-minElement);
                    minElement=element;
                }
                else if(minElement<element && element<maxElement)
                    st.push(element);
                else
                {
                    st.push(2*element-maxElement);
                    maxElement=element;
                }
            }
            return;
        }
        void pop()
        {
            if(st.empty())
                return;
            ll element=st.top();
            st.pop();
            if(element<minElement)
                minElement=2*minElement-element;
            else if(maxElement<element)
                maxElement=2*maxElement-element;
            return;
        }
        ll peek()
        {
            if(st.empty())
                return -1;
            ll element=st.top();
            if(element<minElement)
                return minElement;
            else if(maxElement<element)
                return maxElement;
            return element;
        }
        ll getMin()
        {
            return minElement;
        }
        ll getMax()
        {
            return maxElement;
        }
};
vector<ll> solve(vector<pair<string,ll>> &queries)
{
    vector<ll> result;
    MinMaxStack stk;
    for(auto &it:queries)
    {
        if(it.first=="push")
            stk.push(it.second);
        else if(it.first=="pop")
            stk.pop();
        else if(it.first=="peek")
            result.push_back(stk.peek());
        else if(it.first=="getMin")
            result.push_back(stk.getMin());
        else
            result.push_back(stk.getMax());
    }
    return result;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll t,element;
    string query;
    vector<pair<string,ll>> queries;
    vector<ll> result;
    fin>>t;
    while(t--)
    {
        fin>>query;
        if(query=="push")
        {
            fin>>element;
            queries.push_back({query,element});
        }
        else
            queries.push_back({query,-1});
    }
    result=solve(queries);
    for(auto &it:result)
        fout<<it<<endl;
    fin.close();
    fout.close();
    return 0;
}
