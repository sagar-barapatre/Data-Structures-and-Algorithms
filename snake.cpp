// C++ program to find minimum number of dice throws required to
// reach last cell from first cell of a given snake and ladder
// board
#include<iostream>
#include <queue>
using namespace std;

// An entry in queue used in BFS
struct cell
{
	int vertex;	 // vertex number
	int dist; // Distance of this vertex from source
};

// This function returns minimum number of dice throws required to
// Reach last cell from 0'th cell in a snake and ladder game.
// move[] is an array of size N where N is no. of cells on board
// If there is no snake or ladder from cell i, then move[i] is -1
// Otherwise move[i] contains cell to which snake or ladder at i
// takes to.
int getMinDiceThrows(int move[], int N)
{
	// The graph has N vertices. Mark all the vertices as
	// not visited
	vector<bool> visited(N, 0);

	// Create a queue for BFS
	queue<cell> q;

	// Mark the node 0 as visited and enqueue it.
	visited[0] = true;
	cell src = {0, 0}; // distance of 0't vertex is also 0
	q.push(src); // Enqueue 0'th vertex

	// Do a BFS starting from vertex at index 0
	// A queue entry (t)
	cell t;
	while (!q.empty())
	{
		t = q.front();
		int vertex = t.vertex; // vertex no. of queue entry

		// If front vertex is the destination vertex,
		// we are done
		if (vertex == N - 1)
			break;

		// Otherwise dequeue the front vertex and enqueue
		// its adjacent vertices (or cell numbers reachable
		// through a dice throw)
		q.pop();
		for (int j = vertex + 1; j <= (vertex + 6) && j < N; ++j)
		{
			// If this cell is already visited, then ignore
			if (!visited[j])
			{
				// Otherwise calculate its distance and mark it
				// as visited
				cell a;
				a.dist = (t.dist + 1);
				visited[j] = true;

				// Check if there a snake or ladder at 'j'
				// then tail of snake or top of ladder
				// become the adjacent of 'i'
				if (move[j] != -1)
					a.vertex = move[j];
				else
					a.vertex = j;
				q.push(a);
			}
		}
	}

	// We reach here when 't' has last vertex
	// return the distance of vertex in 't'
	return t.dist;
}

// Driver program to test methods of graph class
int main()
{
	// Let us construct the board given in above diagram
	int N = 30;
	int moves[N];
	memset(moves, -1, sizeof(moves));

	// Ladders
	moves[2] = 21;
	moves[4] = 7;
	moves[10] = 25;
	moves[19] = 28;

	// Snakes
	moves[26] = 0;
	moves[20] = 8;
	moves[16] = 3;
	moves[18] = 6;

	cout << "Min Dice throws required is " << getMinDiceThrows(moves, N);
	return 0;
}
