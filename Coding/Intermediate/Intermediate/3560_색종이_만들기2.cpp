#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

unsigned int map[1030][1030];
void cut(int x, int y, int size);
bool check(int x, int y, int size);

int main()
{
	int N, i, j;
	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			scanf("%u", &map[i][j]);

	cut(1, 1, N);
}

bool check(int x, int y, int size)
{
	int key = map[x][y], i, j;

	for (i = x; i < x + size; i++)
		for (j = y; j < y + size; j++)
			if (key != map[i][j])
				return false;

	return true;
}

void cut(int x, int y, int size)
{
	if (check(x, y, size))
	{
		printf("%d", map[x][y]);
		//printf("%d %d ", x, y);
		//printf("(%d) / %d\n", map[x][y], size);
		return;
	}

	printf("X");

	int x_mid = (x + x + size) / 2, y_mid = (y + y + size) / 2;
	size /= 2;

	cut(x, y, size);
	cut(x, y_mid, size);
	cut(x_mid, y, size);
	cut(x_mid, y_mid, size);
}