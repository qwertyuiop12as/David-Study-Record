#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> better_arr, worse_arr;
vector<int> visited;

int cnt;
void find_better(int cur);
void find_worse(int cur);
void reset();

int main()
{
	int N, M, x, in1, in2, i;
	scanf("%d%d%d", &N, &M, &x);

	better_arr.resize(N); worse_arr.resize(N);
	visited.resize(N);

	for (i = 0; i < M; i++)
	{
		scanf("%d%d", &in1, &in2);
		in1--;	in2--;
		better_arr[in1].push_back(in2);
		worse_arr[in2].push_back(in1);
	}


	reset();
	find_better(x-1);
	int higher_bound = cnt;
	reset();
	find_worse(x - 1);
	int lower_bound = N-cnt+1;


	printf("%d %d", higher_bound, lower_bound);
}

void find_better(int cur)
{
	if (visited[cur] == 1)
		return;

	visited[cur] = 1;
	cnt++;

	for (int i = 0; i < worse_arr[cur].size(); i++)
		find_better(worse_arr[cur][i]);

	return;
}

void find_worse(int cur)
{
	if (visited[cur] == 1)
		return;

	visited[cur] = 1;
	cnt++;

	for (int i = 0; i < better_arr[cur].size(); i++)
		find_worse(better_arr[cur][i]);

	return;
}

void reset()
{
	for (int i = 0; i < visited.size(); i++)
		visited[i] = 0;
	cnt = 0;
	return;
}