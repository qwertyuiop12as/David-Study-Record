#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void MergeSort(int A[], int start, int end);
int N, arr[1003], tmp[1003];

int main()
{
	int i;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	MergeSort(arr, 0, N - 1);
}

void MergeSort(int A[], int start, int end)
{
	if (start >= end)
		return;

	int mid = (start + end) / 2;

	MergeSort(A, start, mid);
	MergeSort(A, mid+1, end);

	int idx_lower = start, idx_higher = mid + 1, idx = start;
	while (idx_lower <= mid || idx_higher <= end)
	{
		if (idx_lower > mid)
			tmp[idx++] = A[idx_higher++];
		else if (idx_higher > end)
			tmp[idx++] = A[idx_lower++];
		else if (A[idx_lower] < A[idx_higher])
			tmp[idx++] = A[idx_lower++];
		else
			tmp[idx++] = A[idx_higher++];
	}

	for (int i = start; i <= end; i++)
		A[i] = tmp[i];

	for (int i = 0; i < N; i++)
		printf("%d ", A[i]);

	printf("\n");

	return;
}