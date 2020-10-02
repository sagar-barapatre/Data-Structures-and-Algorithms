/*
The idea is to use maps. We initially insert all elements of the first row in an map.
For every other element in remaining rows, we check if it is present in the map.
If it is present in the map and is not duplicated in current row,
we increment count of the element in map by 1, else we ignore the element.
If the currently traversed row is the last row,
we print the element if it has appeared m-1 times before.
*/
#include<iostream>
#include<unordered_map>
#define M 4
#define N 5
using namespace std;

void printCommonElements(int mat[M][N])
{
	unordered_map<int, int> mp;
	for (int i = 0 ; i < N ; i++)
		mp[mat[0][i]] = 1;

	for (int i = 1 ; i < M ; i++)// i is started from 1 beacause 1st row is already
		//evaluted in the map so now we traverse the whole remaining matrix.
	{
		for (int j = 0 ; j < N ; j++)
		{
			if (mp[mat[i][j]] == i)
			{
				mp[mat[i][j]] = i + 1;

				if (i == M - 1)
					cout << mat[i][j] << " ";
			}
		}
	}
}
int main()
{
	int mat[M][N] =
	{
		{1, 2, 1, 4, 8},
		{3, 7, 8, 5, 1},
		{8, 7, 7, 3, 1},
		{8, 1, 2, 7, 9},
	};

	printCommonElements(mat);
	return 0;
}