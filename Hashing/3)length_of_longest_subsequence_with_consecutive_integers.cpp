#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int lengthofCSI(vector<int> add, int n)
{
	unordered_set<int> s(add.begin(), add.end());

	int max_len = 1;
	for(auto x : add)
	{
		if(s.find(x-1) == s.end())
		{
			int len = 1;
			while(s.find(x + len) != s.end())
				len++;

			max_len = max(max_len, len);
		}
	}
	return max_len;
}

int main()
{
	vector<int> vec = { 2, 0, 6, 1, 5, 3, 7 };

	cout << "The length of maximum length consecutive subsequence is "
		 << findMaxLenSubSeq(vec);
	return 0;
}