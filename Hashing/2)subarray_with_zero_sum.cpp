#include <iostream>
#include <unordered_set>
using namespace std;

// Function to check if sub-array with 0 sum is present
// in the given array or not
bool zeroSumSubarray(int A[], int n)
{
	// create an empty set to store sum of elements of each
	// sub-array A[0..i] where 0 <= i < n
	unordered_set<int> set;

	// insert 0 into set to handle the case when sub-array with
	// 0 sum starts from index 0
	set.insert(0);

	int sum = 0;

	// traverse the given array
	for (int i = 0; i < n; i++)
	{
		// sum of elements so far
		sum += A[i];

		// if sum is seen before, we have found a sub-array with 0 sum
		if (set.find(sum) != set.end()) {
			return true;
		} else {
			// insert sum so far into set
			set.insert(sum);
		}
	}

	// we reach here when no sub-array with 0 sum exists
	return false;
}

int main()
{
	int A[] = { 4, 2, -3, -1, 0, 4 };
	int n = sizeof(A)/sizeof(A[0]);

	zeroSumSubarray(A, n) ?
			cout << "Subarray exists":
			cout << "Subarray do not exist";

	return 0;
}