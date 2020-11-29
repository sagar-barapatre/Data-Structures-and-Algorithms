#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;

// M x N matrix
#define M 3
#define N 4

// Below arrays details all 8 possible movements from a cell
// (top, right, bottom, left and 4 diagonal moves)
int row[] = { -1, -1, -1, 0, 1, 0, 1, 1 };
int col[] = { -1, 1, 0, -1, -1, 1, 0, 1 };

// Function to check if it is safe to go to cell (x, y) from current cell.
// The function returns false if (x, y) is not valid matrix coordinates
// or cell (x, y) is already processed
bool isSafe(int x, int y, bool processed[][N])
{
	return (x >= 0 && x < M) && (y >= 0 && y < N) &&
	       !processed[x][y];
}

// A recursive function to generate all possible words in a boggle
void searchBoggle(char board[][N], unordered_set<string> &words,
                  bool processed[][N], int i, int j, string path)
{
	// mark current node as processed
	processed[i][j] = true;

	// update the path with the current character and insert it into the set
	path = path + board[i][j];
	words.insert(path);

	// check for all 8 possible movements from the current cell
	for (int k = 0; k < 8; k++)
	{
		// skip if cell is invalid or it is already processed
		if (isSafe(i + row[k], j + col[k], processed)) {
			searchBoggle(board, words, processed, i + row[k], j + col[k], path);
		}
	}

	// mark current node as unprocessed
	processed[i][j] = false;
}

// Function to search for given set of words in a boggle
void searchBoggle(char board[][N], vector<string> &input)
{
	// construct a boolean matrix to store whether a cell is processed or not
	bool processed[M][N];
	memset(processed, false, sizeof(processed));

	// construct a set to store all possible words constructed from the matrix
	unordered_set<string> words;

	// generate all possible words in a boggle
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// consider each character as a starting point and run DFS
			searchBoggle(board, words, processed, i, j, "");
		}
	}

	// for each word in the input list, check whether it is present in the set
	for (string word : input) {
		if (words.find(word) != words.end()) {
			cout << word << endl;
		}
	}
}

int main()
{
	char board[M][N] = {
		{'M', 'S', 'E', 'F'},
		{'R', 'A', 'T', 'D'},
		{'L', 'O', 'N', 'E'}
	};

	vector<string> words { "START", "NOTE", "SAND", "STONED" };

	searchBoggle(board, words);
	// delete[] row;
	// delete[] col;

	return 0;
}