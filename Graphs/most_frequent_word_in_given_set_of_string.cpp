#include<iostream>
#include<unordered_map>
using namespace std;

string mostFrequent(string arr[], int n)
{
	unordered_map<string, int> mp;
	for (int i = 0 ; i < n ; i++)
	{
		mp[arr[i]]++;
	}

	int max_count = 0;
	string res = "";
	for (auto i : mp) {
		if (max_count < i.second) {
			res = i.first;
			max_count = i.second;
		}
	}
	return res;
}

int main()
{
	string arr[] = { "geeks", "for", "geeks", "a",
	                 "portal", "to", "learn", "can", "be",
	                 "computer", "science", "zoom", "yup",
	                 "fire", "in", "be", "data", "geeks"
	               };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << mostFrequent(arr, n) << endl;
	return 0;
}