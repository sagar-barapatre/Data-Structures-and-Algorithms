#include<iostream>
#include<unordered_map>
using namespace std;

bool isTrue(vector<int> add, int k)
{
	unordered_map>int, int> mp;
	for(int i = 0 ; i < add.size() ; i++)
	{
		if(mp.find(add[i]) != mp.end())
		{
			if(i - mp[add[i]] <= k)
				return true;

		}
		mp[add[i]] = i;
	}
	return false;
}

int main()
{
	vector<int> vec = { 5, 6, 8, 2, 4, 6, 9 };
	int k = 4;

	if (hasDuplicates(vec, k)) {
		cout << "Duplicates found";
	}
	else {
		cout << "No Duplicates found";
	}
	return 0;
}