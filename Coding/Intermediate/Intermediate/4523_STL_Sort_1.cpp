#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[100003];

int main()
{
	int N, i, start, end;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	scanf("%d%d", &start, &end);

	sort(arr + start, arr + end + 1);

	for (i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");


	sort(arr + 0, arr + N);

	for (i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}