#include<bits/stdc++.h>
using namespace std;
bool checkSorted(int * arr,int i)
{
    if(i==0)return true;

    if(arr[i]>=arr[i-1] && checkSorted(arr,i-1))return true;

    return false;
}
int main()
{
    int arr[]={1,2,3,10,6,7,7};
    int n=sizeof(arr)/sizeof(int);

    cout<<checkSorted(arr,n-1);
}
