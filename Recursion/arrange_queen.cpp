#include <bits/stdc++.h>
using namespace std;

bool issafe(int board[][10],int i,int j,int n)
{
    //col check
    for(int r=0;r<i;r++)
    {
        if(board[r][j]==1)return false;
    }
    int x=i,y=j;

    //left diagonal
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)return false;

        x--;
        y--;
    }

    //right diagonal

    x=i,y=j;
    while(x>=0 && y<n)
    {
        if(board[x][y]==1)return false;

        x--;
        y++;
    }

    return true;
}
bool arrangeQueens(int board[][10],int i,int n)
{
    //print board
    if(i==n)
    {
        for(int x=0;x<n;x++)
        {
            for(int y=0;y<n;y++)
            {
                if(board[x][y]==1)
                    cout<<"Q ";

                else
                    cout<<"_ ";
            }
            cout<<endl;
        }


        return true;  //return false if you need to have all possible answers
    }

    //rec case

    for(int j=0;j<n;j++)
    {
        if(issafe(board,i,j,n))
        {
            board[i][j]=1;
            bool nextsafe=arrangeQueens(board,i+1,n);
            if(nextsafe==true)
            {
               return true;
            }
        }
        board[i][j]=0;
    }
    return false;

}
int main()
{
    int n;
    cin>>n;

    int board[n][10];

    arrangeQueens(board,0,n);
}
