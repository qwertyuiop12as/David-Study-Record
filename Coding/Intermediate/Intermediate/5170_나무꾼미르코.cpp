#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[1000003];

unsigned long long calc(int height, int N);
int find_height(int start, int end, int N, int M);

int main()
{
	int N, M, i, ma = 0;
	scanf("%d%d", &N, &M);

	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		ma = max(ma, arr[i]);
	}

	printf("%d", find_height(0, ma - 1, N, M));
}

int find_height(int start, int end, int N, int M)
{
	int mid = (start + end + 1) / 2;

	if (start >= end)
		return mid;

	if (calc(mid, N) == M)
		return mid;

	if (calc(mid, N) < M)
		return find_height(start, mid - 1, N, M);

	if (calc(mid, N) > M)
		return find_height(mid, end, N, M);
}

unsigned long long calc(int height, int N)
{
	int i;
	unsigned long long sum = 0;

	for (i = 0; i < N; i++)
		if (arr[i] > height)
			sum += arr[i] - height;

	return sum;
}