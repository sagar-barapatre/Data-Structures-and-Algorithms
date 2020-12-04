// C program for Knight Tour problem
#include<stdio.h>
#define N 8

// int solveKTUtil(int x, int y, int movei, int sol[N][N],
//                 int dx[], int dy[]);

/* A utility function to check if i,j are valid indexes
for N*N chessboard */
int isSafe(int x, int y, int sol[N][N])
{
	return ( x >= 0 && x < N && y >= 0 &&
	         y < N && sol[x][y] == -1);
}

/* A utility function to print solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
			printf(" %2d ", sol[x][y]);
		printf("\n");
	}
}

/* This function solves the Knight Tour problem using
Backtracking. This function mainly uses solveKTUtil()
to solve the problem. It returns false if no complete
tour is possible, otherwise return true and prints the
tour.
Please note that there may be more than one solutions,
this function prints one of the feasible solutions. */


/* A recursive utility function to solve Knight Tour
problem */
bool solveKTUtil(int x, int y, int movei, int sol[N][N],
                 int dx[N], int dy[N])
{
	int k, next_x, next_y;
	if (movei == N * N)
		return true;

	/* Try all next moves from the current coordinate x, y */
	for (k = 0; k < 8; k++)
	{
		next_x = x + dx[k];
		next_y = y + dy[k];
		if (isSafe(next_x, next_y, sol))
		{
			sol[next_x][next_y] = movei;
			if (solveKTUtil(next_x, next_y, movei + 1, sol,
			                dx, dy))
				return true;
			else
				sol[next_x][next_y] = -1;// backtracking
		}
	}

	return false;
}

/* Driver program to test above functions */
int main()
{
	int sol[N][N];

	/* Initialization of solution matrix */
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			sol[x][y] = -1;

	/* dx[] and dy[] define next move of Knight.
	dx[] is for next value of x coordinate
	dy[] is for next value of y coordinate */
	int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	// Since the Knight is initially at the first block
	sol[0][0] = 0;

	/* Start from 0,0 and explore all tours using
	solveKTUtil() */
	if (solveKTUtil(0, 0, 1, sol, dx, dy) == 0)
	{
		printf("Solution does not exist");
		return 0;
	}
	else
		printSolution(sol);


	return 0;
}
