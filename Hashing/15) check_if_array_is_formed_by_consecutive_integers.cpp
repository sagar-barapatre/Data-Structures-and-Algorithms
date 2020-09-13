#include<iostream>
#include<unordered_set>
using namespace std;

bool isConsecutive(int arr[], int n)
{
	int min = arr[0];
	int max = arr[0];

	for (int i = 0 ; i < n ; i++)
	{
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}

	if ((max - min) != (n - 1))
		return false;

	unordered_set<int> set;

	for (int i = 0; i < n; ++i)
	{
		if (set.find(arr[i]) != set.end())
			return false;

		else
			set.insert(arr[i]);
	}
	return true;
}

int main()
{
	int arr[] = { -1, 5, 4, 2, 0, 3, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	isConsecutive(arr, n) ? cout << "Array contains consecutive integers\n" :
	                             cout << "Array do not contain consecutive integers\n";
	return 0;
}