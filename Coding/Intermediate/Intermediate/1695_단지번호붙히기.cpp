#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

char input[30];
int N, map[30][30];
int change[3] = { -1, 0, 1 };
int cnt = 0, arr[1000], cur;
void DFS(int x, int y);

int main()
{
	int i, j;
	scanf("%d", &N);
	
	for (i = 0; i < N; i++)
	{
		scanf("%s", input);
		for (j = 0; j < N; j++)
			map[i][j] = input[j] - '0';
	}

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			if (map[i][j] == 1)
			{
				cur = 1;
				DFS(i, j);
				arr[cnt] = cur;
				cnt++;
				//printf("\n------------------------\n");
			}
		}

	sort(arr, arr + cnt);
	printf("%d\n", cnt);
	for (i = 0; i < cnt; i++)
		printf("%d\n", arr[i]);
}

void DFS(int x, int y)
{
	map[x][y] = 0;
	//printf("x : %d, y : %d\n", x, y);
	int i, j, sum = 0;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			if (change[i] != 0 && change[j] != 0)
				continue;
			if (change[i] == 0 && change[j] == 0)
				continue;

			int new_x = x + change[i], new_y = y+change[j];

			if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= N)
				continue;

			if (map[new_x][new_y] == 1) {
				cur++;
				DFS(new_x, new_y);
			}
		}

	return;
}