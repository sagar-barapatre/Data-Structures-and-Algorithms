//Given an array of integers where each element
//represents the max number of steps that can be
// made forward from that element. The task is to
//find the minimum number of jumps to reach the end
//of the array (starting from the first element).
//If an element is 0, then cannot move through that element.


#include <bits/stdc++.h>
using namespace std;
int minJumps(int *arr,int i,int n)
{
    if(i>=n-1)return 0;

    int noJumps=arr[i];
    int minimum=INT_MAX;

    for(int j=1;j<=noJumps;j++)
    {
        minimum=min(minJumps(arr,i+j,n)+1,minimum);
    }
    return minimum;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<minJumps(arr,0,n)<<endl;
    }


}
