#include<bits/stdc++.h>
using namespace std;


void bubble_sort(int arr[],int s,int e)
{
    if(e==1)return;

    if(s==e-1)
    {
        return bubble_sort(arr,0,e-1);
    }

    if(arr[s]>arr[s+1])
    {
        swap(arr[s],arr[s+1]);
    }
    bubble_sort(arr,s+1,e);

}
int main()
{
    int arr[]={1,23,5,3,6,1,7};
    int n=sizeof(arr)/sizeof(int);

    bubble_sort(arr,0,n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
