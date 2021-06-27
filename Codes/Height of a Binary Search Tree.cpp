/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Height of a Binary Search Tree
Problem Statement :- Given a binary search tree with N nodes, find the height of the tree.
Problem Category :-  Binary Search Trees
Program Input Format :- N, denoting the number of nodes in the tree.
                        N integers denoting the node values.
Program Output Format :- Height of the Tree
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
ll solve(vector<ll> nodes)
{
    node *root=NULL,*temp;
    queue<pair<node*,ll>> next;
    ll height=-1,level;
    for(auto &it:nodes)
        root=add(root,it);
    next.push({root,0});
    while(!next.empty())
    {
        temp=next.front().first;
        level=next.front().second;
        height=max(height,level);
        if(temp->left)
            next.push({temp->left,level+1});
        if(temp->right)
            next.push({temp->right,level+1});
        next.pop();
    }
    _deallocate(&root);
    root=NULL;
    return height;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    ll n,i;
    fin>>n;
    vector<ll> nodes(n);
    for(i=0;i<n;i++)
        fin>>nodes[i];
    fout<<solve(nodes);
    fin.close();
    fout.close();
    return 0;
}
