#include<bits/stdc++.h>
using namespace std;

int binarySearch(int *arr,int s,int e,int k)
{
    if(s>e)return -1;

    int mid=(s+e)/2;

    if(arr[mid]>k)
    {
        return binarySearch(arr,s,mid-1,k);
    }
    else if(arr[mid]<k)
    {
        return binarySearch(arr,mid+1,e,k);
    }
    else{
        return mid;
    }
}
int main()
{
    int arr[]={1,3,4,5,6,7,8,9,19,100};

    int k=100,n=sizeof(arr)/sizeof(int);

    cout<<"position of "<<k<<" "<<binarySearch(arr,0,n-1,k);
}
