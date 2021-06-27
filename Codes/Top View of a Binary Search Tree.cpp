/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Top View of a Binary Search Tree
Problem Statement :- Given a binary search tree with N nodes, print the top view of the tree.
Problem Category :-  Trees
Program Input Format :- N, denoting the number of nodes in the tree.
                        N integers denoting the node values.
Program Output Format :- List of nodes visible from the top view of the tree.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct Node
{
    ll value;
    struct Node* left;
    struct Node* right;
    Node(ll x)
    {
        value=x;
        left=NULL;
        right=NULL;
    }
};
typedef struct Node node;
node* add(node* root,ll x)
{
    node* temp=new Node(x);
    if(root==NULL)
        return temp;
    node* cur=root;
    while(1)
    {
        if(temp->value<cur->value)
        {
            if(cur->left==NULL)
            {
                cur->left=temp;
                break;
            }
            else
                cur=cur->left;
        }
        else
        {
            if(cur->right==NULL)
            {
                cur->right=temp;
                break;
            }
            else
                cur=cur->right;
        }
    }
    return root;
}
void deallocate(node* root)
{
    if(root)
    {
        deallocate(root->left);
        deallocate(root->right);
        delete root;
    }
    return;
}
void _deallocate(node** root)
{
    deallocate(*root);
    *root=NULL;
}
vector<pair<ll,ll>> solve(vector<ll> nodes)
{
    node *root=NULL,*temp;
    map<ll,bool> vertical;
    vector<pair<ll,ll>> result;
    queue<pair<node*,ll>> next;
    ll level;
    for(auto &it:nodes)
        root=add(root,it);
    next.push({root,0});
    while(!next.empty())
    {
        temp=next.front().first;
        level=next.front().second;
        if(vertical[level]==false)
        {
            result.push_back({level,temp->value});
            vertical[level]=true;
        }
        if(temp->left)
            next.push({temp->left,level-1});
        if(temp->right)
            next.push({temp->right,level+1});
        next.pop();
    }
    _deallocate(&root);
    root=NULL;
    return result;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,i;
    vector<pair<ll,ll>> result;
    fin>>n;
    vector<ll> nodes(n);
    for(i=0;i<n;i++)
        fin>>nodes[i];
    result=solve(nodes);
    sort(result.begin(),result.end());
    for(auto &it:result)
        fout<<it.second<<' ';
    fin.close();
    fout.close();
    return 0;
}
