#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, cnt, ans = 0;
vector<vector<int>> arr_up, arr_down;
vector<int> cnt_up, cnt_down, visited_up, visited_down;

void DFS_down(int cur);
void DFS_up(int cur);
void reset();

int main()
{
	int x, y, i, j;
	scanf("%d%d", &N, &M);
	arr_up.resize(N); arr_down.resize(N);
	visited_up.resize(N, 0); visited_down.resize(N, 0);

	for (i = 0; i < M; i++)
	{
		scanf("%d%d", &x, &y);
		arr_down[x - 1].push_back(y - 1);
		arr_up[y - 1].push_back(x - 1);
	}

	for (i = 0; i < N; i++)
	{
		reset();
		DFS_down(i); DFS_up(i);
		//printf("%d : %d\n", i, cnt);
		if (cnt == N - 1)
			ans++;
	}

	printf("%d\n", ans);
	//for (i = 0; i < N; i++)
	//	printf("%d : %d\n", i, cnt_down[i]);

	return 0;
}

void DFS_down(int cur)
{
	if (visited_down[cur] == 1)
		return;

	visited_down[cur] = 1;
	cnt++;

	//printf("%d(%d)\n", cur, arr_down[cur].size());

	for (int i = 0; i < arr_down[cur].size(); i++)
		DFS_down(arr_down[cur][i]);

	return;
}

void DFS_up(int cur)
{
	if (visited_up[cur] == 1)
		return;

	visited_up[cur] = 1;
	cnt++;

	//printf("%d(%d)\n", cur, arr_down[cur].size());

	for (int i = 0; i < arr_up[cur].size(); i++)
		DFS_up(arr_up[cur][i]);

	return;
}

void reset()
{
	cnt = -2;
	for (int i = 0; i < N; i++)
	{
		visited_up[i] = 0;
		visited_down[i] = 0;
	}
	return;
}