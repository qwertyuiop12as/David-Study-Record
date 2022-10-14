#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, left, res = 0;
int box[1003][1003], visited[1003][1003];
int change_x[4] = { 0, 1, 0, -1 }, change_y[4] = { 1, 0, -1, 0 };

struct grid {
	int x, y, t;
};
queue<grid> que;

void BFS();

int main()
{
	int i, j;
	scanf("%d%d", &N, &M);
	for (i = 1; i <= M; i++)
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1)
			{
				que.push({ i, j, 0 });
				visited[i][j] = 1;
			}
			if (box[i][j] == 0)
				left++;
		}

	BFS();

	if (left > 0)
		printf("-1\n");
	else
		printf("%d\n", res);

	return 0;
}

void BFS()
{
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

			if (new_x < 1 || new_x > M || new_y < 1 || new_y > N || visited[new_x][new_y] == 1 || box[new_x][new_y] != 0)
				continue;

			visited[new_x][new_y] = 1;
			res = new_t;
			left--;
			que.push({ new_x, new_y, new_t });
		}

		que.pop();
	}
}