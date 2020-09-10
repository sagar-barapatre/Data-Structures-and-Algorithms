#include<iostream>
#include<unordered_map>
using namespace std;

void print(int arr[], int n)
{
	unordered_map<int, int>  mp;

	for (int i = 0 ; i < n ; i++)
	{
		mp[arr[i]]++;
	}
	for (int i = 0 ; i < n ; i++)
	{
		if (mp.find(arr[i]) != mp.end())
		{
			int n = mp[arr[i]];
			while (n--)
			{
				cout << arr[i] << " ";
			}
			mp.erase(arr[i]);
		}
	}
}

int main()
{
	int A[] = { 5, 4, 5, 5, 3, 1, 2, 2, 4 };
	int n = sizeof(A) / sizeof(A[0]);

	print(A, n);
	return 0;

}