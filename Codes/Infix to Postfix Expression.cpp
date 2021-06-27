/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Infix to Postfix Expression
Problem Statement :- Given a infix expression, convert it to equivalent postfix expression.
Problem Category :-  Stack
Program Input Format :- The infix expression
Program Output Format :- The equivalent postfix expression
**/

#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long int
ll priority(char ch)
{
    switch(ch)
    {
        case '^':return 1;
                    break;
        case '/':return 2;
                    break;
        case '*':return 3;
                    break;
        case '+':return 4;
                    break;
        case '-':return 5;
                    break;
        default:
                break;
    }
    return 6;
}
string solve(string exp)
{
    stack<char> st;
    string result="";
    ll i;
    for(i=0;i<exp.length();i++)
    {
        if(exp[i]=='(')
            st.push(exp[i]);
        else if(exp[i]>='a' && exp[i]<='z')
            result.push_back(exp[i]);
        else if(exp[i]==')')
        {
            while(st.top()!='(')
            {
                result.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && priority(exp[i])>priority(st.top()))
            {
                result.push_back(st.top());
                st.pop();
            }
            st.push(exp[i]);
        }
    }
    while(!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }
    return result;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll t,i;
    string exp;
    fin>>exp;
    fout<<solve(exp);
    fin.close();
    fout.close();
    return 0;
}

