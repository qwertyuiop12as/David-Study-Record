#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int map[60][60];
long long int sum_v[60][60], sum_h[60][60], sum_x_lu[60][60], sum_x_ru[60][60];
long long int cur, ma = 0;
int N, M;

long long int check_ten(int x, int y);
long long int check_x(int x, int y);

int main()
{
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
			sum_v[i][j] = sum_v[i - 1][j] + map[i][j];
			sum_h[i][j] = sum_h[i][j - 1] + map[i][j];
			sum_x_lu[i][j] = sum_x_lu[i - 1][j - 1] + map[i][j];
			sum_x_ru[i][j] = sum_x_ru[i - 1][j + 1] + map[i][j];
		}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			ma = max(ma, check_ten(i, j));
			ma = max(ma, check_x(i, j));

			//printf("check_x(%d, %d) : %d\n", i, j, check_x(i, j));
			/*if (check_x(i, j) == 11)
				printf("%d %d\n", i, j);*/
		}

	/*printf("\n");
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++) {
			printf("%lld ", sum_x_lu[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++) {
			printf("%lld ", sum_x_ru[i][j]);
		}
		printf("\n");
	}*/

	/*printf("\n");
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++) {
			printf("%3lld ", sum_v[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++) {
			printf("%3lld ", sum_h[i][j]);
		}
		printf("\n");
	}*/

	//printf("%lld\n", check_ten(3, 4));

	printf("%lld", ma);
	
	
}

long long int check_ten(int x, int y)
{
	long long int sum = 0;

	int start_x = max(0, x - M - 1), start_y = max(0, y - M - 1), end_x = min(N, x + M), end_y = min(N, y + M);

	sum += sum_v[end_x][y] - sum_v[start_x][y];
	sum += sum_h[x][end_y] - sum_h[x][start_y];

	return sum - map[x][y];
}

long long int check_x(int x, int y)
{
	long long int sum = 0;

	int start_x, start_y, end_x, end_y;
	int gap_x, gap_y, len;

	// ----- lu ----
	// bottom
	gap_x = N - x;
	gap_y = N - y;
	len = min(gap_x, gap_y);
	len = min(len, M);

	end_x = x + len;
	end_y = y + len;

	// top
	gap_x = x - 1;
	gap_y = y - 1;
	len = min(gap_x, gap_y);
	len = min(len, M);

	start_x = x - len;
	start_y = y - len;

	sum += sum_x_lu[end_x][end_y] - sum_x_lu[start_x-1][start_y-1];


	// ----- ru ----
	// bottom
	gap_x = N-x;
	gap_y = y-1;
	len = min(gap_x, gap_y);
	len = min(len, M);

	end_x = x + len;
	end_y = y - len;

	// top
	gap_x = x-1;
	gap_y = N-y;
	len = min(gap_x, gap_y);
	len = min(len, M);

	start_x = x - len;
	start_y = y + len;

	sum += sum_x_ru[end_x][end_y] - sum_x_ru[start_x - 1][start_y + 1];
	return sum - map[x][y];
}