#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, cnt, res = -1;
int cost[20][30];
bool visited[20];

void DFS(int idx, int sum);

int main()
{
	int i, j;
	scanf("%d", &N);
	
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
			scanf("%d", &cost[i][j]);
		visited[i] = false;
	}

	cnt = 1;
	visited[1] = true;
	DFS(1, 0);

	printf("%d", res);

	return 0;
}

void DFS(int idx, int sum)
{
	if (res != -1 && res <= sum)
		return;

	if (cnt == N)
	{
		if (cost[idx][1] == 0)
			return;

		sum += cost[idx][1];
		if (res == -1 || sum < res)
			res = sum;
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (i == idx || visited[i] == true || cost[idx][i] == 0)
			continue;

		visited[i] = true;
		cnt++;
		DFS(i, sum + cost[idx][i]);
		visited[i] = false;
		cnt--;
	}
}