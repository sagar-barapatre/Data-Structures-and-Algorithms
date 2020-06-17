#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of elements in array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array : ";
    for(int i=0 ; i<n ; i++)
    cin>>arr[i];
    int k;
    cin>>k;


    priority_queue <int> maxheap;
    for(int i=0 ; i<n ; i++)
    {
        maxheap.push(arr[i]);
        if(maxheap.size() > k)
        maxheap.pop();

    }

    cout<<"The "<<k<<"th smallest element is : "<<maxheap.top()<<endl;
    return 0;
}