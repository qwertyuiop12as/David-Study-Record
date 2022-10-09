#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 999999999

int order[25], M;
int res = MAX;

void DFS(int door1, int door2, int cnt, int idx); // num은 몇개 했냐

int main()
{
	int N, door1, door2;
	scanf("%d%d%d%d", &N, &door1, &door2, &M);

	for (int i = 0; i < M; i++)
	{
		scanf("%d", &order[i]);
	}

	DFS(door1, door2, 0, 0);

	printf("%d", res);
	return 0;
}

void DFS(int door1, int door2, int cnt, int idx)
{
	if (idx == M)
	{
		res = min(res, cnt);
		return;
	}

	DFS(order[idx], door2, cnt + abs(order[idx] - door1), idx + 1);
	DFS(door1, order[idx], cnt + abs(order[idx] - door2), idx + 1);
}