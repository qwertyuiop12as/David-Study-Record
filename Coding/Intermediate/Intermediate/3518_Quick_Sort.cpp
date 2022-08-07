#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;

void q_sort(int arr[], int start, int end);

int main()
{
	int i;
	int arr[1003];
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	q_sort(arr, 0, N-1);
}

void swap(int idx1, int idx2, int arr[])
{
	int tmp;
	tmp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = tmp;

	return;
}

void q_sort(int arr[], int start, int end)
{
	//printf("st : %d, en : %d\n", start, end);

	if (start >= end)
		return;

	int pivot = arr[end];
	int lower_idx = start-1, i;

	for (i = start; i < end; i++)
	{
		if (arr[i] < pivot)
			swap(++lower_idx, i, arr);
	}

	swap(++lower_idx, end, arr);

	for (i = 0; i < N; i++)
		printf("%d ", arr[i]);

	printf("\n");

	q_sort(arr, start, lower_idx-1);
	q_sort(arr, lower_idx+1, end);

	return;
}