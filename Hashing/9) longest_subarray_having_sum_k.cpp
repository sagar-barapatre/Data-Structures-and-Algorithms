/*
Algorithm :

   1) Initialize sum = 0 and maxLen = 0.
   2) Create a hash table having (sum, index) tuples.
   3) For i = 0 to n-1, perform the following steps:
        Accumulate arr[i] to sum.
        If sum == k, update maxLen = i+1.
    4)    Check whether sum is present in the hash table or not. If not present, then add it to the hash table as (sum, i) pair.
      5)  Check if (sum-k) is present in the hash table or not. If present, then obtain index of (sum-k) from the hash table as index. Now check if maxLen < (i-index), then update maxLen = (i-index).
    Return maxLen.

*/
#include<iostream>
#include<unordered_map>
using namespace std;

int lenOfLongSubarr(int arr[], int n, int k)
{

	// unordered_map 'um' implemented
	// as hash table
	unordered_map<int, int> mp;
	int sum = 0, maxLen = 0;

	// traverse the given array
	for (int i = 0; i < n; i++) {

		// accumulate sum
		sum += arr[i];

		// when subarray starts from index '0'
		if (sum == k)
			maxLen = i + 1;

		// make an entry for 'sum' if it is
		// not present in 'um'
		if (mp.find(sum) == mp.end())
			mp[sum] = i;

		// check if 'sum-k' is present in 'um'
		// or not
		if (mp.find(sum - k) != mp.end()) {

			// update maxLength
			if (maxLen < (i - mp[sum - k]))
				maxLen = i - mp[sum - k];
		}
	}

	// required maximum length
	return maxLen;
}

int main()
{
	int arr[] = {10, 5, 2, 7, 1, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 15;
	cout << "Length = "
	     << lenOfLongSubarr(arr, n, k) << endl;
	return 0;
}