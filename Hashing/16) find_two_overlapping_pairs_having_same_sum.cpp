#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
typedef pair<int, int> Pair;

void pairshavingsamesum(int arr[], int n)
{

	unordered_map<int, vector<Pair>> mp;
	for (int i = 0 ; i < n - 1 ; i++)
	{
		for (int j = i + 1 ; j < n ; j++)
		{
			int sum = arr[i] + arr[j];

			if (mp.find(sum) != mp.end())
			{
				for (auto pair : mp.find(sum)->second)
				{
					int m = pair.first;
					int n = pair.second;
					if ((m != i && m != j) && (n != i && n != j))
					{
						cout << "(" << arr[i] << ", " << arr[j] << ") and (" << arr[m] << ", " << arr[n] << ")\n";
						return ;
					}

				}
			}

			mp[sum].push_back({i, j});

		}
	}
}


int main()
{
	int arr[] = { 3, 4, 7, 3, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);

	pairshavingsamesum(arr, n);
	return 0;
}

