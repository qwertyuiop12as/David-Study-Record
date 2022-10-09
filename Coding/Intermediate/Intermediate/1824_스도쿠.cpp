#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

int board[10][10];
int row[10][10];	// row[i][x] == 1 => i번 row에 x가 있다
int column[10][10];
int box[10][10];

bool done = false;

void DFS(int cnt);
void print();

int main()
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++) {
			scanf("%d", &board[i][j]);
			row[i][board[i][j]] = 1;
			column[j][board[i][j]] = 1;
			box[(i-1) / 3 * 3 + (j-1)/3 + 1][board[i][j]] = 1;
		}
	}

	DFS(0);

	return 0;
}


void DFS(int cnt)
{
	if (done == true)
		return;

	if (cnt == 81)
	{
		print();
		done = true;
		return;
	}

	cnt++;
	int x = (cnt - 1) / 9 + 1, y = (cnt-1) % 9 + 1;
	int box_num = (x - 1) / 3 * 3 + (y - 1) / 3 + 1;

	//printf("%d %d %d\n", x, y, box_num);

	if (board[x][y] != 0)
		DFS(cnt);

	else
	{
		for (int i = 1; i <= 9; i++)
		{
			if (row[x][i] == 0 && column[y][i] == 0 && box[box_num][i] == 0)
			{
				board[x][y] = i;
				row[x][i] = 1;
				column[y][i] = 1;
				box[box_num][i] = 1;
				DFS(cnt);
				row[x][i] = 0;
				column[y][i] = 0;
				box[box_num][i] = 0;
				board[x][y] = 0;
			}
		}
	}
}

void print()
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
			printf("%d ", board[i][j]);
		printf("\n");
	}
}