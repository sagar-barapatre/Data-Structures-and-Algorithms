#include <iostream>
#include <unordered_set>
using namespace std;

// Function to check if sub-array with given sum exists in
// the array or not
bool findSubarray(int arr[], int n, int sum)
{
	// create an empty set
	unordered_set<int> set;

	// insert number 0 into the set to handle the case when
	// sub-array with given sum starts from index 0
	set.insert(0);

	// maintains sum of elements so far
	int sum_so_far = 0;

	// traverse the given array
	for (int i = 0; i < n; i++)
	{
		// update sum_so_far
		sum_so_far += arr[i];

		// if (sum_so_far - sum) is seen before, we have found
		// the sub-array with sum 'sum'
		if (set.find(sum_so_far - sum) != set.end())
			return true;

		// else insert sum of elements so far into the set
		set.insert(sum_so_far);
	}

	// we reach here when no sub-array exists
	return false;
}

int main()
{
	// array of integers
	int arr[] = { 0, 5, -7, 1, -4, 7, 6, 1, 4, 1, 10 };
	int sum = -3;

	int n = sizeof(arr)/sizeof(arr[0]);

	if (findSubarray(arr, n, sum))
		cout << "Sub-array with given sum exists";
	else
		cout << "Sub-array with given sum do not exist";

	return 0;
}