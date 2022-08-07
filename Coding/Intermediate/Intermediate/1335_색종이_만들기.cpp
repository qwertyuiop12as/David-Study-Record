#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned int map[130][130];
int count[3];

void cut(int x, int y, int size);
bool check(int x, int y, int size);

int main()
{
	int N, i, j;
	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
			scanf("%u", &map[i][j]);
	}
	cut(1, 1, N);
	printf("%d\n%d", count[0], count[1]);
}

bool check(int x, int y, int size)
{
	int key = map[x][y], i, j;
	for (i = x; i < x + size; i++)
	{
		for (j = y; j < y + size; j++)
			if (key != map[i][j])
				return false;
	}

	return true;
}

void cut(int x, int y, int size)
{
	if (check(x, y, size)) {
		//printf("%d %d %d (%d)\n", x, y, size, map[x][y]);
		//printf("returned!\n");
		count[map[x][y]]++;
		return;
	}

	int x_mid = (x + x + size) / 2, y_mid = (y + y + size) / 2;
	size /= 2;

	cut(x, y, size);
	cut(x, y_mid, size);
	cut(x_mid, y, size);
	cut(x_mid, y_mid, size);
}

