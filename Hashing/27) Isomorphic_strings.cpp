/*
Two strings str1 and str2 are called isomorphic if there is a one to one mapping
possible for every character of str1 to every character of str2.
And all occurrences of every character in ‘str1’ map to same character in ‘str2’


An Efficient Solution can solve this problem in O(n) time. The idea is to create an array to store mappings of processed characters.

1) If lengths of str1 and str2 are not same, return false.
2) Do following for every character in str1 and str2
   a) If this character is seen first time in str1,
      then current of str2 must have not appeared before.
      (i) If current character of str2 is seen, return false.
          Mark current character of str2 as visited.
      (ii) Store mapping of current characters.
   b) Else check if previous occurrence of str1[i] mapped
      to same character.

*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Find if string X and Y are Isomorphic or not
bool isIsomorphic(string X, string Y)
{
	// if X and Y have different lengths, they cannot be Isomorphic
	if (X.length() != Y.length())
		return false;

	// use map to store mapping from characters of string X to string Y
	unordered_map<char, char> map;

	// use set to store pool of already mapped characters
	unordered_set<char> set;

	for (int i = 0; i < X.length(); i++)
	{
		char x = X[i], y = Y[i];

		// if x is seen before
		if (map.find(x) != map.end())
		{
			// return false if first occurrence of x is mapped to
			// different character
			if (map[x] != y)
				return false;
		}

		// if x is seen for the first time (i.e. it is not mapped yet)
		else
		{
			// return false if y is already mapped to some other char in X
			if (set.find(y) != set.end())
				return false;

			// map y to x and mark it mapped
			map[x] = y;
			set.insert(y);
		}
	}

	return true;
}

int main()
{
	string X = "ACAB";
	string Y = "XCXY";

	if (isIsomorphic(X, Y))
		cout << X << " and " << Y << " are Isomorphic\n";
	else
		cout << X << " and " << Y << " are not Isomorphic\n";

	return 0;
}