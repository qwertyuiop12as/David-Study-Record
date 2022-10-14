#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

char map[53][53];
int R, C;

int main()
{
	int i, j;
	scanf("%d%d", &R, &C);

	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++)
			scanf("%c", &map[i][j]);


}