#include<bits/stdc++.h>
using namespace std;

void reversearray(int arr[],int n,int i)
{
    if(i==n/2)return ;

    int temp=arr[i];
    arr[i]=arr[n-1-i];
    arr[n-1-i]=temp;

    reversearray(arr,n,i+1);
}
int main()
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);
    reversearray(arr,n,0);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }


}
