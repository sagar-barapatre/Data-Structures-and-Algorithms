#include<bits/stdc++.h>
using namespace std;
int sumofarray(int *arr,int n,int i)
{
    if(i==n)return 0;

    return arr[i]+sumofarray(arr,n,i+1);
}
int main()
{
    int arr[]={1,24,4,52,3,6,7};
    int n=sizeof(arr)/sizeof(int);

    cout<<sumofarray(arr,n,0);
}
