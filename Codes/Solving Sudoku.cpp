/**
Author :- Raghavendra Gururaj Kulkarni
Problem Name :- Solving Sudoku
Problem Statement :- Given a 9x9 sudoku board with some empty cells denoted by zero, fill
                     the empty cells adhering to the rules of standard sudoku game.
Problem Category :-  Recursion and Backtracking
Program Input Format :- 9x9 matrix of integers denoting the sudoku board to be solved
Program Output Format :- 9x9 matrix of integers denoting the solved sudoku board.
**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool vertical(vector<vector<int>> board,int l,int m)
{
    int i;
    for(i=0;i<9;i++)
        if(board[i][l]==m)
            return false;
    return true;
}
bool horizontal(vector<vector<int>> board,int k,int m)
{
    int i;
    for(i=0;i<9;i++)
        if(board[k][i]==m)
            return false;
    return true;
}
bool block(vector<vector<int>> board,int k,int l,int m)
{
    int p,q,i,j;
    p=3*floor(k/3);
    q=3*floor(l/3);
    for(i=p;i<p+3;i++)
        for(j=q;j<q+3;j++)
            if(board[i][j]==m)
                return false;
    return true;
}
bool solve(vector<vector<int>> &board, int row, int col)
{
    if(row==8 && col==9)
        return true;
    if(col==9)
    {
        row++;
        col=0;
    }
    if(board[row][col]>0)
        return solve(board,row,col+1);
    int num;
    for(num=1;num<=9;num++)
    {
        if(horizontal(board,row,num) && vertical(board,col,num) && block(board,row,col,num))
        {
            board[row][col]=num;
            if(solve(board,row,col+1))
                return true;
        }
        board[row][col]=0;
    }
    return false;
}
int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL),fout.tie(NULL);
    int i,j,k;
    vector<vector<int>> board(9,vector<int> (9));
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            fin>>board[i][j];
    if(solve(board,0,0))
    {
        fout<<"Sudoku solved successfully!!"<<endl<<endl;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
                fout<<board[i][j]<<' ';
            fout<<endl;
        }
    }
    else
        fout<<"No solution exists for the Sudoku"<<endl;
    fin.close();
    fout.close();
    return 0;
}
