/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Successor in a Binary Search Tree
Problem Statement :- Given a binary search tree with N nodes, find the successor of a given
                     element and print -1 if no successor present.
Problem Category :-  Binary Search Trees
Program Input Format :- N, denoting the number of nodes in the tree.
                        N integers denoting the node values.
Program Output Format :- Successor of the given element if present and -1 otherwise
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
void inOrder(node* root,vector<ll> &traversal)
{
    if(root)
    {
        inOrder(root->left,traversal);
        traversal.push_back(root->value);
        inOrder(root->right,traversal);
    }
    return;
}
ll solve(vector<ll> nodes,ll k)
{
    node *root=NULL;
    ll i,result=-1;
    vector<ll> traversal;
    for(auto &it:nodes)
        root=add(root,it);
    inOrder(root,traversal);
    for(i=0;i<traversal.size()-1;i++)
        if(traversal[i]==k)
            result=traversal[i+1];
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
    ll n,i,k;
    fin>>n;
    vector<ll> nodes(n);
    for(i=0;i<n;i++)
        fin>>nodes[i];
    fin>>k;
    fout<<solve(nodes,k);
    fin.close();
    fout.close();
    return 0;
}
