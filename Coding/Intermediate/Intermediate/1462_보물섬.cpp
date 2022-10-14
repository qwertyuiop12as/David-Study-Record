#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

char map[55][55], visited[55][55];
char input[55];
int N, M;
int change_x[4] = { 0, 1, 0, -1 }, change_y[4] = {1, 0, -1, 0};
int tmp_max, final_max = 0;

struct spot {
	int x, y, t;
};
queue<spot> que;

void reset();
void BFS(int start_x, int start_y);

int main()
{
	int i, j;
	scanf("%d%d", &N, &M);

	for (i = 0; i < N; i++)
		scanf("%s", map[i]);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (map[i][j] == 'W')
				continue;

			reset();
			BFS(i, j);

			final_max = max(final_max, tmp_max);
		}
	}

	printf("%d", final_max);
	return 0;
}

void BFS(int start_x, int start_y)
{
	que.push({start_x, start_y, 0});
	visited[start_x][start_y] = 1;

	while (!que.empty())
	{
		int cur_x = que.front().x;
		int cur_y = que.front().y;
		int cur_t = que.front().t;

		for (int i = 0; i < 4; i++)
		{
			int new_x = cur_x + change_x[i];
			int new_y = cur_y + change_y[i];
			int new_t = cur_t + 1;

			if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= M || visited[new_x][new_y] == 1 || map[new_x][new_y] == 'W')
				continue;

			que.push({ new_x, new_y, new_t });
			visited[new_x][new_y] = 1;
			tmp_max = new_t;
		}

		que.pop();
	}
}
void reset()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visited[i][j] = 0;

	tmp_max = 0;
}