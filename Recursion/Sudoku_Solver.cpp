#include<bits/stdc++.h>
using namespace std;

bool canPlace(int board[][9],int n,int r,int c,int num)
{
    //row col check

    for(int i=0;i<n;i++)
    {
        if(board[r][i]==num)return false;
        if(board[i][c]==num)return false;
    }

    //box check

    int rootn=sqrt(n);

    int boxStartRow = (r/rootn) * rootn;
    int boxStartCol = (c/rootn) * rootn;

    for(int i=boxStartRow;i<boxStartRow+3;i++)
    {
        for(int j=boxStartCol ; j<boxStartCol + 3 ; j++)
        {
            if(board[i][j]==num)return false;
        }
    }

    return true;
}

bool solver(int board[][9],int n,int r,int c)
{
    if(r==n)
    {
        return true;
    }

    if(board[r][c]!=0)
        {
            if(c==n-1)
            {
                return solver(board,n,r+1,0);
            }
            else
            {
                return solver(board,n,r,c+1);
            }

        }

    for(int i=1;i<=n;i++)
    {
        if(canPlace(board,n,r,c,i))
        {
            board[r][c]=i;

            bool success;

            if(c==n-1)
            {
                success = solver(board,n,r+1,0);
            }
            else
            {
                success = solver(board,n,r,c+1);
            }

            if(success)return true;

            board[r][c]=0;
        }
    }

    return false;
}
int main()
{
    int board[9][9]=
    {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    solver(board,9,0,0);

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
