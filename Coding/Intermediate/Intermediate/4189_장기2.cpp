#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int R, C, S, K;
int board[1003][1003];
int change_x[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }, change_y[8] = {2, 1, -1, -2, -2, -1, 1, 2};

struct piece {
	int x, y, time;
};

queue<piece> que;

int BFS();

int main()
{
	scanf("%d%d", &N, &M);
	scanf("%d%d%d%d", &R, &C, &S, &K);

	printf("%d\n", BFS());
}

int BFS()
{
	que.push({ R, C, 0 });
	board[R][C] = 1;

	while (true)
	{
		int cur_x = que.front().x, cur_y = que.front().y, cur_t = que.front().time;
		que.pop();
		for (int i = 0; i < 8; i++)
		{
			int new_x = cur_x + change_x[i];
			int new_y = cur_y + change_y[i];
			int new_t = cur_t + 1;

			if (new_x < 1 || new_x > N || new_y < 1 || new_y > M || board[new_x][new_y] == 1)
				continue;

			if (new_x == S && new_y == K)
				return new_t;

			board[new_x][new_y] = 1;

			que.push({ new_x, new_y, new_t });
		}
	}

	return -1;
}