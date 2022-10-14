#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, x, y, res = -1;
bool done = false;
vector<vector<pair<int, int>>> arr;
vector<int> cost_map, visited;

void DFS(int cur, int cost, int max_path);

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

	if (x == y)
	{
		printf("0");
		return 0;
	}

	for (int &element : visited)
		element = 0;

	DFS(x, 0, 0);

	printf("%d\n", res);
	return 0;
}

void DFS(int cur, int cost, int max_path)
{
	if (visited[cur] == 1 || done == true)
		return;

	visited[cur] = 1;

	if (cur == y)
	{
		done = true;
		res = cost - max_path;
		//printf("max_path : %d\n", max_path);
	}

	cost_map[cur] = cost;

	for (int i = 0; i < arr[cur].size(); i++)
	{
		DFS(arr[cur][i].first, cost + arr[cur][i].second, max(max_path, arr[cur][i].second));
	}
}