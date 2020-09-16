#include<iostream>
#include<unordered_set>
using namespace std;

void pairswithgivendifference(int arr[], int n, int diff)
{
	unordered_set<int> set;

	for (int i = 0 ; i < n ; i++)
	{
		if (set.find(arr[i] - diff) != set.end())
			cout << "(" << arr[i] << ", " << arr[i] - diff << ")\n";
		if (set.find(arr[i] + diff) != set.end())
			cout << "(" << arr[i] + diff << ", " << arr[i] << ")\n";

		set.insert(arr[i]);
	}
}

int main()
{
	int arr[] = { 1, 5, 2, 2, 2, 5, 5, 4};
	int diff = 3;

	int n = sizeof(arr) / sizeof(arr[0]);

	pairswithgivendifference(arr, n, diff);
	return 0;
}