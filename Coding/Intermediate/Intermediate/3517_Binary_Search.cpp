#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[500003];

int binary_search(int start, int end, int key);

int main()
{
	int N, Q, i, num;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	scanf("%d", &Q);
	for (i = 1; i <= Q; i++)
	{
		scanf("%d", &num);
		printf("%d ", binary_search(0, N - 1, num));
	}
}

int binary_search(int start, int end, int key)
{
	int mid = (start + end) / 2;

	if (start > end)
		return -1;

	if (arr[mid] == key)
		return mid;

	if (arr[mid] > key)
		return binary_search(start, mid - 1, key);

	if (arr[mid] < key)
		return binary_search(mid + 1, end, key);
}