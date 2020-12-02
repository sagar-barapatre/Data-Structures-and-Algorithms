#include<iostream>
#include<map>
using namespace std;

void mostFrequent(string arr[], int n)
{
	map<string, int> mp;
	for (int i = 0 ; i < n ; i++)
	{
		mp[arr[i]]++;
	}

	int max_count = 0;
	string res = "";
	for (auto i : mp) {
		cout << i.first << " -> " << i.second << endl;
	}



}

int main()
{
	string arr[] = { "geeks", "for", "geeks", "a",
	                 "portal", "to", "learn", "can", "be",
	                 "computer", "science", "zoom", "yup",
	                 "fire", "in", "be", "data", "geeks"
	               };
	int n = sizeof(arr) / sizeof(arr[0]);
	mostFrequent(arr, n);
	return 0;
}