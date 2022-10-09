#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

int board[15][15];
int diagonal[50];
int res_arr[3] = {-1, -1, -1};
void DFS(int diagonal_num, int cnt, int type); // type = black(1), type = white(2)
int N;
int max_diagonal = 0;

int main()
{
	int i, j; 
	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}

	DFS(1, 0, 1);
	DFS(2, 0, 2);

	//printf("%d %d\n", res_arr[1], res_arr[2]);
	//printf("max : %d\n", max_diagonal);
	printf("%d", res_arr[1] + res_arr[2]);
	return 0;
}

void DFS(int diagonal_num, int cnt, int type)
{
	if (diagonal_num >= 2 * N)
	{

		if (res_arr[type] == -1 || res_arr[type] < cnt)
			res_arr[type] = cnt;

		return;
	}

	int x;
	for (x = 1; x <= diagonal_num; x++)
	{
		int y = diagonal_num - x + 1;

		max_diagonal = max(N + x - y, max_diagonal);

		if (diagonal[N + x - y] == 0 && board[x][y] == 1)
		{
			diagonal[N + x - y] = 1;
			DFS(diagonal_num + 2, cnt+1, type);
			diagonal[N + x - y] = 0;
		}
	}

	DFS(diagonal_num + 2, cnt, type);

	return;
}