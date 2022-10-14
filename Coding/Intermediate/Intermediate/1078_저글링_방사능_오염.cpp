#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int map[103][103], visited[103][103];
char input[103];
int left = 0, res_time = 3;
int change_x[4] = { 0, 1, 0, -1 }, change_y[4] = { 1, 0, -1, 0 };

struct jug {
	int x, y, t;
};

queue<jug> que;

void BFS(int W, int H, int x, int y);

int main()
{
	int	W, H, x, y;
	int i, j;
	scanf("%d%d", &W, &H);

	for (i = 1; i <= H; i++)
	{
		scanf("%s", input);
		// printf("%d\n", strlen(input));
		for (j = 0; j < strlen(input); j++)
		{
			//printf("%c\n", input[j]);
			if (input[j] == '1')
				left++;
			map[i][j+1] = input[j] - '0';
		}
	}

	scanf("%d%d", &x, &y);

	BFS(W, H, x, y);
	//printf("%d\n", left);

	printf("%d\n%d\n", res_time, left);
	return 0;
}


void BFS(int W, int H, int x, int y)
{
	que.push({ y, x, 3 });
	visited[y][x] = 1;
	left--;

	while (!que.empty())
	{
		int cur_x = que.front().x, cur_y = que.front().y, cur_t = que.front().t;
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int new_x = cur_x + change_x[i];
			int new_y = cur_y + change_y[i];
			int new_t = cur_t + 1;

			if (new_x < 1 || new_x > H || new_y < 1 || new_y > W || map[new_x][new_y] == 0 || visited[new_x][new_y] == 1)
				continue;

			visited[new_x][new_y] = 1;
			res_time = new_t;

			//printf("(%d, %d) pushed!\n", new_x, new_y);
			que.push({ new_x, new_y, new_t });
			left--;
		}
	}
}