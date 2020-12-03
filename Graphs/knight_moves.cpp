#include<bits/stdc++.h>
#define M 8
#define N 8
using namespace std;
// The time complexity of above solution will be O(m*n), where m and n are size
// of 2D matrix given;
/*
The solution will be same for the shortest path in a
binary maze, we just need to update dx[] = { -1, 0, 0, 1 };
and dy[] ={ 0, -1, 1, 0 };
and run loop from i = 0 to i = 4 and that's it we are done.
*/
class cell
{
public :
	int x;
	int y;
	int dist;

	cell(int x, int y, int dist)
	{
		this->x = x;
		this->y = y;
		this->dist = dist;
	}

};

bool isInside(int x, int y, int M, int N)
{
	if ((x >= 0 && x < M) && (y >= 0 && y < N))
		return true;
	return false;
}

int numberOfMoves(int x1, int y1, int x2, int y2)
{
	queue<cell> q;
	cell src(x1 - 1, y1 - 1, 0);
	q.push(src);
	bool visited[M][N];
	memset(visited, 0, sizeof(visited));
	int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
	int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	int x, y;

	while (!q.empty())
	{
		cell t = q.front();
		q.pop();

		if (t.x == x2 - 1 && t.y == y2 - 1)
			return t.dist;

		for (int i = 0 ; i < 8 ; i++)
		{
			x = t.x + dx[i];
			y = t.y + dy[i];

			if (isInside(x, y, M, N) && !visited[x][y])
			{
				visited[x][y] = true;
				cell dest(x, y, t.dist + 1);
				q.push(dest);
			}
		}



	}
	return -1;
}

