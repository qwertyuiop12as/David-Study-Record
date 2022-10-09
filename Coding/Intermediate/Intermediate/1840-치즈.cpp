#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int map[105][105], visited[105][105];
int num_check = 0, prev, time = 0;
int change_x[5] = { 1, 0, -1, 0 }, change_y[5] = {0, 1, 0, -1};
int V, H;
void DFS(int x, int y, int lv);
void reset();
void print();
int main()
{
	int i, j;
	scanf("%d%d", &V, &H);

	for (i = 0; i < V; i++)
	{
		for (j = 0; j < H; j++)
		{
			scanf("%d", &map[i][j]);
			num_check += map[i][j];
			if (map[i][j] == 1)
				map[i][j] = -1;
		}
	}

	while (num_check > 0)
	{
		prev = num_check;
		reset();
		for (i = 0; i < V; i++)
		{
			for (j = 0; j < H; j++)
			{
				if (map[i][j] == time)
				{
					DFS(i, j, time+1);
					time++;
					j = H;
					i = V;
				}
			}
		}
		/*printf("cur : %d\n", num_check);
		printf("------------------\n");
		print();
		printf("------------------\n");*/
	}

	printf("%d\n%d\n", time, prev);
}

void DFS(int x, int y, int lv)
{
	//printf("%d %d %d\n", x, y, lv);
	map[x][y] = -2;
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int new_x = x + change_x[i], new_y = y + change_y[i];
		if (new_x >= V || new_x < 0 || new_y >= H || new_y < 0 || visited[new_x][new_y] == 1)
			continue;

		if (map[new_x][new_y] == -1)
		{
			map[new_x][new_y] = lv;
			num_check--;
		}

		if (map[new_x][new_y] == time || map[new_x][new_y] == 0 || map[new_x][new_y] == -2)
		{
			DFS(new_x, new_y, lv);
		}
		
	}
}

void print()
{
	int i, j;
	for (i = 0; i < V; i++)
	{
		for (j = 0; j < H; j++)
		{
			printf("%2d ", map[i][j]);
		}
		printf("\n");
	}
}

void reset()
{
	int i, j;
	for (i = 0; i < V; i++)
	{
		for (j = 0; j < H; j++)
		{
			visited[i][j] = 0;
		}
	}
}