#include <iostream>
#include <queue>
#include<cstring>

// M x N matrix
#define M 6
#define N 5

// Data Structure for the queue node
struct Node
{
	int x;			  // stores x-coordinate of a matrix cell
	int y;			  // stores y-coordinate of a matrix cell
	int distance;	   // stores the distance of (x, y) from mine
};

// check if specified row and column are valid matrix index
bool isValid(int i, int j)
{
	return (i >= 0 && i < M) && (j >= 0 && j < N);
}

// check if current cell is an open area and its
// distance from mine is not yet calculated
bool isSafe(int i, int j, char mat[][N], int result[][N])
{
	return mat[i][j] == 'O' && result[i][j] == -1;
}

// Replace all O's in the matrix with their shortest distance
// from the nearest mine
void updateDistance(char mat[][N], int result[][N])
{
	// initialize an empty queue
	std::queue<Node> Q;

	// find all mines location and add them to the queue
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// if current cell represents a mine
			if (mat[i][j] == 'M')
			{
				Q.push({i, j, 0});

				// update mine distance as 0
				result[i][j] = 0;
			}
			// else initialize mine distance by as -1
			// else result[i][j] = -1;
		}
	}

	// arrays to get indices of 4 adjacent cells of a given cell
	int R[] = { 0, -1, 0, 1 };
	int C[] = { -1, 0, 1, 0 };

	// do for each Node in the queue
	while (!Q.empty())
	{
		// process front cell in the queue
		int x = Q.front().x;
		int y = Q.front().y;
		int distance = Q.front().distance;

		// dequeue the front cell
		Q.pop();

		// update the 4 adjacent cells of the front node in the queue
		for (int i = 0; i < 4; i++)
		{
			// enqueue the adjacent cell if it is valid, unvisited,
			// and has a path through it
			if (isValid(x + R[i], y + C[i]) &&
			        isSafe(x + R[i], y + C[i], mat, result))
			{
				result[x + R[i]][y + C[i]] = distance + 1;
				Q.push({x + R[i], y + C[i], distance + 1});
			}
		}
	}
}

// Find shortest distance of every cell from land mine in a Maze
int main()
{
	char mat[][N] =
	{
		{'O', 'M', 'O', 'O', 'X'},
		{'O', 'X', 'X', 'O', 'M'},
		{'O', 'O', 'O', 'O', 'O'},
		{'O', 'X', 'X', 'X', 'O'},
		{'O', 'O', 'M', 'O', 'O'},
		{'O', 'X', 'X', 'M', 'O'}
	};

	int result[M][N];
	memset(result, -1, sizeof(result));
	updateDistance(mat, result);

	// print results
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			std::cout  << result[i][j] << "  ";
		std::cout << '\n';
	}

	return 0;
}