#include<iostream>
using namespace std;

int maxlength(int arr[], int n)
{
	unordered_map<int, int> mp;
	mp[0] = -1;

	int max_len = 0;
	int sum = 0;
	for (int i = 0 ; i < n ; i++)
	{
		sum += (arr[i] == 1 ? 1 : -1);

		if (mp.find(sum) != mp.end())
			max_len = max(max_len, i - mp[sum]);
		else
			mp[sum] = i;
	}
	return max_len;
}

int main()
{
	int arr[] = { 0, 0, 1, 0, 1, 0, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << maxlength(arr, n) << endl;
	return 0;
}