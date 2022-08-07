#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;

int map[103][103]; // (0,0)บฮลอ
int N, x, y, i, j, k;
int min_x = 101, max_x = 0, max_y = 0, min_y = 101;
long long int big = 0;

stack<pair<int, int>> st;

void inputMap();
void setMap();
void findMax(int);

int main()
{
	scanf("%d", &N);

	inputMap();

	setMap();

	for (i = min_y; i <= max_y; i++)
	{
		findMax(i);
	}

	//for (i = 0; i < 30; i++) {
	//	for (j = 0; j < 30; j++)
	//		printf("%3d ", map[i][j]);
	//	printf("\n\n");
	//}

	//printf("min_x : %d\nmax_x : %d\nmin_y : %d\nmax_y : %d\n", min_x, max_x, min_y, max_y);
	printf("%lld\n", big);
	return 0;
}

void push(int height, int position)
{
	int idx = position;
	while (!st.empty() && st.top().first > height)
	{
		idx = st.top().second;
		big = max(big, (long long)(position - idx) * st.top().first);
		st.pop();
	}

	st.push(make_pair(height, idx));

	return;
}

void findMax(int line)
{

	for (int j = min_x; j <= max_x+1; j++)
		push(map[line][j], j);

	return;
}

void inputMap()
{
	int i, j, k;
	for (i = 0; i < N; i++)
	{
		scanf("%d%d", &x, &y);
		min_x = min(x, min_x);
		min_y = min(y, min_y);
		max_x = max(x + 9, max_x);
		max_y = max(y + 9, max_y);

		for (j = x; j < x + 10; j++)
			for (k = y; k < y + 10; k++) {
				map[k][j] = 1;
			}
	}

	return;
}

void setMap()
{
	int i, j;
	for (i = 1; i <= 100; i++)
		for (j = 1; j <= 100; j++)
			if (map[i][j] == 1)
				map[i][j] = map[i - 1][j] + 1;

	return;
}