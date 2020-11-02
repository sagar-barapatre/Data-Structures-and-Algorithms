#include<bits/stdc++.h>
using namespace std;

void floodFill(int arr[][5],int n,int r,int c,int prefill,int tofill)
{
    int row=n;
    int col=n;
    if(r<0 || r>=row || c<0 || c>=col)return ;

    if(arr[r][c]!=prefill)return;

    arr[r][c]=tofill;

    floodFill(arr,n,r-1,c,prefill,tofill);
    floodFill(arr,n,r,c+1,prefill,tofill);
    floodFill(arr,n,r+1,c,prefill,tofill);
    floodFill(arr,n,r,c-1,prefill,tofill);
}

void printMat(int arr[][5],int n)
{
    int row=n;
    int col=n;

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main()
{
    int arr[5][5]={ {1,1,1,1,2},
                     {1,1,1,2,2},
                     {1,1,2,2,2},
                     {3,3,3,3,3},
                     {3,3,4,4,4}  };

    floodFill(arr,5,0,0,1,9);

    printMat(arr,5);


}
