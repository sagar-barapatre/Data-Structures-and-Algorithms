#include <iostream>
#include <unordered_set>
#include <vector>
#include <cstdlib>
using namespace std;

// Returns the number of distinct absolute values in the given input
int findDistinct(vector<int> input)
{
	unordered_set<int> set;
	for (int const& i: input)
		set.insert(abs(i));

	return set.size();
}

int main()
{
	vector<int> input = { -1, -1, 0, 1, 1, 1 };

	cout << "The number of distinct absolute values are "
		<< findDistinct(input);

	return 0;
}