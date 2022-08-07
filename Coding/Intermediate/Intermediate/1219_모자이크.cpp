#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

int errors[1000003];
int err[1003], err_idx = -1;

int H, W, N, M;
int max_height = 0, max_width = 0, min_width = 1000003;

int find_size(int low, int high);
bool is_filled(int size);

int main()
{
	scanf("%d%d%d%d", &H, &W, &N, &M);

	int x, y, i;
	for (i = 1; i <= M; i++)
	{
		scanf("%d%d", &x, &y);

		max_height = max(max_height, x);
		max_width = max(max_width, y);
		min_width = min(min_width, y);

		errors[y] = 1;
	}

	for (i = min_width; i <= max_width; i++)
		if (errors[i])
			err[++err_idx] = i;

	int larger = max(max_height, (max_width - min_width + 1));
	int res = find_size(max_height, larger);

	printf("%d", res);
	//printf("\n%d %d %d", is_filled(1), is_filled(2), is_filled(3));
}

bool is_filled(int size)
{
	int cnt = 1, cur_st = 0;
	
	for (int i = 0; i <= err_idx; i++)
	{
		if (err[i] - err[cur_st] >= size)
		{
			cnt++;
			cur_st = i;
		}

		if (cnt > N)
			return false;
	}

	return true;
}

int find_size(int low, int high)
{
	int mid = (low + high) / 2;
	//printf("l : %d, h : %d m : %d\n", low, high, mid);

	if (low >= high) {
		//printf("%d returned!\n", mid);
		return mid;
	}

	if (is_filled(mid))
		return find_size(low, mid);

	if (!is_filled(mid))
		return find_size(mid + 1, high);
}