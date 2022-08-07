#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[303];

int find_min(int low, int high);
bool is_possible(int num);

int N, M;

int main()
{
	int i, sum = 0, max_num = 0;
	scanf("%d%d", &N, &M);

	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
		max_num = max(max_num, arr[i]);
	}

	//printf("%d %d\n", max(max_num, sum / M), sum - M + 1);

	//printf("16 : %d\n17 : %d\n18 : %d\n19 : %d\n", is_possible(16), is_possible(17), is_possible(18), is_possible(19));
	printf("%d", find_min(max(max_num, sum / M), sum - M + 1));
}

bool is_possible(int num)
{
	int cnt = 1, i, cur_sum = 0;
	for (i = 0; i < N; i++)
	{
		if (cur_sum + arr[i] > num)
		{
			if (cnt >= M)
				return false;

			cur_sum = arr[i];
			cnt++;
		}

		else
			cur_sum += arr[i];
	}

	return true;
}

int find_min(int low, int high)
{
	int mid = (low + high) / 2;

	if (low >= high)
		return mid;

	if (is_possible(mid))
		return find_min(low, mid);

	if (!is_possible(mid))
		return find_min(mid + 1, high);
}