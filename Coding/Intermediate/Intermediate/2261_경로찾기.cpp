#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

char map[1005][50];
int visited[1005], parent[1005];
int start, en;
bool is_finished = false;

vector<vector<int>> haming;
queue<int> que;

bool comp(int, int);
void BFS();
void DFS(int);

int N, K;
int main()
{
	int i, j;
	scanf("%d%d", &N, &K);

	haming.resize(N);

	for (i = 0; i < N; i++)
	{
		scanf("%s", map[i]);
		for (j = i - 1; j >= 0; j--)
		{
			if (comp(i, j) == true)
			{
				haming[i].push_back(j);
				haming[j].push_back(i);
			}
		}
	}

	scanf("%d%d", &start, &en);
	start--;	en--;
	/*for (i = 0; i < N; i++)
	{
		printf("%d : ", i + 1);
		for (j = 0; j < haming[i].size(); j++)
			printf("%d, ", haming[i][j] + 1);
		printf("\n");
	}*/

	parent[start] = -1;
	visited[start] = 1;
	que.push(start);
	BFS();

	if (is_finished == true)
		DFS(en);
	else
		printf("-1");

	return 0;
}

void BFS()
{
	while (!que.empty())
	{
		int cur = que.front();
		for (int i = 0; i < haming[cur].size(); i++)
		{
			if (visited[haming[cur][i]] == 1)
				continue;

			visited[haming[cur][i]] = 1;
			parent[haming[cur][i]] = cur;
			que.push(haming[cur][i]);

			if (haming[cur][i] == en)
			{
				is_finished = true;
				return;
			}
		}
		que.pop();
	}

	return;
}

bool comp(int a, int b)
{
	int cnt = 0;
	for (int idx = 0; idx < K; idx++)
	{
		if (map[a][idx] != map[b][idx])
			cnt++;
		if (cnt >= 2)
			return false;
	}

	return true;
}

void DFS(int cur)
{
	if (cur == start)
	{
		printf("%d ", cur+1);
		return;
	}

	DFS(parent[cur]);
	printf("%d ", cur+1);
}