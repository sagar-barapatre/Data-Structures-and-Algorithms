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
    int k,x;
    cout<<"Enter the value of number of numbers to be found closest to and that number :  ";
    cin>>x>>k;

    priority_queue<pair<int, int> > maxheap;

    for(int i=0 ; i<n; i++)
    {
        maxheap.push({ abs(arr[i] - x), arr[i] });

        if(maxheap.size() > k)
        maxheap.pop();
    }

    while(maxheap.size() > 0)
    {
        cout<<maxheap.top().second<<endl;
        maxheap.pop();
    }
    return 0;
}