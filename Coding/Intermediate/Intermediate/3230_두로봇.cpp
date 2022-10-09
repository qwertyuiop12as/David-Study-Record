#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, x, y, res = -1;
vector<vector<pair<int, int>>> arr;
vector<int> cost_map, visited;

void DFS(int cur, int robot, int cost);

int p1, p2;
int main()
{
	int i, cost;
	scanf("%d%d%d", &N, &x, &y);
	x--;	y--;

	arr.resize(N);
	cost_map.resize(N, -1);
	visited.resize(N, 0);

	for (i = 1; i < N; i++)
	{
		scanf("%d%d%d", &p1, &p2, &cost);
		p1--;	p2--;
		arr[p1].push_back(make_pair(p2, cost));
		arr[p2].push_back(make_pair(p1, cost));
	}

	DFS(x, 1, 0);
	for (i = 0; i < N; i++)
		printf("%d : %d\n", i+1, cost_map[i]);

	for (int &element : visited)
		element = 0;

	DFS(y, 2, 0);

	printf("%d\n", res);
	return 0;
}

void DFS(int cur, int robot, int cost)
{
	if (robot == 1)
	{
		if (visited[cur] == 1 || cur == y)
			return;

		visited[cur] = 1;

		cost_map[cur] = cost;

		for (int i = 0; i < arr[cur].size(); i++)
			DFS(arr[cur][i].first, robot, cost + arr[cur][i].second);
	}

	if (robot == 2)
	{
		visited[cur] = 1;

		for (int i = 0; i < arr[cur].size(); i++)
		{
			if (visited[arr[cur][i].first] == 0)
			{
				if (res == -1 || res > cost + cost_map[arr[cur][i].first])
					res = cost + cost_map[arr[cur][i].first];

				DFS(arr[cur][i].first, robot, cost + arr[cur][i].second);
			}
		}
	}
}