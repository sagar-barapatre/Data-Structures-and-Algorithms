#include<iostream>
#include<unordered_map>
#include<vector>
#define  Pair pair<int, int>
using namespace std;

bool fourSum(int arr[], int n, int sum)
{
	unordered_map<int, vector<Pair>> mp;

	for (int i = 0 ; i <  n - 1 ; i++)
	{
		for (int j = i + 1 ; j < n ; j++)
		{
			int ans = sum - (arr[i] + arr[j]);

			if (mp.find(ans) != mp.end())
			{
				for (auto pair : mp.find(ans)->second)
				{
					int x = pair.first;
					int y = pair.second;
					if (x != i && x != j && y != i && y != j)
					{
						cout << "(" << arr[i] << ", " << arr[j] << ", " << arr[x] << ", " << arr[y] << ")";
						return true;
					}
				}

			}

			mp[arr[i] + arr[j]].push_back({i, j});
		}
	}
	return false;
}
//time complexity : O(n2)
//space complexity : O(n2)
int main()
{
	int arr[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
	int sum = 20;

	int n = sizeof(arr) / sizeof(arr[0]);

	if (!fourSum(arr, n, sum))
		cout << "Quadruplet Don't Exist";

	return 0;
}