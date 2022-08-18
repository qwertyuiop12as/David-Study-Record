#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int map[60][60];
long long int cur, ma = 0;
int N, M;

long long int check_ten(int x, int y);
long long int check_x(int x, int y);

int main()
{
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &map[i][j]);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			ma = max(ma, check_ten(i, j));
			ma = max(ma, check_x(i, j));

			//if (check_ten(i, j) == 16)
				//printf("%d %d\n", i, j);
		}

	printf("%lld\n", ma);
}

long long int check_ten(int x, int y)
{
	long long int sum = 0;

	int start_x = max(1, x - M), start_y = max(1, y - M), end_x = min(N, x+M), end_y = min(N, y+M);

	for (int i = start_x; i <= end_x; i++)
		sum += map[i][y];

	for (int i = start_y; i <= end_y; i++)
		sum += map[x][i];

	return sum - map[x][y];
}

long long int check_x(int x, int y)
{
	long long int sum = 0;

	int start_x = max(1, x - M), start_y = max(1, y - M), end_x = min(N, x + M), end_y = min(N, y + M);

	for (int i = start_x, j = start_y; i <= end_x && j <= end_y; i++, j++)
		sum += map[i][j];

	/*if (x == 2 && y == 2)
	{
		printf("sum1 : %lld\n", sum);
	}*/

	int tmp = start_x;
	start_x = end_x;
	end_x = tmp;

	for (int i = start_x, j = start_y; i >= end_x && j <= end_y; i--, j++)
		sum += map[i][j];

	/*if (x == 2 && y == 2)
	{
		printf("sum2 : %lld\n", sum);
	}*/

	return sum - map[x][y];

	return sum;
}