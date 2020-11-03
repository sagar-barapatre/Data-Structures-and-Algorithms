#include<bits/stdc++.h>
using namespace std;

int coinMax(int *arr,int l,int r)
{
    if(l+1==r)return max(arr[l],arr[r]);

    return max(arr[l]+min( coinMax(arr,l+2,r),coinMax(arr,l+1,r-1))
               ,arr[r]+min( coinMax(arr,l,r-2),coinMax(arr,l+1,r-1)));
}
int main()
{
    int arr[]={1,5,7,3,2,4};
    int n=sizeof(arr)/sizeof(int);

    cout<<"Max score : "<<coinMax(arr,0,n-1);
}
