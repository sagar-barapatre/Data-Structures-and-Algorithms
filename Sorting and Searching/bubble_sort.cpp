#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[128];
	cout<<"Enter the unsorted array : ";
	for(int i=0 ; i<n ; i++)
	{
		cin>>arr[i];
	}
	for(int i=0 ; i<n-1 ; i++)
	{
		for(int j=0 ; j<n-1 ; j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp;
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	cout<<"The sorted array is : ";
	for(int i=0 ; i<n ; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}