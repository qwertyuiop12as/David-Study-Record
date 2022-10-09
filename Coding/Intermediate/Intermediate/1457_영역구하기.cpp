#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

int M, N, K;
int cur, cnt = 0, arr[10000];
int map[103][103];
int change[3] = { -1, 0, 1 };

void DFS(int x, int y);

int main()
{
	int i, j, x1, y1, x2, y2;
	scanf("%d%d%d", &M, &N, &K);
	for (i = 1; i <= K; i++)
	{
		scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
		for (int x = x1; x < x2; x++)
		{
			for (int y = y1; y < y2; y++)
				map[x][y] = 1;
		}
	}

	for (int x = 0; x < M; x++)
	{
		for (int y = 0; y < N; y++)
			if (map[x][y] == 0)
			{
				cur = 1;
				DFS(x, y);
				arr[cnt] = cur;
				cnt++;
			}
	}

	sort(arr, arr + cnt);
	printf("%d\n", cnt);
	for (i = 0; i < cnt; i++)
		printf("%d ", arr[i]);
}

void DFS(int x, int y)
{
	// printf("cnt : %d / (%d, %d, %d)\n", cnt, x, y, cur);
	map[x][y] = 1;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (change[i] == 0 && change[j] == 0)
				continue;
			if (change[i] != 0 && change[j] != 0)
				continue;

			int new_x = x + change[i], new_y = y + change[j];

			if (map[new_x][new_y] == 1 || new_x < 0 || new_x >= M || new_y < 0 || new_y >= N)
				continue;

			cur++;
			DFS(new_x, new_y);
		}

	return;
}