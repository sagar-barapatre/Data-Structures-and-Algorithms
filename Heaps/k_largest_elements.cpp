#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array : ";
    for(int i=0 ; i<n ; i++)
    cin>>arr[i];

    int k;
    cin>>k;

    priority_queue <int, vector<int>, greater<int> > minheap;

    for(int i=0 ; i<n ; i++)
    {
        minheap.push(arr[i]);
        if(minheap.size() > k)
        minheap.pop();
    }

    while(minheap.size() > 0)
    {
        cout<<minheap.top()<<endl;
        minheap.pop();
    }
    return 0;   
}