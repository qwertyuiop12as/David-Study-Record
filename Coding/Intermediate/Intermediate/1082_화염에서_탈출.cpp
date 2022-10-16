#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct point {
	int x, y, t;
};

point start, finish;
queue<point> que;

char map[53][53];
int visited[53][53];
int R, C;
int change_x[4] = { 1, -1, 0, 0 }, change_y[4] = { 0, 0, -1, 1 };

int BFS();

int main()
{
	int i, j;
	char in[100];
	scanf("%d%d", &R, &C);

	for (i = 0; i < R; i++)
	{
		scanf("%s", &in);
		for (j = 0; j < C; j++) {
			map[i][j] = in[j];
			switch (map[i][j]) {
			case '*':
				que.push({ i, j, 0 });
				visited[i][j] = 1;
				break;
			case 'D':
				finish = { i, j, 0 };
				break;
			case 'S':
				start = { i, j, 0 };
				visited[i][j] = 1;
				break;
			}

		}
	}

	que.push(start);

	int result = BFS();
	if (result == -1)
		printf("impossible\n");
	else
		printf("%d\n", result);
	return 0;
}

int BFS()
{
	while (!que.empty())
	{
		int cur_x = que.front().x, cur_y = que.front().y, cur_t = que.front().t;
		char cur_element = map[cur_x][cur_y];

		//printf("%c visiting (%d, %d, %d)\n", cur_element, cur_x, cur_y, cur_t);

		for (int i = 0; i < 4; i++)
		{
			int new_x = cur_x + change_x[i];
			int new_y = cur_y + change_y[i];
			int new_t = cur_t + 1;

			if (new_x < 0 || new_x >= R || new_y < 0 || new_y >= C || visited[new_x][new_y] == 1 || map[new_x][new_y] == '*' || map[new_x][new_y] == 'X')
				continue;

			if (cur_element == 'S')
			{
				if (new_x == finish.x && new_y == finish.y)
					return new_t;
				map[new_x][new_y] = 'S';
			}

			if (map[new_x][new_y] == 'D')
				continue;

			if (cur_element == '*')
				map[new_x][new_y] = '*';


			visited[new_x][new_y] = 1;
			que.push({ new_x, new_y, new_t });
		}

		que.pop();
	}
	return -1;
}