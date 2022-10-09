#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> door;
vector<int> visited;

int N, M;

void DFS(int x);

int main()
{
	scanf("%d%d", &N, &M);
	door.resize(N);
	visited.resize(N, 0);

	for (int i = 0; i < M; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--; y--;
		door[x].push_back(y);
		door[y].push_back(x);
	}

	for (int i = 0; i < N; i++)
		sort(door[i].begin(), door[i].end());

	/*for (int i = 0; i < N; i++)
	{
		printf("%d : ", i);
		for (int j = 0; j < door[i].size(); j++)
			printf("%d ", door[i][j]);
		printf("\n");
	}*/

	DFS(0);

	return 0;
}


void DFS(int x)
{

	visited[x] = 1;
	printf("%d ", x + 1);

	if (x == N)
		return;

	for (int i = 0; i < door[x].size(); i++)
	{
		if (visited[door[x][i]] == 1)
			continue;
		DFS(door[x][i]);
	}

	return;
}