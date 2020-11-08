#include <bits/stdc++.h>
using namespace std;
int ratInMaze(int maze[][5],int n,int solution[][5],int i,int j)
{
    if(i==n-1 && j==n-1)
    {
        solution[i][j]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<solution[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<endl;

        return 1;
    }

    if(maze[i][j]==0 || i>=n || j>=n)
    {
        return 0;
    }

    solution[i][j]=1;

    int a=ratInMaze(maze,5,solution,i,j+1);
    int b=ratInMaze(maze,5,solution,i+1,j);

    solution[i][j]=0;

    return a+b;
}
int main()
{
    int maze[5][5]={    {1,1,1,1,1},
                        {1,1,1,0,1},
                        {1,1,1,1,0},
                        {1,0,1,1,1}  };

    int solution[5][5]={0};

    cout<<ratInMaze(maze,5,solution,0,0);
}
