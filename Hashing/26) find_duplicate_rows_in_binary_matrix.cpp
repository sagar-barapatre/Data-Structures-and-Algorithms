/*
Another approach is be to convert the decimal equivalent of row and check
if a new row has the same decimal equivalent then it is a duplicate row.
It will not work if the number of columns is large .
*/
/*
The idea is to convert each row into its decimal equivalent and check if decimal
value is seen before, we report the row as duplicate.
this method will work only for N < 32 (or N < 64 if long is used)
where N is the number of columns in the matrix.
*/
#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;

// M x N matrix
#define M 5
#define N 5

int main()
{
	bool mat[M][N] =
	{
		{0, 0, 0, 0, 0},
		{0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 1, 1, 0},
		{0, 1, 1, 0, 0}
	};

	unordered_set<unsigned> set;

	// do for each row i
	for (int i = 0; i < M; i++)
	{
		unsigned decimal = 0;

		// convert binary row i into its decimal equivalent
		for (int j = 0; j < N; j++) {
			decimal += mat[i][j] * j;
		}

		// if decimal value is seen before
		if (set.find(decimal) != set.end()) {
			cout << "Duplicate row found : Row #" << i + 1 << endl;
		}
		else {
			set.insert(decimal);
		}
	}

	return 0;
}