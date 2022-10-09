#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>

int map[15][15];
int x_used[15];
int cnt = 0;

void N_Queen(int, int);
bool can_place(int, int, int);

int main()
{
	int N;
	scanf("%d", &N);

	N_Queen(0, N);

	printf("%d", cnt);

	return 0;
}

void N_Queen(int i, int N)
{
	if (i == N)
	{
		cnt++;
		return;
	}

	for (int j = 1; j <= N; j++) {
		if (x_used[j] == 0 && can_place(i + 1, j, N))
		{
			x_used[j] = 1;
			map[i + 1][j] = 1;
			N_Queen(i + 1, N);
			map[i + 1][j] = 0;
			x_used[j] = 0;
		}
	}
}

bool can_place(int x, int y, int N)
{
	int i, j;

	for (i = x-1; i >= 1; i--)
		if (map[i][y] == 1)
			return false;

	for (i = x-1, j = y-1; i >= 1 && j >= 1; i--, j--)
	{
		if (map[i][j] == 1)
			return false;
	}

	for (i = x-1, j = y+1; i >= 1 && j <= N; i--, j++)
	{
		if (map[i][j] == 1)
			return false;
	}

	return true;
}