#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find majority element is present in an array (vector)
int majorityElement(vector<int> A)
{
	// create an empty map
	unordered_map<int, int> map;

	// get input size
	int n = A.size();

	// 1. store each element's frequency in a map
	for (int i = 0; i < n; i++) {
		map[A[i]]++;
	}

	// 2. return the element if its count is more than n/2
	for (auto pair : map) {
		if (pair.second > n / 2) {
			return pair.first;
		}
	}

	// Note that step 2 and step 3 can be merged into one
	/* for (int i = 0; i < n; i++)
	{
		if (++map[A[i]] > n/2)
			return A[i];
	} */

	// return -1 if no majority element is present
	return -1;
}

int main()
{
	vector<int> vec = { 2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2 };

	int res = majorityElement(vec);
	if (res != -1)
		cout << "Majority element is " << res;
	else
		cout << "Majority element doesn't exists";

	return 0;
}