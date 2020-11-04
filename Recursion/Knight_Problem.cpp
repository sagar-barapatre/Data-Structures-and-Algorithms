#include <bits/stdc++.h>
using namespace std;
bool ifPossible(int board[][10],int n,int r,int c)
{
    if(r>=0 && r<n && c>=0 && c<n && board[r][c]==0)
    {
        return true;
    }

    return false;
}

bool SolveKnight(int board[][10],int n,int count,int r,int c)
{

    if(count==n*n)
    {
          return true;
    }


    int row[]={2,1,-1,-2,-2,-1,1,2};
    int col[]={1,2,2,1,-1,-2,-2,-1};

    for(int i=0;i<8;i++)
    {


        int nextR=r+row[i];
        int nextC=c+col[i];

        if(ifPossible(board,n,nextR,nextC))
        {
            board[nextR][nextC]=count+1;
            bool temp=SolveKnight(board,n,count+1,nextR,nextC);

            if(temp)
            {
                return true;
            }

            board[nextR][nextC]=0;

        }

    }

    return false;
}
int main()
{
    int board[10][10]={0};
    board[0][0]=1;

    int n;
    cin>>n;

    bool ans=SolveKnight(board,n,1,0,0);

    if(ans)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    else
    {
        cout<<"not possible";
    }
}
